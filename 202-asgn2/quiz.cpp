/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			quiz.cpp											*
*																		*
************************************************************************/
#include"quiz.h"
#include"questionTF.h"
#include"questionMC.h"
#include<fstream>
#include<sstream>
#include<iostream>

Quiz::Quiz(std::string dataFile) {
	filename = dataFile;
	std::vector<Question*> temp(0);
	questions = temp;
}

Quiz::Quiz() {
	std::vector<Question*> temp(0);
	questions = temp;
}

Quiz::~Quiz() {
	// no dynamically allocated memory in class
}

bool Quiz::loadQuestions(std::string dataFileName) {
	std::fstream questionFile;
	std::string line;

	try {
		questionFile.open(dataFileName.c_str());
	} catch (const std::exception& e) {
		std::cerr << e.what();
		filenameIsValid = false;
	}
	
	if (questionFile.is_open()) {
		while (std::getline(questionFile, line)) {
			std::istringstream ss(line);
			std::string token;
			std::string type;
			std::string level;
			std::string questionText;
			std::string answerText;
			std::string multipleChoices;
			int index = 0;
			bool correct = false;
			
			while (std::getline(ss, token, '|')) {
				switch (index) {
				case 0:
					type = token;
					break;
				case 1:
					level = token;
					break;
				case 2:
					questionText = token;
					break;
				case 3:
					if (type != "M") {
						answerText = token;
					} else {
						multipleChoices = token;
						std::getline(ss, token, '|');
						answerText = token;
					}
					break;
				default:
					break;
				}
				index++;
			}

			if (type == "T") {
				// true/false question
				Question * newQuestion = new QuestionTF(questionText, answerText, correct);
				questions.push_back(newQuestion);
			} else if (type == "M") {
				// multiple choice question
				Question * newQuestion = new QuestionMC(questionText, answerText, correct, multipleChoices);
				questions.push_back(newQuestion);
			} else if (type == "S") {
				// standard question
				Question * newQuestion = new Question(questionText, answerText, correct);
				questions.push_back(newQuestion);
			} else {
				// unidentified question type
				// TODO: handle this error
				return false;
			}
		}
	} else {
		std::cerr << "Error opening file." << std::endl;
		filenameIsValid = false;
		return false;
	}
	return true;
}

void Quiz::dumpQuestions() {
	for (int i = 0; i < questions.size(); i++) {
		questions[i]->showQuestion();
		questions[i]->showAnswer();
		std::cout << std::endl;
	}
}

int Quiz::deliverQuiz() {
	int correctAnswers = 0;
	std::string userAnswer = "";

	for (int i = 0; i < questions.size(); i++) {
		questions[i]->showQuestion();
		std::getline(std::cin, userAnswer);

		if (questions[i]->checkAnswer(userAnswer)) {
			correctAnswers++;
		}
		delete questions[i];
		std::cin.ignore(999, '\n');     // a fancy wait for enter
	}
	return correctAnswers;
}

int Quiz::totalQuestions() {
	return questions.size();
}

int Quiz::getNumCorrect()
{
	return 0;
}

int Quiz::getNumIncorrect()
{
	return 0;
}
