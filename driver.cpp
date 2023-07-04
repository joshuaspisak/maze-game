/******************************************************
** Program: driver.cpp
** Author: Joshua Spisak
** Date: 3/9/2023
** Description: main driver
** Input: option to continue
** Output: gameplay
******************************************************/


#include <iostream>

#include "Game.h"
#include "MazeLocation.h"
#include "Wall.h"
#include "OpenSpace.h"
#include "Maze.h"
#include "MazePerson.h"
#include "IntrepidStudent.h"
#include "TA.h"
#include "Instructor.h"

using namespace std;

int main(){

    srand(time(NULL));

    Game game;

    int quit = 1;

    /* 
     *  loops until quits
     */

    while(quit == 1){

        game.play();

        cout << endl << "Would you like to play again? (1-yes, 0-no): ";

        cin >> quit;

    }

    return 0;
}