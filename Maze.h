/******************************************************
** Program: maze.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: maze header
** Input:
** Output:
******************************************************/

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <ctime>

#include "Wall.h"
#include "OpenSpace.h"
#include "IntrepidStudent.h"
#include "TA.h"
#include "Instructor.h"

using namespace std;

class Maze{

private:
    vector<vector<MazeLocation*> > locations;

    int size;

public:

    Maze();

    Maze(int);

    MazeLocation* get_location(int, int);

    vector<vector<int> > wall_arr(int);

    void populate_instructor(int);

    void populate_ta(int);

    void populate_skill(int);

    void populate_student(int);

    void display_maze(Maze&, int);

    int get_size();

    int get_num_skills(Maze&);

    Maze(const Maze&);

    Maze& operator=(const Maze&);

    ~Maze();

};

#endif