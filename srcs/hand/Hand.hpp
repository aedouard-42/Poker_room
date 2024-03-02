#ifndef HAND_HPP
# define HAND_HPP

# include <iostream>
# include <string>

#include "../deck/Deck.hpp"

class Hand
{
	public:
		Hand();
		Hand(Hand const &src);
		~Hand();
		Hand &operator=(Hand const &rhs);
		void draw(Deck &deck);
		void clear();
		std::vector<Card> getCards()const;
		unsigned int size() const;
	private:
		std::vector<Card> cards;
};

std::ostream &operator<<(std::ostream &o, Hand const &instance);


#endif /* ************************************************************* HAND_HPP */
