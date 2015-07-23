//Ford Tang
//46564602
//ICS 45C
//Project 2

#ifndef _getInput
#define _getInput
#include <iostream>
#include <string>
#include "student.h"
#include "graded_artifacts.h"
#include "calculate.h"

std::string getName();

void getGradedArtifacts(graded_artifacts *grades);

void getStudents(unsigned int number_of_students, graded_artifacts *grades, student **students);

void getScores(unsigned int number_of_students, graded_artifacts *grades, student **students);

void getCutpointSetAmount(unsigned int number_of_students, graded_artifacts *grades, student **students);

void getCutpoints(unsigned int number_of_students, unsigned int set, graded_artifacts *grades, student **students);

#endif
