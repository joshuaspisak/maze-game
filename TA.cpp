/******************************************************
** Program: ta.cpp
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: ta class
** Input:
** Output:
******************************************************/

#include "TA.h"

TA::TA(){
    this->moved = 0;
}

int TA::get_num_skills(){
    return 0;
}

/*********************************************************************
** Function: get_move
** Description: gets random move
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/

char TA::get_move(){

    int choice = (rand() % 4);

    if(choice == 0){
        return 'w';
    }

    if(choice == 1){
        return 'a';
    }

    if(choice == 2){
        return 's';
    }

    if(choice == 3){
        return 'd';
    }
    
}

void TA::add_skill(){

}

TA::~TA(){

}

int TA::get_moved(){
    return this->moved;
}

void TA::set_moved(int moved){
    this->moved = moved;
}