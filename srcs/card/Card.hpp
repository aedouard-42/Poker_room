#ifndef CARD_HPP
# define CARD_HPP

# include <iostream>
# include <string>

enum COLORS
{
	CLUB,
	DIAMOND,
	SPADE,
	HEART,
	NOFLUSH = -999
};

enum VALUES
{
	DEUCE,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	HEIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

class Card
{
	public:
	
		Card();
		Card(Card const &src);
		Card(unsigned int id, unsigned int value, unsigned int color);
		~Card();
		unsigned int getId(void)const;
		unsigned int getValue(void)const;
		unsigned int getColor(void)const;
		bool operator==(Card const &rhs);
		bool operator<(Card const &rhs);
		bool operator<=(Card const &rhs);
		bool operator>(Card const &rhs);
		bool operator>=(Card const &rhs);


	private:
		unsigned int _id;
		unsigned int _value;
		unsigned int _color;
};

std::ostream &operator<<(std::ostream &o, Card const &i);

#endif /* ************************************************************* CARD_HPP */
