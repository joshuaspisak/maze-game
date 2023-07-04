/******************************************************
** Program: openspace.cpp
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: openspace class
** Input:
** Output:
******************************************************/

#include "OpenSpace.h"

OpenSpace::OpenSpace(){

        /* 
         *  creates default maze display
         */

    for (int i = 0; i < 4; i++)
    {
        this->objects.push_back('-');
    }
    
    this->person = NULL;

    this->instructor_check = 0;
    this->ta_check = 0;
    this->student_check = 0;
    this->skill_check = 0;
}

bool OpenSpace::is_occupiable(){

    if(this->student_check == 1 || this->ta_check >= 1 || this->instructor_check == 1 || this->skill_check == 1){

        return 0;

    }
}

char OpenSpace::get_display_character(){

    return this->display_character;

}

/*********************************************************************
** Function: set_has_student
** Description: sets the openspace objecct to having a student
** Parameters: boolean
** Pre-Conditions:
** Post-Conditions: student boolean true
*********************************************************************/

void OpenSpace::set_has_student(bool has){

    this->student_check = has;

    if(this->student_check == 1){

        this->objects[0] = '*';

    }
    else{
        this->objects[0] = '-';
    }
}
bool OpenSpace::has_student(){
    return this->student_check;
}

/*********************************************************************
** Function: set_has_ta
** Description: makes the object have a ta
** Parameters: int
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/

void OpenSpace::set_has_ta(int change){
    this->ta_check += change;


    if(this->ta_check > this->tas.size()){

        for (int i = this->tas.size(); i < this->ta_check; i++)
        {
            this->tas.push_back(new TA);
        }
    }

    if(this->ta_check < this->tas.size()){

        /* 
         *  loops through ta vector
         */

        for (int i = this->tas.size(); i > this->ta_check; i--)
        {
            if(this->tas[i-1] != NULL){

                delete this->tas[i-1];

                this->tas[i-1] = NULL;

            }
            this->tas.pop_back();
        }
    }
    for (int i = 0; i < this->ta_check; i++)
    {
        this->objects[i+1] = 'T';
    }
    for (int i = this->ta_check+1; i < 4; i++)
    {
        this->objects[i] = '-';
    }
}
bool OpenSpace::has_ta() {

    return this->ta_check;

}

void OpenSpace::set_has_instructor(bool has){

    this->instructor_check = has;

    this->objects[0] = '%';

}
bool OpenSpace::has_instructor(){

    return this->instructor_check;

}

void OpenSpace::set_has_skill(bool has){

    this->skill_check = has;

    if(this->skill_check == 1){

        this->objects[0] = '$';

    }
}
bool OpenSpace::has_skill(){

    return this->skill_check;

}

vector<char> OpenSpace::get_objects(){

    return this->objects;

}

OpenSpace::~OpenSpace(){

    if(this->person != NULL){

        delete this->person;

        this->person = NULL;

    }

    this->objects.clear();

        /* 
         *  loops through ta vector
         */


    for (int i = 0; i < this->tas.size(); i++)

    {
        if(this->tas[i] != NULL){

            delete this->tas[i];

            this->tas[i] = NULL;

        }
    }
}

OpenSpace& OpenSpace::operator=(const OpenSpace& old_os){
	this->objects = old_os.objects;
	this->display_character = old_os.display_character;
	this->student_check = old_os.student_check;
    this->ta_check = old_os.ta_check;
    this->instructor_check = old_os.instructor_check;
    this->skill_check = old_os.skill_check;

	//free memory first
	if (this->person != NULL){

		delete [] this->person;

		this->person = NULL;

	}
	//deep copy
	(*(this->person)) = (*(old_os.person));

    for (int i = this->tas.size() - 1; i >= 0; i--)
    {

        if(this->tas[i] != NULL){

            delete this->tas[i];

            this->tas[i] = NULL;
        }

        this->tas.pop_back();
    }

    for (int i = 0; i < this->ta_check; i++)
    {
        this->tas.push_back(new TA());

        (*this->tas[i]) = (*old_os.tas[i]);
    }
    

	return *this;
}

OpenSpace::OpenSpace(const OpenSpace& old_os){
	this->objects = old_os.objects;
	this->display_character = old_os.display_character;
	this->student_check = old_os.student_check;
    this->ta_check = old_os.ta_check;
    this->instructor_check = old_os.instructor_check;
    this->skill_check = old_os.skill_check;

	//deep copy
	(*(this->person)) = (*(old_os.person));

    for (int i = 0; i < this->ta_check; i++)
    {
        this->tas.push_back(new TA());

        (*this->tas[i]) = (*old_os.tas[i]);

    }
}

MazePerson* OpenSpace::get_person(){
    return this->person;
}

void OpenSpace::set_person(MazePerson* person){
    this->person = person;
}

vector<TA*> OpenSpace::get_tas(){
    return this->tas;
}