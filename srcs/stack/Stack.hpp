#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>

class Stack
{
	public:
		Stack();
		Stack(int value);
		~Stack();
		int value;
		double chips_amount;
		void remove(int value);
		void receive(int value);
};

std::ostream &operator<<(std::ostream &o, Stack const &instance);


#endif /* ************************************************************* STACK_HPP */
