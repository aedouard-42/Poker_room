#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include <string>

#include "Stack.hpp"
#include "Hand.hpp"
#include "Action.hpp"

class Player
{
	public:
		Player();
		Player(int chips_value, std::string name);
		~Player();


		Action decideAction(int toCall, int highestBet);
		int currentBet = 0;
		void resetHand();
		Stack stack;
		Hand hand;
		std::string name;
		std::string position;
		bool isFolded = false;
};

std::ostream &operator<<(std::ostream &o, Player const &instance);


#endif /* ************************************************************* PLAYER_HPP */
