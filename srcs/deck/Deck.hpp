#ifndef DECK_HPP
# define DECK_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
#include <random>
#include <iterator>

#include "../card/Card.hpp"

class Deck
{
	public:
		Deck();
		~Deck();
		void randomize();
		void add(Card card);
		void remove();
		void display();
		std::vector<Card> getCards()const;

	private:
		std::vector<Card> cards;

};

std::ostream &operator<<(std::ostream &o, Deck const &i);

#endif /* ************************************************************* DECK_HPP */
