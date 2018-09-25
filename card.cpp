//
//  card.cpp
//  WarCardGame
//
//  Created by Rex Ruzek on 9/24/18.
//  Copyright © 2018 Rex Ruzek. All rights reserved.
//
#include<vector>
#include "card.hpp"
using std::cout;
using std::endl;

// Defualt constructer for the game class.
Game::Game()
{
    
}

// Constructor fo the card
Card::Card(Rank r, Suit s)
{
    m_rank = r;
    m_suit = s;
}

// Creates the deck
void Game::makeDeck()
{
    int rankCount = 0;
    int suitCount = 0;
    for( int i = 0; i <= 52; i++)
    {
        gameDeck.push_back(Card(Rank(rankCount),Suit(suitCount)));
        if(rankCount == 12){
            suitCount++;
            rankCount = 0;
        }
        rankCount++;
    }
    
    /* Debugging stuff
    for( int i = 0; i <= 52; i++)
    {
        std::cout << gameDeck[i].getRank() << " of " <<  gameDeck[i].getSuit() << std::endl;
    }*/
}

// Shuffles the deck
void Game::shuffleDeck()
{
    for(int i = 0; i <= 52; i++)
    {
        int second = (rand() + time(0)) % 52;

        Card temp = gameDeck[i];
        gameDeck[i] = gameDeck[second];
        gameDeck[second] = temp;
    }
    
}

// Divids the deck up bewteen two players.
void Game::dividDeck()
{
    bool whichOne = true;
    for(int i = 52; gameDeck.size() != 0; i--)
    {
        if(whichOne){
            playerAdeck.push_back(gameDeck[i]);
            gameDeck.pop_back();
        }
        else{
            playerBdeck.push_back(gameDeck[i]);
            gameDeck.pop_back();
        }
        whichOne = !whichOne;
    }
    
    /*  Debugging stuff
    cout << endl << endl ;
    for( int i = 0; i <= playerAdeck.size() - 1 ; i++)
    {
        std::cout << playerAdeck[i].getRank() << " of " <<  playerAdeck[i].getSuit() << std::endl << i << endl;
    }
    cout << endl << endl ;
    for( int i = 0; i <= playerBdeck.size() - 1; i++)
    {
        std::cout << playerBdeck[i].getRank() << " of " <<  playerBdeck[i].getSuit() << std::endl << i << endl;
    }*/
}

// Function for the game
void Game::playGame()
{
    int aScore = 26;
    int bScore = 26;
    int totalTurns = 0;
    bool gameOver = false;
    enum statis
    {
        aWon,
        bWon,
        tie,
    };
    statis gameStatis = tie;
    
    cout << "Welcome to war!" << endl;
    cout << "Lets Begin:" << endl;
    
    // Loop for the game, it goes until one of the players has no more cards.
    while(!gameOver)
    {
        cout << "Player A's card has a value of " << playerAdeck.front().getRank() << endl;
        cout << "PLayer B's card has a value of " << playerBdeck.front().getRank() << endl;
        
        // Puts the cards from both players into a pile
        pileToTake.push_back(playerBdeck.front());
        pileToTake.push_back(playerAdeck.front());
        
        // If else statments to computer who won the battle
        if(playerAdeck.front().getRank() > playerBdeck.front().getRank())
        {
            cout << "  -Since A's card is better, A get gets the pile. " << endl;
            for(int i = 0; i < pileToTake.size(); i++)
            {
                aScore++;
                playerAdeck.push_back(pileToTake[i]);
            }
            pileToTake.clear();
            gameStatis = aWon;
        }
        else if(playerAdeck.front().getRank() < playerBdeck.front().getRank())
        {
            cout << "  -Since B's card is better, B gets the pile. " << endl;
            for(int i = 0; i < pileToTake.size(); i++)
            {
                bScore++;
                playerBdeck.push_back(pileToTake[i]);
            }
            pileToTake.clear();
            gameStatis = bWon;
        }
        else
        {
            cout << "  -The two values are the same, therefore they keep drawing cards. " << endl;
            gameStatis = tie;
        }
        
        // Takes cards away from both the player's decks
        playerBdeck.erase(playerBdeck.begin());
        playerAdeck.erase(playerAdeck.begin());
        
        
        aScore--;
        bScore--;
        totalTurns++;
        
        
        if(playerAdeck.size() == 0 || playerBdeck.size() == 0)
        {
            gameOver = true;
            cout << "A has: " << aScore << endl;
            cout << "B has: " << bScore << endl;
            cout << "Total number of turns was: " << totalTurns << endl;
        }
    }
    
}











