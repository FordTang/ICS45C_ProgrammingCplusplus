//Ford Tang
//46564602
//ICS 45C
//Project 2

#ifndef _student
#define _student
#include <string>

struct student
{
    unsigned int student_id;
    char grade_option;
    std::string name;
    double* scores; //pointer to array of unsigned int
    double total_score;
    std::string* grades;
};

#endif
