/******************************************************
** Program: wall.cpp
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: wall class
** Input:
** Output:
******************************************************/

#include "Wall.h"

Wall::Wall(){

}

char Wall::get_display_character(){
    return this->display_character;
}

bool Wall::is_occupiable(){
    return 0;
}

void Wall::set_has_student(bool){}
bool Wall::has_student(){
    return 0;
}

void Wall::set_has_ta(int){}
bool Wall::has_ta(){
    return 0;
}

void Wall::set_has_instructor(bool){}
bool Wall::has_instructor(){
    return 0;
}

void Wall::set_has_skill(bool){}
bool Wall::has_skill(){
    return 0;
}

vector<char> Wall::get_objects(){
    vector<char> v;
    return v;
}

Wall::~Wall(){

}

MazePerson* Wall::get_person(){
    return NULL;
}

void Wall::set_person(MazePerson*){

}

vector<TA*> Wall::get_tas(){
    vector<TA*> v;
    return v;
}