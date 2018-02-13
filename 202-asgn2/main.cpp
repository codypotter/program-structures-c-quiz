/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			main.cpp											*
*																		*
************************************************************************/
#include"quiz.h"
#include"question.h"
#include<iostream>
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
	Quiz quiz;
	bool isDumped = false;
	std::string fileName = "";

	// can't handle more than one file or option
	if (argc > 3) {
		std::cerr << "Invalid arguments. Correct usage: quiz [filename] [options]" << std::endl;
		return 0;
	}

	// look for the dump option in the arguments
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-d")) {
			isDumped = true;
		} else {
			fileName = argv[i];
		}
	}

	// user didn't supply a filename
	if (fileName == "") {
		std::cerr << "Invalid arguments. Correct usage: quiz [filename] [options]" << std::endl;
	}

	std::cout << "Cody Potter" << std::endl;
	std::cout << "Hope your brain is warmed up, because it's quiz time!!!" << std::endl;
	std::cout << "After each answer is displayed, press enter to see the next question." << std::endl << std::endl;

	int correctAnswers = 0;
	if (!isDumped) {
		quiz.loadQuestions(fileName);
		correctAnswers = quiz.deliverQuiz();
	} else {
		quiz.loadQuestions(fileName);
		quiz.dumpQuestions();
	}

	int percent = 100 * correctAnswers / quiz.totalQuestions();

	std::cout << "You got " << correctAnswers << " of " << quiz.totalQuestions() << " correct: " << percent << "%. ";

	if (percent == 100.0) {
		std::cout << "Great Job!" << std::endl;
	} else {
		std::cout << "Better study some more!" << std::endl;
	}

	return 68;
}