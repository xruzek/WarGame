//
//  main.cpp
//  WarCardGame
//
//  Created by Rex Ruzek on 9/24/18.
//  Copyright © 2018 Rex Ruzek. All rights reserved.\
//
// Notes: Theres a miner bug where one deck has more cards than the other, I didn't have enough time to figure that one out(it's probably something simple I'm missing). Also I wasn't sure if you wanted me to have the cards name displayed or if you just wanted the value of each card. Either way, I couldn't figure out how to do that by using Enums and I didn't want to re-do everything. TBH this due date kinda snuck up on me.
#include "card.hpp"
#include <iostream>
#include <vector>

int main()
{
    // Creates and plays the game of war
    Game game1;
    game1.makeDeck();
    game1.shuffleDeck();
    game1.dividDeck();
    game1.playGame();
   
    return 0;
}
