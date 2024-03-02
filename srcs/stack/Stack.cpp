

#include "Stack.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Stack::Stack()
{
	this->value = 0;
}

Stack::Stack(int value)
{
	this->value = value;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Stack::~Stack()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, Stack const &instance)
{
	o << instance.value;
	return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Stack::receive(int value)
{
	this->value = this->value + value;
}

void	Stack::remove(int value)
{
	this->value = this->value - value;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/




/* ************************************************************************** */
