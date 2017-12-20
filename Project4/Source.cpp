#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int fullfillVector(vector <string> &myVector);
int createTemplate(string &inputWord, string &word);
int enterLetter(string &word, string &inputWord);
int firstError();
int secondError();
int thirdError();
int fourthError();
int fifthError();
bool isWordGuessed(string &inputWord);

int main() {
	vector <string> myVector;
	srand(time(NULL));
	fullfillVector(myVector);
	string word = myVector[rand() % myVector.size()];
	cout << word << endl;

	string inputWord(word.length(), ' ');
	createTemplate(inputWord, word);
	
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == ' ') {
			inputWord[i] = ' ';
		}
	}

	cout<< inputWord << endl;

	int k = 0;
	do {
		if (!enterLetter(word, inputWord)) {
			k++;
			switch (k) {
			case 1: firstError();
				break;

			case 2: secondError();
				break;

			case 3: thirdError();
				break;

			case 4: fourthError();
				break;

			case 5: fifthError();
				break;
			}
		}
		else {
			if (isWordGuessed(inputWord)) {
				cout << "You win!" << endl;
				system("pause");
				return 0;
			}
		}
	} while (k <=5);
	cout << "You lose :(" << endl;

	system("pause");
	return 0;
}

int fullfillVector(vector <string> &myVector) {
	ifstream f1("a.txt");
	if (!f1.is_open()) {
		cout << "Error!" << endl;
		return -1;
	}
	string buf;
	while (getline(f1, buf, ',')) {
		myVector.push_back(buf);
	}
	return 0;
}

int createTemplate(string &inputWord, string &word) {
	for (int i = 0; i < word.length(); i++) {
		inputWord[i] = '_';
	}

	return 0;
}

int enterLetter(string &word, string &inputWord) {
	cout << "Enter the letter: " << endl;
	char letter;
	cin >> letter;
	bool flag = false;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == letter) {
			inputWord[i] = letter;
			flag = true;
		}

	}
	if (flag) {
		cout << inputWord << endl;
		return 1;
	}
	else {
		cout << inputWord << endl;
		return 0;
	}
}

int firstError() {
	cout << "------------------" << endl;
	cout << "|\t\t |" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;

	return 0;
}

int secondError() {
	cout << "------------------" << endl;
	cout << "|\t\t |" << endl;
	cout << "|\t\t 0" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;

	return 0;
}

int thirdError() {
	cout << "------------------" << endl;
	cout << "|\t\t |" << endl;
	cout << "|\t\t 0" << endl;
	cout << "|\t\t\\ /" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;

	return 0;
}

int fourthError() {
	cout << "------------------" << endl;
	cout << "|\t\t |" << endl;
	cout << "|\t\t 0" << endl;
	cout << "|\t\t\\ /" << endl;
	cout << "|\t\t |" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;

	return 0;
}

int fifthError() {
	cout << "------------------" << endl;
	cout << "|\t\t |" << endl;
	cout << "|\t\t 0" << endl;
	cout << "|\t\t\\ /" << endl;
	cout << "|\t\t |" << endl;
	cout << "|\t\t/ \\" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;

	return 0;
}

bool isWordGuessed(string &inputWord) {
	bool flag = true;
	for (int i = 0; i < inputWord.length(); i++) {
		if (inputWord[i] == '_') {
			flag = false;
			break;
		}
	}
	return flag;
}

/*
----------
|		 |
|		 
|
|
|
|
|
|

----------
|		 |
|		 0
|
|
|
|
|
|

----------
|		 |
|		 0
|		 |
|
|
|
|
|

----------
|		 |
|		 0
|		\|/
|		 
|
|
|
|


----------
|		 |
|		 0
|		\|/
|		 |
|
|
|
|

----------
|		 |
|		 0
|		\|/
|		 |
|		/ \
|
|
|



*/