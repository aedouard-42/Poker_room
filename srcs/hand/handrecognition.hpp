#ifndef HANDRECOGNITION_HPP
# define HANDRECOGNITION_HPP

# include <iostream>
# include <string>
# include <vector>
#include "Hand.hpp"
#include "../board/Board.hpp"

enum HAND_TYPES
{
	STRAIGHT_FLUSH,
	QUADS,
	FULL_HOUSE,
	FLUSH,
	STRAIGHT,
	TRIPS,
	TWO_PAIRS,
	PAIR,
	HIGHCARD
};
void display_compare(Hand &h , Board &board);
int Hand_compare (Hand &h1, Hand &h2, Board &board);

int cards_straight(std::vector<Card> vector);
int is_flush(std::vector<Card> vector);
int	get_hand_type(std::vector<Card> cards);

#endif /* ************************************************************* HANDRECOGNITION_HPP */
