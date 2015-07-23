//Ford Tang
//46564602
//ICS 45C
//Project 2

#include "printout.h"

void printTotalScores(unsigned int number_of_students, graded_artifacts *grades, student **students)
{
    std::cout << "TOTAL SCORES" <<std::endl;
    for (int i = 0; i < number_of_students; i++)
        std::cout << students[i]->student_id << " " << students[i]->name << " " << students[i]->total_score << std::endl;
}

void printCutpointSets(unsigned int number_of_students, unsigned int set, graded_artifacts *grades, student **students)
{
    std::cout << "CUTPOINT SET " << set + 1 << std::endl;
    for (int i = 0; i < number_of_students; i++)
        std::cout << students[i]->student_id << " " << students[i]->name << " " << students[i]->grades[set] << std::endl;
}
