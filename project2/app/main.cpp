//Ford Tang
//46564602
//ICS 45C
//Project 2

//#include <iostream>
#include "getInput.h"
#include "graded_artifacts.h"
#include "student.h"
#include "printout.h"
#include "cleanup.h"

int main()
{
    graded_artifacts* grades = new graded_artifacts;
    
    getGradedArtifacts(grades);
    //std::cout << "got artifacts" << std::endl;

    unsigned int number_of_students;
    std::cin >> number_of_students;
    
    student** students = new student*[number_of_students];
    
    getStudents(number_of_students, grades, students);
    //std::cout << "got students" << std::endl;

    getScores(number_of_students, grades, students);
    //std::cout << "got scores" << std::endl;

    printTotalScores(number_of_students, grades, students);

    getCutpointSetAmount(number_of_students, grades, students);
    //std::cout << "cutpoints setup" << std::endl;

    for (int i = 0; i < grades->cutpoint_sets; i++)
    {
        getCutpoints(number_of_students, i, grades, students);
        printCutpointSets(number_of_students, i, grades, students);
    }
    //std::cout << "got cutpoints" << std::endl;
    
    cleanup(grades);
    cleanup(number_of_students, students);

    delete grades;
    delete[] students;

    return 0;
}

