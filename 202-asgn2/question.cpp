/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			question.cpp										*
*																		*
************************************************************************/
#include"question.h"
#include<sstream>
#include<iostream>

Question::Question() {
	questionText = "";
	answerText = "";
	correct = false;
}

Question::Question(std::string questionText, std::string answerText, bool correct) {
	this->questionText = questionText;
	this->answerText = answerText;
	this->correct = correct;
}


Question::~Question() {
	questionText = '\0';
	answerText = '\0';
	correct = '\0';
}

void Question::showQuestion() {
	std::cout << questionText << '?' << std::endl;
}

bool Question::checkAnswer(std::string userAnswer) {
	if (userAnswer == answerText) {
		markCorrect();
		std::cout << "Correct! Great Job!" << std::endl;
		return true;
	}
	else {
		std::cout << "Sorry, the answer is " << answerText << '.' << std::endl;
		return false;
	}
}

void Question::showAnswer() {
	std::cout << "Answer: " << answerText << std::endl;
}

void Question::markCorrect() {
	correct = true;
}