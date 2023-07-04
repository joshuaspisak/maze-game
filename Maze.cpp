/******************************************************
** Program: maze.cpp
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: implements and displays maze
** Input:
** Output:
******************************************************/

#include "Maze.h"

Maze::Maze(){}

/*********************************************************************
** Function: Maze
** Description: constructor
** Parameters: int size
** Pre-Conditions:
** Post-Conditions: maze constructed
*********************************************************************/

Maze::Maze(int size){

    vector<vector<int> > wall_arr = this->wall_arr(size);


    for(int i = 0; i < size; i++){

        /* 
         *  instantiates mazelocation pointer vector
         */

        vector<MazeLocation*> row;

        for (int j = 0; j < size; j++)
        {
            if(wall_arr[i][j] == 1){

                row.push_back(new Wall());

            }
            else{
                row.push_back(new OpenSpace());
            }
        }
        
        this->locations.push_back(row);

    }

    this->size = size;

}

MazeLocation* Maze::get_location(int i, int j){

    return this->locations[i][j];

}

/*********************************************************************
** Function: wall_arr
** Description: returns the array of wall locations
** Parameters: int size
** Pre-Conditions:
** Post-Conditions: walls are created randomly
*********************************************************************/

vector<vector<int> > Maze::wall_arr(int size){

    

    vector<vector<int> > wall_arr;

    for (int i = 0; i < size; i++)
    {
        vector<int> row(size, 0);

        wall_arr.push_back(row);

    }

    int filled = 0;

    while(filled != 4){

        int wall_location = (rand() % (size*size));

        int row = wall_location / size;

        int col = wall_location % size;

        /* 
         *  loops through whole maze
         */

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if(j == row && k == col && wall_arr[j][k] == 0){

                    wall_arr[j][k] = 1;

                    filled++;

                }
            }
            
        }
        
    }

    return wall_arr;
}

void Maze::populate_instructor(int size){

   

    int filled = 0;

    while(filled != 1){

        int instructor_location = (rand() % (size*size));

        int row = instructor_location / size;

        int col = instructor_location % size;

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if(j == row && k == col && this->locations[j][k]->get_display_character() != '#'){

                    if(this->locations[j][k]->get_person() != NULL){

                        delete this->locations[j][k]->get_person();

                        this->locations[j][k]->set_person(NULL);
                    }

                    this->locations[j][k]->set_has_instructor(1);

                    filled++;

                    this->locations[j][k]->set_person(new Instructor());

                }
            }
            
        }
        
    }
}

int Maze::get_num_skills(Maze& maze){

    for (int i = 0; i < maze.get_size(); i++)
        {
            for (int j = 0; j < maze.get_size(); j++)
            {
                if(maze.get_location(i, j)->has_student() == 1){

                    return maze.get_location(i, j)->get_person()->get_num_skills();

                }
            }
            
        }
        return 0;
}

void Maze::display_maze(Maze& maze, int appeasement){

        /* 
         *  helpful display
         */

    cout << endl << endl << "Number of Rounds Safe from TA: " << appeasement;

    cout << endl << endl << "Number of Programming Skills: " << this->get_num_skills(maze) << endl << endl;

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            string display;

            if(this->locations[i][j]->get_display_character() == '#'){

                cout << "####" << " ";
            }

            else{
                for (int k = 0; k < 4; k++)
                {
                    cout << this->locations[i][j]->get_objects()[k];
                }
                cout << " ";
                
            }
            
        }

        cout << endl;
        
    }
    
}

void Maze::populate_ta(int size){

  

    int filled = 0;

    while(filled != 3){

        int ta_location = (rand() % (size*size));

        int row = ta_location / size;

        int col = ta_location % size;

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if(j == row && k == col && this->locations[j][k]->get_display_character() != '#' && this->locations[j][k]->get_objects()[0] != '%'){

                    if(this->locations[j][k]->get_person() != NULL){

                        delete this->locations[j][k]->get_person();

                        this->locations[j][k]->set_person(NULL);

                    }
                    this->locations[j][k]->set_has_ta(1);

                    filled++;

                    //this->locations[j][k]->set_person(new TA());
                }
            }
            
        }
        
    }
}

void Maze::populate_skill(int size){

   

    int filled = 0;

    while(filled != 6){

        int skill_location = (rand() % (size*size));

        int row = skill_location / size;

        int col = skill_location % size;

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if(j == row && k == col && this->locations[j][k]->get_display_character() != '#' && this->locations[j][k]->get_objects()[0] != '%'){

                    this->locations[j][k]->set_has_skill(1);

                    filled++;

                }
            }
            
        }
        
    }
}

void Maze::populate_student(int size){

  

    int filled = 0;

    while(filled != 1){
    
        int student_location = (rand() % (size*size));

        int row = student_location / size;

        int col = student_location % size;

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if(j == row && k == col && this->locations[j][k]->get_display_character() != '#' && this->locations[j][k]->get_objects()[0] != '%' && this->locations[j][k]->get_objects()[1] != 'T'){

                    this->locations[j][k]->set_has_student(1);

                    filled++;

                    if(this->locations[j][k]->get_person() != NULL){

                        delete this->locations[j][k]->get_person();

                        this->locations[j][k]->set_person(NULL);

                    }

                    this->locations[j][k]->set_person(new IntrepidStudent());

                }
            }
            
        }
        
    }
}


Maze::Maze(const Maze& old_m){

    this->size = old_m.size;

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            
            (*this->locations[i][j]) = (*old_m.locations[i][j]);
        }
        
    }
}

Maze& Maze::operator=(const Maze& old_m){
	this->size = old_m.size;

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            if (this->locations[i][j] != NULL)
            {
                delete this->locations[i][j];

                this->locations[i][j] = NULL;
            }
            
        }
        
    }

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            
            (*this->locations[i][j]) = (*old_m.locations[i][j]);
        }
        
    }
    


	return *this;
}

Maze::~Maze(){
    for (int i = 0; i < this->locations.size(); i++)
    {
        for (int j = 0; j < this->locations.size(); j++)
        {
            if(this->locations[i][j] != NULL)

            delete this->locations[i][j];

            this->locations[i][j] = NULL;

        }
        
    }
    
}

int Maze::get_size(){

    return this->size;

}