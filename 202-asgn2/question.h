/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			question.h											*
*																		*
************************************************************************/
#pragma once
#include<string>

class Question {
protected:
	std::string questionText;
	std::string answerText;
	bool correct;
public:
	Question();
	Question(std::string questionText, std::string answerText, bool correct);
	~Question();
	virtual void showQuestion() = 0;
	virtual bool checkAnswer(std::string) = 0;
	virtual void showAnswer();
	void markCorrect();
};