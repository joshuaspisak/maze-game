/******************************************************
** Program: intrepidstudent.cpp
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: student class
** Input:
** Output:
******************************************************/

#include "IntrepidStudent.h"


IntrepidStudent::IntrepidStudent(){
    this->num_skills = 0;
}

IntrepidStudent::IntrepidStudent(int num_skills){
    this->num_skills = num_skills;
}

/*********************************************************************
** Function: get_move
** Description: retrieves move input
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/

char IntrepidStudent::get_move(){

    cout << "Please select a move out of the following (w-move up, a-move left, s-move down, d-move right, p-appease the TAs with one programming skill): ";

    char move;

    cin >> move;

    return move;


}

int IntrepidStudent::get_num_skills(){
    return this->num_skills;
}

void IntrepidStudent::add_skill(){
    this->num_skills++;
}

IntrepidStudent::~IntrepidStudent(){

}

int IntrepidStudent::get_moved(){
    return 0;
}

void IntrepidStudent::set_moved(int){

}