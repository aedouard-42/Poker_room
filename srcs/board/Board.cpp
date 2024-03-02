

#include "Board.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Board::Board()
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Board::~Board()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, Board const &instance)
{

	unsigned long i = 0;
	while (i < instance.getCards().size())
	{
		o << "|" <<instance.getCards()[i] ;
		i++;
	}
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Board::draw(Deck &deck)
{
	std::vector<Card> cardscpy = deck.getCards();
	unsigned int size = cardscpy.size();
	// std::cout << size << std::endl;
	Card tmp_card(cardscpy[size - 1]);
	// std::cout << tmp_card << std::endl;
	this->cards.push_back(tmp_card);
	deck.remove();
}

int Board::size() const
{
	return this->cards.size();
}

void Board::clear() {
    cards.clear(); // Supprime toutes les cartes du vector
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


std::vector<Card> Board::getCards()const
{
	return this->cards;
}


/* ************************************************************************** */
