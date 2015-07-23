//Ford Tang
//46564602
//ICS 45C
//Project 2

#include "cleanup.h"

void cleanup(graded_artifacts *grades)
{
    delete[] grades->total_points;
    delete[] grades->weight;
    delete[] grades->grade_a;
    delete[] grades->grade_b;
    delete[] grades->grade_c;
    delete[] grades->grade_d;
}

void cleanup(student *student)
{
    delete[] student->scores;
    delete[] student->grades;
    delete student;
}

void cleanup(unsigned int number_of_students, student **students)
{
    for (int i = 0; i < number_of_students; i++)
    {
        cleanup(students[i]);
    }
}
