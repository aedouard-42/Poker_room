

#include "Game.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Game::Game(int numPlayers) : dealerPosition(0), smallBlind(5), bigBlind(10)
{
	if (numPlayers < 2 || numPlayers > 9) {
        throw std::invalid_argument("Invalid number of players. Must be between 2 and 9.");
    }

	deck = Deck();
    deck.randomize();
    for (int i = 0; i < numPlayers; i++) {
        Player newPlayer(1000, "Player " + std::to_string(i + 1));
        
        players.push_back(newPlayer);
    }


}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Game::~Game()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, Game const &instance) {
    o << "Game State:\n";
    o << "Number of Players: " << instance.players.size() << "\n";
    o << "Dealer Position: " << instance.dealerPosition << "\n";
    o << "Small Blind: " << instance.smallBlind << "\n";
    o << "Big Blind: " << instance.bigBlind << "\n";

    o << "Board Cards: ";
    if (!instance.board.getCards().empty()) {
        for (const auto& card : instance.board.getCards()) {
            o << card << " ";
        }
    } else {
        o << "No cards on the board yet.";
    }
    o << "\n";

    o << "Players:\n";
    for (const auto& player : instance.players) {
        o << player << "\n"; 
    }

    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

#include "Game.hpp"


size_t Game::firstPlayerToAct(bool isPreFlop) {
    size_t numPlayers = players.size();
	size_t firstPlayer;
    if (numPlayers == 2)
         return dealerPosition; // Small Blind agit en premier pré-flop en heads-up
	else
	{
		if (isPreFlop)
		{
			firstPlayer = (dealerPosition + 3) % numPlayers;
			while (players[firstPlayer].isFolded)
			{
				firstPlayer = (firstPlayer + 1) % players.size();
			}
			return firstPlayer;
			// return (dealerPosition + 3) % numPlayers; // Sinon, le joueur à gauche du BB commence
		}
		else
		{
			firstPlayer = (dealerPosition + 1) % numPlayers;
			while (players[firstPlayer].isFolded)
			{
				firstPlayer = (firstPlayer + 1) % players.size();
			}
			return firstPlayer;
			// return (dealerPosition + 1) % numPlayers; // Le joueur à gauche du dealer commence toujours post-flop
		}
	}
}

void Game::initializeGame() {

	size_t numPlayers = players.size();
	std::vector<std::string> basePositions = {" (BU)" ," (SB)", " (BB)"};
	std::vector<std::string> extendedPositions = {" F1", " F2", " F3", " (UTG)", " (HJ)", " (CO)"};										
	int j = MAX_PLAYER_COUNT - numPlayers;
	bool is_heads_up = false;

	for (auto& player : players) {
        player.resetHand();
    }
	board.clear();
	deck.reset();
    deck.randomize();

    smallBlind = 5;
    bigBlind = 10;
	dealerPosition = (dealerPosition + 1) % players.size(); 

    for (auto& player : players) {
        player.hand.draw(deck);
        player.hand.draw(deck);
		player.currentBet = 0;
		player.isFolded = false;
		player.position = "";
    }

	if (numPlayers == 2)
	{
		players[(dealerPosition) % players.size()].currentBet = smallBlind;
		players[(dealerPosition + 1) % players.size()].currentBet = bigBlind;
		is_heads_up = true;
	}
	else
	{
		players[(dealerPosition + 1) % players.size()].currentBet = smallBlind;
   		players[(dealerPosition + 2) % players.size()].currentBet = bigBlind;
	}


	/* Assign position string to players*/
	if (is_heads_up)
	{
		players[dealerPosition].position = "BU";
		players[(dealerPosition + 1) % numPlayers].position = "BB";
	}
	else
	{
		for (size_t i = 0; i < 3 ; i++)
		{
      		players[(dealerPosition + i) % numPlayers].position = basePositions[i];
  	 	}
		int i = 0;
		while (j < 6)
		{
			players[(dealerPosition + 3 + i) % numPlayers].position = extendedPositions[j];
			i++;
			j++;
		}
	}
}

void Game::playHand() {


    initializeGame();

	/*Preflop*/
	std::cout << *this << std::endl;
    manageBets(Stage::preFlop);
	
	/*Flop*/
    for (int i = 0; i < 3; i++) {
        board.draw(deck);
    }
	std::cout << *this << std::endl;
	manageBets(Stage::flop);
	
	/*Turn*/
    board.draw(deck);
	std::cout << *this << std::endl;
	manageBets(Stage::turn);
	
	
	/*River*/
    board.draw(deck);
	std::cout << *this << std::endl;
	manageBets(Stage::river);

    // showdown();
    // prepareForNextHand();
}

void Game::manageBets(Stage stage) {


	std::cout << "dealer position : " << Game::dealerPosition <<std::endl;
    size_t currentPlayer = Game::firstPlayerToAct(stage == Stage::preFlop);
	std::cout << "current player position : " << currentPlayer <<std::endl;
    int highestBet;
    size_t bbPosition;
	size_t numPlayers = players.size();
	int activePlayers;

	if (stage == Stage::preFlop)
		highestBet = bigBlind;
	else
		highestBet = 0;


	/*HEADS UP BB position is different*/
	if (numPlayers == 2)
		bbPosition = (dealerPosition + 1) % players.size(); 
	else
		bbPosition =(dealerPosition + 2) % players.size();


    while (true) 
	{
        int toCall = highestBet - players[currentPlayer].currentBet;
        Action action = players[currentPlayer].decideAction(toCall, highestBet);
        
        switch (action.type) {
            case ActionType::Fold:
                players[currentPlayer].isFolded = true;
                break;
            case ActionType::Call:
            case ActionType::Check:
                players[currentPlayer].currentBet += toCall;
                break;
            case ActionType::Raise:
				highestBet = action.amount;
				std::cout << "action amount : " << action.amount << std::endl;
                players[currentPlayer].currentBet = highestBet;
                break;
        }


        if (currentPlayer == bbPosition) {
            bbHasacted = true;
        }

        // Passer au joueur suivant

		activePlayers = std::count_if(players.begin(), players.end(), [](const Player& p) { return !p.isFolded; });
        if (activePlayers == 1) {
			std::cout << "all folded" << std::endl;
            break;
        }
		do
		{
			currentPlayer = (currentPlayer + 1) % players.size();
		} while (players[currentPlayer].isFolded);

        // Vérifier si tous les joueurs ont agi
        if (bbHasacted && std::all_of(players.begin(), players.end(), [&](const Player& p) {
            return p.currentBet == highestBet || p.isFolded;
        })) 
		{
			std::cout << " next street" << std::endl;
            break; // Tous les joueurs ont agi ou fold, fin de la ronde de mises
        }
    }

    // Réinitialiser pour la prochaine ronde de mises
    for (auto& player : players) {
        player.currentBet = 0;
    }
}





/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
