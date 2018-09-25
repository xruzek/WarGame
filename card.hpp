//
//  card.hpp
//  WarCardGame
//
//  Created by Rex Ruzek on 9/24/18.
//  Copyright © 2018 Rex Ruzek. All rights reserved.
//

#ifndef card_hpp
#define card_hpp
#include <stdio.h>
#include <vector>
#include <iostream>

// Enums for the rank and suit of the card.
enum Suit
{
    Spades,
    Clubs,
    Diamonds,
    Hearts,
};

enum Rank
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

// Class for the card
class Card
{
public:
    Card(Rank r, Suit s);
    //friend std::ostream& operator<<(std::ostream& os, const Card& card);
    Rank getRank() const
    {
        return m_rank;
    };
    Suit getSuit() const
    {
        return m_suit;
    };
private:
    Rank m_rank;
    Suit m_suit;
};

// Class that runs the game and makes/manages the decks
class Game
{
public:
    Game();
    void makeDeck();
    void shuffleDeck();
    void dividDeck();
    void playGame();
    Card getGameDeckCard(int num)
    {
        return gameDeck[num];
    }
private:
    std::vector<Card> gameDeck;
    std::vector<Card> playerAdeck;
    std::vector<Card> playerBdeck;
    std::vector<Card> pileToTake;
};
using Deck = std::vector<Card>;

#endif /* card_hpp */
