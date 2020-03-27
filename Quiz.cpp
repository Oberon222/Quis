#include "Quiz.h"
#include <fstream>

Quiz* quizes;
int countQuizes=0;
const int countQuectionInQuiz = 5;
const string fileName = "Quizes.txt";

void InsertQuiz(Quiz quiz)
{
	Quiz* tmp = new Quiz[countQuizes + 1];
	for (int i = 0; i < countQuizes; i++) {
		tmp[i] = quizes[i];
	}
	tmp[countQuizes] = quiz;
	countQuizes++;
	quizes = new Quiz[countQuizes];
	for (int i = 0; i < countQuizes; i++)
	{
		quizes[i] = tmp[i];
	}
	delete[]tmp;
}

void PassQuiz()
{
	int selectQuiz = 0;
	int score = 0;

	cout << "Enter number quiz for start pass -> ";
	cin >> selectQuiz;
	selectQuiz--;

	cout << endl;
	cout << "You sterted passing " << quizes[selectQuiz].Title << endl;

	for (int i = 0; i < countQuectionInQuiz; i++)
	{
		cout << quizes[selectQuiz].questions[i].questionText << endl;
		string tmpAnswer = " ";
		cout << "Your answer -> ";
		cin >> tmpAnswer;

		if (quizes[selectQuiz].questions[i].trueAnswer == tmpAnswer) {
			cout << "It's true answer! (+20 score)" << endl;
			score += 20;

		}
		else {
			cout << "It's false answer ;(" << endl;
		}

	}
	cout << "Your result: " << score << " // 100" << endl;
}

void Init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == true) {
		while (!fin.eof())
		{
			Quiz getQuiz;
			fin >> getQuiz.Title;
			if (getQuiz.Title != "") {
				for (int i = 0; i < countQuectionInQuiz; i++) {
					fin >> getQuiz.questions[i].questionText;
					fin >> getQuiz.questions[i].trueAnswer;

				}
			}
			else {
				break;
			}
			InsertQuiz(getQuiz);
		}

	}
	else {
		cout << "Error" << endl;
	}
}

void AddQuiz()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen = true) {

		Quiz* tmp = new Quiz[countQuizes + 1];
		for (int i = 0; i < countQuizes; i++) {
			tmp[i] = quizes[i];
		}

		cout << "Enter quiz title -> ";
		cin >> tmp[countQuizes].Title;

		for (int i = 0; i < countQuectionInQuiz; i++)
		{
			cout << "Enter " << i + 1 << "/5 question ->";
			cin >> tmp[countQuizes].questions[i].questionText;

			cout << "Enter correct answer for this question";
			cin >> tmp[countQuizes].questions[i].trueAnswer;

		}

		fout << tmp[countQuizes].Title << endl;
		for (int i = 0; i < countQuectionInQuiz; i++)
		{
			fout << tmp[countQuizes].questions[i].questionText << endl;
			fout << tmp[countQuizes].questions[i].trueAnswer << endl;


		}
		countQuizes++;
		quizes = new Quiz[countQuizes];
		for (int i = 0; i < countQuizes; i++)
		{
			quizes[i] = tmp[i];
		}
		delete[]tmp;
	}

	else {
		cout << "Error" << endl;
	}

}

void ShowQuizes()
{
	for (int i = 0; i < countQuizes; i++)
	{
		cout << i + 1 << ". " << quizes[i].Title << endl;

	}
	cout << endl;
}


