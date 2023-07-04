/******************************************************
** Program: mazeperson.cpp
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: mazeperson abstract class
** Input:
** Output:
******************************************************/

#include "MazePerson.h"

void MazePerson::set_location(int row, int col){
    this->row = row;
    this->col = col;
}

int MazePerson::get_row(){
    return this->row;
}

int MazePerson::get_col(){
    return this->col;
}

MazePerson::~MazePerson(){

}