//Ford Tang
//46564602
//ICS 45C
//Project 2

#include "getInput.h"

std::string getName()
{
    std::string name;
    std::getline(std::cin, name);
    return name.substr(1, name.size() - 1);
}

void getGradedArtifacts(graded_artifacts *grades)
{
    std::cin >> grades->number;
    grades->total_points = new unsigned int[grades->number];
    grades->weight = new unsigned int[grades->number];

    for (int i = 0; i < grades->number; i++)
        std::cin >> grades->total_points[i];

    for (int i = 0; i < grades->number; i++)
        std::cin >> grades->weight[i];
}

void getStudents(unsigned int number_of_students, graded_artifacts *grades, student **students)
{
    for (int i = 0; i < number_of_students; i++)
    {
        students[i] = new student;
        std::cin >> students[i]->student_id;
        std::cin >> students[i]->grade_option;
        students[i]->name = getName();
        students[i]->scores = new double[grades->number];
        for (int j = 0; j < grades->number; j++)
            students[i]->scores[j] = 0;
        students[i]->total_score = 0;
    }
}

void getScores(unsigned int number_of_students, graded_artifacts *grades, student **students)
{
    unsigned int number_of_scores;
    std::cin >> number_of_scores;

    for (int i = 0; i < number_of_scores; i++)
    {
        unsigned int id;
        std::cin >> id;
        bool found = false;
        for (int i = 0; i < number_of_students; i++)
        {
            if (id == students[i]->student_id)
            {
                found = true;
                for (int j = 0; j < grades->number; j++)
                {
                    double score;
                    std::cin >> score;
                    students[i]->scores[j] = calculateTotal(score, grades->total_points[j], grades->weight[j]);
                    students[i]->total_score += students[i]->scores[j];
                }
            }
        }
        if (found == false)
        {
            int junk;
            for (int j = 0; j < grades->number; j++)
                std::cin >> junk;
        }
    }
}

void getCutpointSetAmount(unsigned int number_of_students, graded_artifacts *grades, student **students)
{
    std::cin >> grades->cutpoint_sets;
    
    grades->grade_a = new double[grades->cutpoint_sets];
    grades->grade_b = new double[grades->cutpoint_sets];
    grades->grade_c = new double[grades->cutpoint_sets];
    grades->grade_d = new double[grades->cutpoint_sets];

    for (int i = 0; i < number_of_students; i++)
        students[i]->grades = new std::string[grades->cutpoint_sets];
}

void getCutpoints(unsigned int number_of_students, unsigned int set, graded_artifacts *grades, student **students)
{
    std::cin >> grades->grade_a[set];
    std::cin >> grades->grade_b[set];
    std::cin >> grades->grade_c[set];
    std::cin >> grades->grade_d[set];

    calculateGrades(number_of_students, set, grades, students);
}
