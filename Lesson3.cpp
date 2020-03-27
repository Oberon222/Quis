#include <iostream>
#include <string>
#include <fstream>
#include "Quiz.h"

using namespace std;

int main() {
	Init();
	int action = 0;
	do
	{
		cout << "1. Add new quiz" << endl;
		cout << "2. Show and pass quizes" << endl;
		cout << "3. Exit" << endl;
		cout << "Select action ->_";
		cin >> action;
		switch (action)
		{
		case 1:
		{
			AddQuiz();
			break;
		}
		case 2:
		{
			ShowQuizes();
			PassQuiz();
			break;
		}
		case 3:
		{
			cout << "Goodbye" << endl;
			break;
		}
		default:
		{
			cout << "Error: Select action from list!" << endl;
		}
		
		}

	} while (action !=3);


	system("pause");
	return 0;
}