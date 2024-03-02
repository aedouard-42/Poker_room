

#include "Player.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Player::Player()
:
stack(0),
hand(),
name("default")
{
}

Player::Player(int chips_value, std::string name)
:
stack(chips_value),
hand()
{
	this->name = name;

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Player::~Player()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
std::ostream &operator<<(std::ostream &o, Player const &instance) {
    o << "Name: " << instance.name << instance.position << " | " << instance.stack << " | " << instance.hand << " | Still playing :" <<  (!instance.isFolded) ;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Player::resetHand() {
    hand.clear(); // Utilise la méthode clear de l'objet Hand pour vider la main du joueur
}

Action Player::decideAction(int toCall, int highestBet) {
	std::cout << name << position << ", vous devez suivre " << toCall << " ou vous pouvez relancer. (f/c/r): ";
    std::string input;
    std::cin >> input;

    if (input == "f") {
        return Action(ActionType::Fold);
    } else if (input == "c") {
        return Action(ActionType::Call, toCall);
    } else if (input == "r") {
        std::cout << "Montant de la relance: ";
        int raiseAmount;
        std::cin >> raiseAmount;
		if (raiseAmount <= highestBet)
		{
			std::cout << "montant de la relance trop faible" << std::endl;
			return decideAction(toCall, highestBet); // Demander à nouveau si l'input n'est pas valide
		}
        return Action(ActionType::Raise, (raiseAmount));
    } else {
        std::cout << "Action non reconnue, veuillez réessayer.\n";
        return decideAction(toCall, highestBet); // Demander à nouveau si l'input n'est pas valide
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
