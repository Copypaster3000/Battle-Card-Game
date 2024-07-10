//card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the card class, this class manages the card's name
//

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <cstring>
using namespace std;

class card
{
    public:
        card(void); //Default constructor 
		card(const string & str); //Constructor
		card(const card &); //Copy constructor
        ~card(void); //Destructor
		card & operator = (const card &); //assignment
		int change_name(string & new_nm); //Changes card's name, returns 1 for success
		int ultimate_name(void); //Sets card name to a name so powerful, it is highly unlikely to lose (joke), returns 1 for success
		int delete_name(void); //Deletes name, sets it to nullptr, returns 1 for success


    protected:
		char* name; //Holds the card's name

};


#endif //CARD_H
