/******************************************************
** Program: game.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: game header
** Input:
** Output:
******************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Wall.h"
#include "OpenSpace.h"
#include "Maze.h"
#include "IntrepidStudent.h"
#include "TA.h"
#include "Instructor.h"

using namespace std;

class Game{

private:

    int appease;


public:

    Game();

    int move_wt(Maze&, int, int);

    int move_at(Maze&, int, int);

    int move_st(Maze&, int, int);

    int move_dt(Maze&, int, int);

    int move_w(Maze&, int, int);

    int move_a(Maze&, int, int);

    int move_s(Maze&, int, int);

    int move_d(Maze&, int, int);

    int move_p(Maze&, int, int);

    void play();

    bool check_ta(Maze&);

    int check_instructor(Maze&);

    int check_skill(Maze&);

    int move(Maze&);

    void reset_moved(Maze&);

    void move_ta(Maze&);

};

#endif