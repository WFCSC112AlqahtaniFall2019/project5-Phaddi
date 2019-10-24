#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"
#include <iostream>

class Deck {
public:
    Deck(); //default constructor
    Deck(const Deck& C); //copy constructor
    Deck&  operator = (const Deck& rhs); //copy assignment operator
    Deck(int numCards); //constructor with parameter
    ~Deck();
    void shuffle(); //shuffles the deck
    bool addCard(Card newCard); //adds a card
    void populate(); //populates the deck
    void PrintDiscard(); //prints cards that were discarded
    Card pickCard(); //selects a card from the playing deck
    Card removeCard(); //eliminates card from playing deck
private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
