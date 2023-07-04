/******************************************************
** Program: mazeperson.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: mazeperson abstract class header
** Input:
** Output:
******************************************************/

#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include <iostream>

using namespace std;

class MazePerson{

protected:
    int row;
    int col;

public:
    virtual char get_move() = 0;
    void set_location(int, int);
    int get_row();
    int get_col();

    virtual int get_num_skills() = 0;
    virtual void add_skill() = 0;
    virtual int get_moved() = 0;

    virtual void set_moved(int) = 0;

    virtual ~MazePerson();

};

#endif