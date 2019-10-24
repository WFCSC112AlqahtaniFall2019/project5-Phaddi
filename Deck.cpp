#include "Deck.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

Deck::Deck() //default constructor
{
    arraySize = 52;
    cards = new Card[arraySize];
    cardsLeft = 52;
}

Deck::Deck(const Deck& C) //copy constructor
{
    cards = new Card;
    *cards = *(C.cards);
    arraySize = C.arraySize;
}

Deck::~Deck() //destructor
{
    delete cards;
}

Deck& Deck::operator = (const Deck& rhs) //copy assignment operator
{
    if(this != &rhs)
    {
        delete cards;
        cards = new Card;
        *cards = *(rhs.cards);
    }
    return *this;
}

void Deck::populate()
{
    for(int i = 0; i < 13; i++) //13 values of cards
    {
        for(int j = 0; j < 4; j++) //4 suits (13*4=52)
        {
            Card c = Card(i, j);
            cards[(4 * i + j)] = c;
        }
    }
}

void Deck::shuffle()
{
    int c1;
    int c2;
    Card temp;
    srand(time(0));
    for(int i = 0; i < pow(cardsLeft, 2); i++)
    {
        c1 = rand() % cardsLeft;
        c2 = rand() % cardsLeft;
        temp = cards[c1];
        cards[c1] = cards[c2];
        cards[c2] = temp;
    }
}

bool Deck::addCard(Card card)
{
    if(cardsLeft == 0) //as long as deck is not full
    {
        cout << "There is no more space in the deck" << endl;
        return false;
    }
    else{
        cards[cardsLeft - 1] = card;
        cardsLeft--;
        return true;
    }
}

void Deck::PrintDiscard()
{
    cout << "Put " << cards[cardsLeft].CardPrint() << " and " << cards[cardsLeft].CardPrint() << " in the discard pile" << endl;
}

Card Deck::removeCard() {
    return cards[-cardsLeft];
}

Card Deck::pickCard() {
    cardsLeft--;
    return cards[cardsLeft];
}