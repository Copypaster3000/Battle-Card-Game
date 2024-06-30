//card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the card class

#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class card
{
    public:
        card(void);
		card(const char* str);

        ~card(void);


    protected:
		char* name;

};


#endif //CARD_H
