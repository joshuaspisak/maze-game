/******************************************************
** Program: game.cpp
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: implements entire game
** Input:
** Output:
******************************************************/


#include "Game.h"

Game::Game(){
    this->appease = 0;
}

/*********************************************************************
** Function: play
** Description: goes through all the game functions
** Parameters: 
** Pre-Conditions: game is started
** Post-Conditions: game ends
*********************************************************************/

void Game::play(){
    int size;

    int prompt_complete = 0;

    while(prompt_complete == 0){

        cout << "Please input the maze size of at least 5: ";

        cin >> size;

        if(size >= 5){

            prompt_complete++;

        }
    }

    Maze maze(size);

    /* 
     *  populates all data
     */

    maze.populate_instructor(size);

    maze.populate_ta(size);

    maze.populate_skill(size);

    maze.populate_student(size);

    int over = 0;

    this->check_skill(maze);

    maze.display_maze(maze, this->appease);

    while(over == 0){

        if(this->check_instructor(maze) == 1){

            over++;

            cout << endl << "Game Over by the Instructor." << endl;

            continue;

        }
        else if(this->check_instructor(maze) == 2){

            over++;

            cout << endl << "You Win! You can escape the maze with a passing grade!" << endl;

            continue;

        }
    

        if(this->check_ta(maze) == 1){

            over++;

            cout << endl << "You got caught by a TA." << endl;

            continue;

        }

        this->move_ta(maze);

        this->reset_moved(maze);

        while(true){

            if(this->move(maze) == 1){
                break;
            }
        
        }

        this->check_skill(maze);

        maze.display_maze(maze, this->appease);
    }
    
        
        

}

int Game::check_skill(Maze& maze){

    for (int i = 0; i < maze.get_size(); i++)

        {
            for (int j = 0; j < maze.get_size(); j++)

            {

                if(maze.get_location(i, j)->has_student() == 1 && maze.get_location(i, j)->has_skill() == 1){

                    maze.get_location(i, j)->get_person()->add_skill();

                    maze.get_location(i, j)->set_has_skill(0);

                }
            }
            
        }
        return 0;
}


int Game::move_w(Maze& maze, int i, int j){

    if(i-1 >= 0 && i-1<maze.get_size() && maze.get_location(i-1,j)->get_display_character() != '#'){

        maze.get_location(i,j)->set_has_student(0);

        maze.get_location(i-1,j)->set_has_student(1);

        if(maze.get_location(i-1,j)->get_person() != NULL){

            delete maze.get_location(i-1,j)->get_person();

        }

        maze.get_location(i-1,j)->set_person(new IntrepidStudent(maze.get_location(i,j)->get_person()->get_num_skills()));

        if(maze.get_location(i,j)->get_person() != NULL){

            delete maze.get_location(i,j)->get_person();

            maze.get_location(i,j)->set_person(NULL);

        }

        return 1;

    }
    else{

        cout << endl << "Sorry, that move is not valid" << endl;

        return 0;

    }
}

int Game::move_a(Maze& maze, int i, int j){

    if(j-1 >= 0 && j-1<maze.get_size() && maze.get_location(i,j-1)->get_display_character() != '#'){

        maze.get_location(i,j)->set_has_student(0);

        maze.get_location(i,j-1)->set_has_student(1);

        if(maze.get_location(i,j-1)->get_person() != NULL){

            delete maze.get_location(i,j-1)->get_person();

        }
        maze.get_location(i,j-1)->set_person(new IntrepidStudent(maze.get_location(i,j)->get_person()->get_num_skills()));

        if(maze.get_location(i,j)->get_person() != NULL){

            delete maze.get_location(i,j)->get_person();

            maze.get_location(i,j)->set_person(NULL);

        }

        return 1;

    }

    else{

        cout << endl << "Sorry, that move is not valid" << endl;

        return 0;

    }
}

int Game::move_s(Maze& maze, int i, int j){

    if(i+1 >= 0 && i+1<maze.get_size() && maze.get_location(i+1,j)->get_display_character() != '#'){

        maze.get_location(i,j)->set_has_student(0);

        maze.get_location(i+1,j)->set_has_student(1);

        if(maze.get_location(i+1,j)->get_person() != NULL){

            delete maze.get_location(i+1,j)->get_person();

        }
        maze.get_location(i+1,j)->set_person(new IntrepidStudent(maze.get_location(i,j)->get_person()->get_num_skills()));

        if(maze.get_location(i,j)->get_person() != NULL){

            delete maze.get_location(i,j)->get_person();

            maze.get_location(i,j)->set_person(NULL);
        }
        return 1;
    }
    else{
        cout << endl << "Sorry, that move is not valid" << endl;
        return 0;
    }
}

int Game::move_d(Maze& maze, int i, int j){

    if(j+1 >= 0 && j+1<maze.get_size() && maze.get_location(i,j+1)->get_display_character() != '#'){

        maze.get_location(i,j)->set_has_student(0);

        maze.get_location(i,j+1)->set_has_student(1);

        if(maze.get_location(i,j+1)->get_person() != NULL){

            delete maze.get_location(i,j+1)->get_person();

            maze.get_location(i,j+1)->set_person(NULL);

        }

        maze.get_location(i,j+1)->set_person(new IntrepidStudent(maze.get_location(i,j)->get_person()->get_num_skills()));

        if(maze.get_location(i,j)->get_person() != NULL){

            delete maze.get_location(i,j)->get_person();

            maze.get_location(i,j)->set_person(NULL);

        }
        return 1;
    }
    else{

        cout << endl << "Sorry, that move is not valid." << endl;

        return 0;
    }
}

int Game::move_wt(Maze& maze, int i, int j){

    if(i-1 >= 0 && i-1<maze.get_size() && maze.get_location(i-1,j)->get_display_character() != '#' && maze.get_location(i-1,j)->has_instructor() != 1){

        maze.get_location(i,j)->set_has_ta(-1);

        maze.get_location(i-1,j)->set_has_ta(1);

        maze.get_location(i-1,j)->get_tas()[maze.get_location(i-1,j)->get_tas().size()-1]->set_moved(1);

        return 1;
    }
    else{
        return 0;
    }
}

int Game::move_at(Maze& maze, int i, int j){

    if(j-1 >= 0 && j-1<maze.get_size() && maze.get_location(i,j-1)->get_display_character() != '#' && maze.get_location(i,j-1)->has_instructor() != 1){

        maze.get_location(i,j)->set_has_ta(-1);

        maze.get_location(i,j-1)->set_has_ta(1);

        maze.get_location(i,j-1)->get_tas()[maze.get_location(i,j-1)->get_tas().size()-1]->set_moved(1);

        return 1;
    }
    else{
        return 0;
    }
}

int Game::move_st(Maze& maze, int i, int j){

    if(i+1 >= 0 && i+1<maze.get_size() && maze.get_location(i+1,j)->get_display_character() != '#' && maze.get_location(i+1,j)->has_instructor() != 1){

        maze.get_location(i,j)->set_has_ta(-1);

        maze.get_location(i+1,j)->set_has_ta(1);

        maze.get_location(i+1,j)->get_tas()[maze.get_location(i+1,j)->get_tas().size()-1]->set_moved(1);

        return 1;
    }
    else{
        return 0;
    }
}

int Game::move_dt(Maze& maze, int i, int j){

    if(j+1 >= 0 && j+1<maze.get_size() && maze.get_location(i,j+1)->get_display_character() != '#' && maze.get_location(i,j+1)->has_instructor() != 1){\

        maze.get_location(i,j)->set_has_ta(-1);

        maze.get_location(i,j+1)->set_has_ta(1);

        maze.get_location(i,j+1)->get_tas()[maze.get_location(i,j+1)->get_tas().size()-1]->set_moved(1);

        return 1;
    }
    else{
        return 0;
    }
}

int Game::move_p(Maze& maze, int i, int j){

    if(maze.get_location(i,j)->get_person()->get_num_skills() >= 1){

        for (int i = 0; i < maze.get_size(); i++)

        {
            for (int j = 0; j < maze.get_size(); j++)

            {
                if(maze.get_location(i,j)->has_ta() > 0){


                }
            }
            
        }
        
    }
}

int Game::move(Maze& maze){

    for (int i = 0; i < maze.get_size(); i++)

    {

        for (int j = 0; j < maze.get_size(); j++)

        {

            if(maze.get_location(i,j)->has_student() == 1){

                char move = maze.get_location(i,j)->get_person()->get_move();

                if(move == 'w' && this->move_w(maze, i, j) == 1){

                    if(this->appease > 0){

                        this->appease--;

                    }

                    return 1;

                }
                else if(move == 'a' && this->move_a(maze,i,j) == 1){

                    if(this->appease > 0){

                        this->appease--;

                    }

                    return 1;

                }
                else if(move == 's' && this->move_s(maze,i,j) == 1){

                   if(this->appease > 0){

                        this->appease--;

                   }

                    return 1;

                }

                else if(move == 'd' && this->move_d(maze,i,j) == 1){

                    if(this->appease > 0){

                        this->appease--;

                    }

                    return 1;

                }

                else if(move == 'p'){

                    if(maze.get_location(i,j)->get_person()->get_num_skills() > 0){

                       this->appease = 10;

                       return 1;

                    }

                    else{

                        cout << endl << endl << "You don't have any programming skills." << endl << endl;

                        return 0;

                    }

                }

                return 0;

            }
        }
        
    }
    
}

void Game::reset_moved(Maze& maze){

    for (int i = 0; i < maze.get_size(); i++)

    {
        for (int j = 0; j < maze.get_size(); j++)

        {

            for (int k = 0; k < maze.get_location(i,j)->get_tas().size(); k++)

            {

                maze.get_location(i,j)->get_tas()[k]->set_moved(0);

            }
            
        }
        
    }
    
}

void Game::move_ta(Maze& maze){

    for (int i = 0; i < maze.get_size(); i++)

    {

        for (int j = 0; j < maze.get_size(); j++)

        {

            if(maze.get_location(i,j)->has_ta() > 0){

                
                for (int k = 0; k < maze.get_location(i,j)->get_tas().size(); k++){

                    if(maze.get_location(i,j)->get_tas()[k]->get_moved() == 0){

                        int ta_moved = 0;

                        while(ta_moved == 0){

                            char move = maze.get_location(i,j)->get_tas()[k]->get_move();

                            if(move == 'w' && this->move_wt(maze, i, j) == 1){

                                ta_moved++;

                            }
                            else if(move == 'a' && this->move_at(maze,i,j) == 1){

                                ta_moved++;

                            }
                            else if(move == 's' && this->move_st(maze,i,j) == 1){

                                ta_moved++;

                            }
                            else if(move == 'd' && this->move_dt(maze,i,j) == 1){

                                ta_moved++;

                            }
                        }
                    }
                }
            }
        }
        
    }
    
}

int Game::check_instructor(Maze& maze){

    for (int i = 0; i < maze.get_size(); i++)
        {
            for (int j = 0; j < maze.get_size(); j++)
            {
                if(maze.get_location(i, j)->has_student() == 1){

                    if(i+1 >= 0 && i+1 < maze.get_size() && maze.get_location(i+1, j)->has_instructor()){

                        if(maze.get_location(i, j)->get_person()->get_num_skills() < 3){

                            return 1;
                        }
                        else{

                            return 2;
                        }
                    }
                    if(i-1 >= 0 && i-1 < maze.get_size() && maze.get_location(i-1, j)->has_instructor()){

                        if(maze.get_location(i, j)->get_person()->get_num_skills() < 3){

                            return 1;
                        }
                        else{

                            return 2;
                        }
                    }
                    if(j+1 >= 0 && j+1 < maze.get_size() && maze.get_location(i, j+1)->has_instructor()){

                        if(maze.get_location(i, j)->get_person()->get_num_skills() < 3){

                            return 1;
                        }
                        else{

                            return 2;
                        }
                    }
                    if(j-1 >= 0 && j-1 < maze.get_size() && maze.get_location(i, j-1)->has_instructor()){

                        if(maze.get_location(i, j)->get_person()->get_num_skills() < 3){

                            return 1;
                        }
                        else{

                            return 2;
                        }
                    }
                }
            }
            
        }
        return 0;
}



bool Game::check_ta(Maze& maze){

    for (int i = 0; i < maze.get_size(); i++)
        {
            for (int j = 0; j < maze.get_size(); j++)
            {
                if(maze.get_location(i, j)->has_student() == 1){

                    if(i+1 >= 0 && i+1 < maze.get_size() && maze.get_location(i+1, j)->has_ta()){

                        if(this->appease == 0){

                            return 1;
                    }
                    }
                    if(i-1 >= 0 && i-1 < maze.get_size() && maze.get_location(i-1, j)->has_ta()){

                        if(this->appease == 0){

                            return 1;
                        }
                    }
                    if(j+1 >= 0 && j+1 < maze.get_size() && maze.get_location(i, j+1)->has_ta()){

                        if(this->appease == 0){

                            return 1;
                        }
                    }
                    if(j-1 >= 0 && j-1 < maze.get_size() && maze.get_location(i, j-1)->has_ta()){

                        if(this->appease == 0){

                            return 1;
                        }
                    }
                    if(maze.get_location(i, j)->has_ta()){

                        if(this->appease == 0){

                            return 1;
                        }
                    }
                }
            }
            
        }
        return 0;
}