//Ford Tang
//46564602
//ICS 45C
//Project 2

#include "calculate.h"
//#include <iostream>

double calculateTotal(double student_score, double total, double weight)
{
    //std::cout << "student_score " << student_score << " total " << total << " weight " << weight << std::endl;
    return (student_score/total) * weight;
}

void calculateGrades(unsigned int number_of_students, unsigned int set, graded_artifacts *grades, student **students)
{
    for (int i = 0; i < number_of_students; i++)
    {
        if (students[i]->grade_option == 'G')
        {
            if (students[i]->total_score < grades->grade_d[set])
                students[i]->grades[set] = 'F';
            else if (students[i]->total_score < grades->grade_c[set])
                students[i]->grades[set] = 'D';
            else if (students[i]->total_score < grades->grade_b[set])
                students[i]->grades[set] = 'C';
            else if (students[i]->total_score < grades->grade_a[set])
                students[i]->grades[set] = 'B';
            else
                students[i]->grades[set] = 'A';
        }

        else
        {
            if (students[i]->total_score < grades->grade_c[set])
                students[i]->grades[set] = "NP";
            else
                students[i]->grades[set] = 'P';
        }
    }
}
