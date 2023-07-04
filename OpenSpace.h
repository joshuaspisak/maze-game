/******************************************************
** Program: openspace.h
** Author: Joshua Spisak
** Date: 2/20/2023
** Description: openspace header
** Input:
** Output:
******************************************************/

#ifndef OPENSPACE_H
#define OPENSPACE_H

#include <iostream>
#include <vector>

#include "MazeLocation.h"
#include "IntrepidStudent.h"
#include "TA.h"
#include "Instructor.h"

using namespace std;

class OpenSpace : public MazeLocation{

private:
    MazePerson* person;
    vector<TA*> tas;
    vector<char> objects;
    char display_character = '-';
    bool student_check;
    int ta_check;
    bool instructor_check;
    bool skill_check;

public:
    OpenSpace();

    void set_has_student(bool);
    bool has_student();

    void set_has_ta(int);
    bool has_ta();

    void set_has_instructor(bool);
    bool has_instructor();

    void set_has_skill(bool);
    bool has_skill();

    vector<char> get_objects();

    bool is_occupiable();

    char get_display_character();

    MazePerson* get_person();

    vector<TA*> get_tas();

    void set_person(MazePerson*);



    OpenSpace(const OpenSpace&);

    OpenSpace& operator=(const OpenSpace&);

    ~OpenSpace();

};

#endif