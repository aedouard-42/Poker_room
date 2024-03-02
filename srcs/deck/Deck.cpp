#include "Deck.hpp"

Deck::Deck()
{

	unsigned int i = 0;
	while (i < 52)
	{
		this->cards.push_back(Card(i, i % 13, i % 4));
		i++;
	}
}
Deck::~Deck()
{
}

std::ostream &operator<<(std::ostream &o, Deck const &instance)
{

	unsigned long i = 0;
	while (i < instance.getCards().size())
	{
		o << "|" <<instance.getCards()[i] ;
		i++;
		if (i % 13 == 0)
			std::cout << std::endl;
	}

	return o;
}

void Deck::randomize()
{
	std::random_device rd;
	std::default_random_engine rng(rd());
	std::shuffle(this->cards.begin(), this->cards.end(), rng);
}

std::vector<Card> Deck::getCards()const
{
	return this->cards;
}

void Deck::add(Card card)
{
	this->cards.push_back(card);
}

void Deck::remove()
{
	this->cards.pop_back();
}

void Deck::display()
{
	unsigned long i = 0;
	while (i < cards.size())
	{
		std::cout << cards[i];
		i++;
	}
}


/* ************************************************************************** */
