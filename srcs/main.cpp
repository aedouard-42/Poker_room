#include <iostream>
#include <string>

#include "Card.hpp"
#include "Stack.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "handrecognition.hpp"
#include "Game.hpp"


int main(void)
{
    Game game(6);


    game.playHand();
    std::cout << "next hand" << std::endl;
    // game.playHand();
    // std::cout << "next hand" << std::endl;
    // game.playHand();
    // std::cout << "next hand" << std::endl;
    // game.playHand();

    /*
        TODO :
        - fix BUG when oop checks , IP doesn t have option to play cause all players are are 0 postflop
        - game betting patterns + manual input testing
        - evaluate hand function
        - UI
    */

    return (0);
}
