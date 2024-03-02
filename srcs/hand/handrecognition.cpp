
#include "handrecognition.hpp"

int cards_straight(std::vector<Card> cards)
{
	std::sort(cards.begin(), cards.end());
	unsigned int tmp_value = cards.back().getValue();
	int straight_cards = 1;

	for (auto i = cards.rbegin(); i != cards.rend(); i++)
	{
		if (i->getValue() == tmp_value - 1)
			straight_cards++;
		else
			straight_cards = 1;
		if (straight_cards == 5)
			return (tmp_value + 5);
		tmp_value = i->getValue();
	}
	if (cards.back().getValue() != 12)
		return 0;
	else
	{
		straight_cards = 1;
		tmp_value = 0;
		for (auto i = cards.begin(); i != cards.end(); i++)
		{
			if (i->getValue() == tmp_value + 1)
				straight_cards++;
			else
				return 0;
			if (straight_cards == 5)
				return 5;
		}
	}
	return 0;
}

int	get_flush_type(std::vector<Card> cards)
{
	int spadecount = 0;
	int heartcount = 0;
	int diamondcount = 0;
	int clubcount = 0;

	for (auto i = cards.begin(); i != cards.end(); i++)
	{
		if (i->getColor() == SPADE)
			spadecount++;
		else if (i->getColor() == HEART)
			heartcount++;
		else if (i->getColor() == DIAMOND)
			diamondcount++;
		else if (i->getColor() == CLUB)
			clubcount++;
	}
	if (spadecount >= 5)
		return SPADE;
	else if (heartcount >= 5)
		return HEART;
	else if (diamondcount >= 5)
		return DIAMOND;
	else if (clubcount >= 5)
		return CLUB;
	else
		return NOFLUSH;
}

int	check_straightflush(std::vector<Card> cards)
{
	std::sort(cards.begin(), cards.end());
	unsigned int tmp_value = cards.back().getValue();
	unsigned int prev_color = cards.back().getColor();
	int straight_cards = 1;

	for (auto i = cards.rbegin(); i != cards.rend(); i++)
	{
		if (i->getValue() == tmp_value - 1 && i->getColor() == prev_color)
			straight_cards++;
		else
			straight_cards = 1;
		if (straight_cards == 5)
			return (STRAIGHT_FLUSH);
		tmp_value = i->getValue();
		prev_color = i->getColor();
	}
	if (cards.back().getValue() != 12)
		return HIGHCARD;
	else
	{
		straight_cards = 1;
		tmp_value = 0;
		prev_color = cards.back().getColor();
		for (auto i = cards.begin(); i != cards.end(); i++)
		{
			if (i->getValue() == tmp_value + 1)
				straight_cards++;
			else
				return HIGHCARD;
			if (straight_cards == 5)
				return STRAIGHT_FLUSH;
		}
	}
	return HIGHCARD;
}

int	get_hand_type(std::vector<Card> cards)
{
	int value_array[13] = {0};

	for (auto i = cards.begin(); i != cards.end(); i++)
	{
		value_array[i->getValue()]++;
	}
	int *foo = std::find(std::begin(value_array), std::end(value_array), 4);
	if (foo != std::end(value_array))
		return QUADS;
	foo = std::find(std::begin(value_array), std::end(value_array), 3);
	if (foo != std::end(value_array))
	{
		/* *foo = 0 removes the 3found cards from the array for next search*/
		*foo = 0; 
		foo = std::find(std::begin(value_array), std::end(value_array), 2);
		int *foo2 = std::find(std::begin(value_array), std::end(value_array), 3);
			if (foo != std::end(value_array) || foo2 != std::end(value_array))
				return FULL_HOUSE;
			else
				return TRIPS;
	}
	else 
	{
		foo = std::find(std::begin(value_array), std::end(value_array), 2);
		if (foo != std::end(value_array))
		{
			*foo = 0;
			foo = std::find(std::begin(value_array), std::end(value_array), 2);
			if (foo != std::end(value_array))
				return TWO_PAIRS;
			else
				return PAIR;
		}
	}
	return HIGHCARD;
}

int Hand_compare(Hand &h1,  Board &Board)
{
	std::vector <Card> v1;

	for (int i = 0; i < Board.size(); i++)
		v1.push_back(Board[i]);
	for (unsigned int i = 0; i < h1.size(); i++)
		v1.push_back(h1.getCards()[i]);
	std::sort(v1.begin(), v1.end());
	// for (auto i = v1.begin(); i != v1.end(); i++)
	// 	std::cout << '|' << *i;
	
	int value_type = check_straightflush(v1);
	//int value_type = HIGHCARD;

	if (value_type == STRAIGHT_FLUSH)
		return STRAIGHT_FLUSH;
	else
	{
		value_type = get_hand_type(v1);
		if (value_type >= FULL_HOUSE)
		{
			if (get_flush_type(v1) != NOFLUSH)
				return FLUSH;
			//std::cout << "straight cards :" << cards_straight(v1) << std::endl;
			else if (cards_straight(v1) >= 5)
				return STRAIGHT;
		}
	}
	return value_type;
}

void display_compare(Hand &h , Board &Board)
{
	int value_type = Hand_compare(h, Board);

	std::cout << std::endl;
	if (value_type == STRAIGHT_FLUSH)
		std::cout << "straight flush" << std::endl;
	else if (value_type == QUADS)
		std::cout << "quads" << std::endl;
	else if (value_type == FULL_HOUSE)
		std::cout << "full house" << std::endl;
	else if (value_type == FLUSH)
		std::cout << "flush" << std::endl;
	else if (value_type == STRAIGHT)
		std::cout << "straight" << std::endl;
	else if (value_type == TRIPS)
		std::cout << "trips" << std::endl;
	else if (value_type == TWO_PAIRS)
		std::cout << "two pairs" << std::endl;
	else if (value_type == PAIR)
		std::cout << "pair" << std::endl;
	else if (value_type == HIGHCARD)
		std::cout << "highcard" << std::endl;
}
