/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			questionMC.cpp										*
*																		*
************************************************************************/
#include "questionMC.h"
#include<sstream>
#include<iostream>

QuestionMC::QuestionMC() {
	questionText = "";
	answerText = "";
	correct = false;
	std::vector<std::string> temp(0);
	choices = temp;
}

QuestionMC::QuestionMC(std::string questionText, std::string answerText, bool correct, std::string multipleChoices) {
	this->questionText = questionText;
	this->answerText = answerText;
	this->correct = correct;

	std::istringstream ss(multipleChoices);
	std::string token;
	while (std::getline(ss, token, ':')) {
		choices.push_back(token);
	}
}


QuestionMC::~QuestionMC() {
	questionText = '\0';
	answerText = '\0';
	correct = '\0';
}

bool QuestionMC::checkAnswer(std::string userAnswer) {
	char formattedUserAnswer = userAnswer.at(0);
	formattedUserAnswer = tolower(formattedUserAnswer);

	char formattedCorrectAnswer = answerText.at(0);
	formattedCorrectAnswer = tolower(formattedCorrectAnswer);

	if (formattedCorrectAnswer == formattedUserAnswer) {
		markCorrect();
		std::cout << "Correct! Great Job!" << std::endl;
		return true;
	} else {
		std::cout << "Sorry, the answer is " << answerText << '.' << std::endl;
		return false;
	}
}

void QuestionMC::showQuestion() {
	char choiceIndex = 'a';
	std::cout << questionText << "? (Multiple Choice)" << std::endl;
	for (int i = 0; i < choices.size(); i++) {
		std::cout << "    " << choiceIndex << ". " << choices[i] << std::endl;
		choiceIndex++;
	}
}
