/******************************************************
** Program: mazelocation.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: mazelocation header
** Input:
** Output:
******************************************************/

#ifndef MAZELOCATION_H
#define MAZELOCATION_H

#include <iostream>
#include <vector>

#include "MazePerson.h"
#include "TA.h"

using namespace std;

class MazeLocation{

private:

public:
    MazeLocation();
    
    virtual bool is_occupiable() = 0;

    virtual char get_display_character() = 0;

    virtual void set_has_student(bool) = 0;
    virtual bool has_student() = 0;

    virtual void set_has_ta(int) = 0;
    virtual bool has_ta() = 0;

    virtual void set_has_instructor(bool) = 0;
    virtual bool has_instructor() = 0;

    virtual void set_has_skill(bool) = 0;
    virtual bool has_skill() = 0;

    virtual vector<char> get_objects() = 0;

    virtual ~MazeLocation();

    virtual MazePerson* get_person() = 0;

    virtual vector<TA*> get_tas() = 0;

    virtual void set_person(MazePerson*) = 0;
};

#endif