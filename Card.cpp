#include "Card.h"
#include <iostream>
using namespace std;

Card::Card() //default constructor
{
    rank = 0;
    suit = 0;
}

Card::Card(int x, int y) //specific constructor
{
    rank = x;
    suit = y;
}

bool Card::operator < (Card c)
{
    if(this->rank < c.rank)
    {
        return true;
    }
    if(this->rank > c.rank)
    {
        return false;
    }
    if(this->rank == c.rank)
    {
        if(this->suit < c.suit)
        {
            return true;
        }
        if(this->suit > c.suit)
        {
            return false;
        }
    }
}

bool Card::operator>(Card c)
{
    if(this->rank > c.rank)
    {
        return true;
    }
    if(this->rank < c.rank)
    {
        return false;
    }
    if(this->rank == c.rank)
    {
        if(this->suit > c.suit)
        {
            return true;
        }
        if(this->suit < c.suit)
        {
            return false;
        }
    }
}

string Card::CardPrint()
{
    return ranks[rank] + " of " + suits[suit];
}