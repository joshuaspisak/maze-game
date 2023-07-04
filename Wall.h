/******************************************************
** Program: wall.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: wall header
** Input:
** Output:
******************************************************/

#ifndef WALL_H
#define WALL_H

#include <iostream>
#include <vector>

#include "MazeLocation.h"
#include "TA.h"

using namespace std;

class Wall : public MazeLocation{

private:
    char display_character = '#';
    
public:
    Wall();

    char get_display_character();
    bool is_occupiable();

    void set_has_student(bool);
    bool has_student();

    void set_has_ta(int);
    bool has_ta();

    void set_has_instructor(bool);
    bool has_instructor();

    void set_has_skill(bool);
    bool has_skill();

    vector<TA*> get_tas();

    vector<char> get_objects();

    ~Wall();

    MazePerson* get_person();

    void set_person(MazePerson*);

};

#endif