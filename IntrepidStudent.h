/******************************************************
** Program: intrepidstudent.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: student header
** Input:
** Output:
******************************************************/

#ifndef INTREPIDSTUDENT_H
#define INTREPIDSTUDENT_H

#include <iostream>

#include "MazePerson.h"

using namespace std;

class IntrepidStudent : public MazePerson{

private:

    int num_skills;

public:

    

    IntrepidStudent();

    IntrepidStudent(int);

    char get_move();

    int get_num_skills();

    void add_skill();

    int get_moved();

    void set_moved(int);

    ~IntrepidStudent();

};

#endif