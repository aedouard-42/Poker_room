#ifndef Board_HPP
# define Board_HPP

# include <iostream>
# include <string>

#include "../deck/Deck.hpp"

class Board
{
	public:
		Board();
		~Board();
		void draw(Deck &deck);
		void clear();
		int size() const;
		std::vector<Card> getCards()const;
		Card& operator[](size_t i) 
		{
			if  (i >= cards.size())
				throw std::exception();
        	return cards[i];
   		}

		const Card& operator[](size_t i) const 
		{
			if  (i >= cards.size())
				throw std::exception();
			return cards[i];
		}
	private:
		std::vector<Card> cards;
};

std::ostream &operator<<(std::ostream &o, Board const &instance);



#endif /* ************************************************************* Board_HPP */
