#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <string>

#include "Deck.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "handrecognition.hpp"

enum class Stage {
    preFlop,
    flop,
    turn,
    river
};

#define MAX_PLAYER_COUNT 9

class Game {
public:
    Game(int numPlayers);
    ~Game();

    void initializeGame();

    // // Jouer une main du début à la fin
    void playHand();

    // Gérer un tour de mises
    void manageBets(Stage stage);

	size_t firstPlayerToAct(bool isPreFlop);

    // // Distribuer les cartes initiales aux joueurs
    // void distributeInitialCards();

    // // Effectuer le flop : distribuer les 3 premières cartes communes
    // void performFlop();

    // // Effectuer le turn : distribuer la 4ème carte commune
    // void performTurn();

    // // Effectuer la river : distribuer la 5ème et dernière carte commune
    // void performRiver();

    // // Afficher l'état actuel du jeu (pour le débogage ou l'interface utilisateur)
    // void displayGameState() const;

    // // Déterminer le gagnant de la main
    // void determineWinner();

    // // Réinitialiser pour la prochaine main
    // void prepareForNextHand();


    std::vector<Player> players; // Liste des joueurs dans la partie
    Deck deck;                   // Le deck de cartes utilisé pour la partie
    Board board;                 // Le tableau contenant les cartes communes
    int dealerPosition;          // La position du dealer dans le vecteur des joueurs
    int smallBlind;              // La valeur du small blind
    int bigBlind;                // La valeur du big blind
	bool bbHasacted = false;


    // Méthodes privées pour des opérations internes
    // void shuffleAndDeal();       // Mélanger le deck et distribuer les cartes
    // void advanceDealer();        // Passer au prochain dealer

	private:
};

std::ostream& operator<<(std::ostream& os, const Game& game);

#endif /* GAME_HPP */
