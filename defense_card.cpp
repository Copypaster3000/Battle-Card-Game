//defense_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file for the defense card class which manages defense cards

#include "defense_card.h"


//defualt constructot, sets card atrributes to half power
defense_card::defense_card(void) : card("Defense Card"), strength(190), type(1), heal(62)
{}


//constructor, sets card attributes to values passed in
defense_card::defense_card(char* name, int str, int typ, int hl) : card(name), strength(str), type(typ), heal(hl)
{}


//destructor
defense_card::~defense_card(void)
{}
