

#include "Hand.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Hand::Hand()
{
}

Hand::Hand(Hand const &src) : cards(src.cards) {

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Hand::~Hand()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, Hand const &instance)
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

void Hand::draw(Deck &deck)
{
	std::vector<Card> cardscpy = deck.getCards();
	unsigned int size = cardscpy.size();
	// std::cout << size << std::endl;
	Card tmp_card(cardscpy[size - 1]);
	// std::cout << tmp_card << std::endl;
	this->cards.push_back(tmp_card);
	deck.remove();
}

void Hand::clear() {
    cards.clear(); // Utilise la méthode clear de l'objet Hand pour vider la main du joueur
}


unsigned int Hand::size() const
{
	return this->cards.size();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<Card> Hand::getCards()const
{
	return this->cards;
}


/* ************************************************************************** */
