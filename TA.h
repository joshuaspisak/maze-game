/******************************************************
** Program: ta.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: ta header
** Input:
** Output:
******************************************************/

#ifndef TA_H
#define TA_H

#include <iostream>

#include "MazePerson.h"

using namespace std;

class TA : public MazePerson{

private:

    int moved;

public:

    TA();

    char get_move();

    int get_num_skills();

    void add_skill();

    int get_moved();

    void set_moved(int);

    ~TA();

};

#endif