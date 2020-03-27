#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Question {
	string questionText;
	string trueAnswer;

};

struct Quiz {
	string Title;
	Question questions[5];

};

void Init();
void AddQuiz();
void ShowQuizes();
void InsertQuiz(Quiz quiz);
void PassQuiz();


