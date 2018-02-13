/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			questionTF.h										*
*																		*
************************************************************************/
#pragma once
#include "question.h"
#include<string>

class QuestionTF : public Question {
public:
	QuestionTF();
	QuestionTF(std::string questionText, std::string answerText, bool correct);
	virtual ~QuestionTF();
	void showAnswer();
	void showQuestion();
	bool checkAnswer(std::string);
	char convertTrueFalseStringToChar(std::string trueFalse);
};

