/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			questionTF.cpp										*
*																		*
************************************************************************/
#include "questionTF.h"
#include<iostream>

QuestionTF::QuestionTF() {
	questionText = "";
	answerText = "";
	correct = false;
}

QuestionTF::QuestionTF(std::string questionText, std::string answerText, bool correct) {
	this->questionText = questionText;
	this->answerText = answerText;
	this->correct = correct;
}


QuestionTF::~QuestionTF() {
	questionText = '\0';
	answerText = '\0';
	correct = '\0';
}

void QuestionTF::showAnswer() {
	std::cout << "Answer: " << answerText << std::endl;
}

void QuestionTF::showQuestion() {
	std::cout << questionText << ". (True/False)" << std::endl;
}

bool QuestionTF::checkAnswer(std::string userAnswer) {
	char firstLetterOfAnswer = convertTrueFalseStringToChar(answerText);
	char firstLetterOfUserAnswer = convertTrueFalseStringToChar(userAnswer);

	if (firstLetterOfAnswer == firstLetterOfUserAnswer) {
		markCorrect();
		std::cout << "Correct! Great Job!" << std::endl;
		return true;
	} else {
		std::cout << "Sorry, the answer is " << answerText << '.' << std::endl;
		return false;
	}
}

char QuestionTF::convertTrueFalseStringToChar(std::string trueFalse) {
	char firstLetterOfTrueFalse = trueFalse.at(0);
	if (firstLetterOfTrueFalse == 'T' || firstLetterOfTrueFalse == 't') {
		return 't';
	} else if (firstLetterOfTrueFalse == 'F' || firstLetterOfTrueFalse == 'f') {
		return 'f';
	} else {
		std::cerr << "Bad answer format. For true, enter true. For false, enter false." << std::endl;
		return '0';
	}
}