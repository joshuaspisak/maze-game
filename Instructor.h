/******************************************************
** Program: instructor.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: instructor header
** Input:
** Output:
******************************************************/

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>

#include "MazePerson.h"

using namespace std;

class Instructor : public MazePerson{


private:

public:

    Instructor();

    char get_move();

    int get_num_skills();

    void add_skill();

    int get_moved();

    void set_moved(int);

    ~Instructor();

};

#endif