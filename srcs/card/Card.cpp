#include "Card.hpp"

Card::Card(void)
:
_id(0),
_value(0),
_color(0)
{
}

Card::Card(unsigned int id, unsigned int value, unsigned int color)
:
_id(id),
_value(value),
_color(color)
{
}

Card::Card(const Card &src)
{
	*this = src;
}


Card::~Card()
{
}

std::ostream &operator<<(std::ostream &o, Card const &i)
{
	typedef struct { std::string name; unsigned int id; } t_names;
	typedef struct {std::string color_str; unsigned int color;} t_colors;

	t_colors colors_id[] = {{"\e[0;32m", CLUB},  {"\e[0;36m" , DIAMOND}, {"\e[0;90m", SPADE}, {"\e[0;31m", HEART}};
	t_names color_names[] = {{"c", CLUB}, {"d", DIAMOND}, {"s", SPADE}, {"h", HEART}};
	t_names card_names[] = {{"2", DEUCE}, {"3", THREE}, {"4", FOUR}, {"5", FIVE}, {"6", SIX}, {"7", SEVEN}, {"8", HEIGHT}, {"9", NINE}, {"T", TEN}, {"J", JACK}, {"Q", QUEEN}, {"K", KING}, {"A", ACE}};
	o << colors_id[i.getColor()].color_str << card_names[i.getValue()].name << color_names[i.getColor()].name << "\e[0;37m";

	return o;
}

bool Card::operator==(Card const &rhs)
{
	if (this->_value == rhs._value)
		return (true);
	return (false);	
}

bool Card::operator<(Card const &rhs)
{
	return (this->_value < rhs._value);
}

bool Card::operator<=(Card const &rhs)
{
	return (this->_value <= rhs._value);
}

bool Card::operator>(Card const &rhs)
{
	return (this->_value > rhs._value);
}

bool Card::operator>=(Card const &rhs)
{
	return (this->_value >= rhs._value);
}

unsigned int Card::getId(void)const
{
	return this->_id;
}

unsigned int Card::getValue(void)const
{
	return this->_value;
}

unsigned int Card::getColor(void)const
{
	return this->_color;
}


/* ************************************************************************** */
