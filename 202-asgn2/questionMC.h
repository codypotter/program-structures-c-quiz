/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			questionMC.h										*
*																		*
************************************************************************/
#pragma once
#include "question.h"
#include<vector>
#include<string>

class QuestionMC : public Question {
private:
	std::vector<std::string> choices;
public:
	QuestionMC();
	QuestionMC(std::string questionText, std::string answerText, bool correct, std::string multipleChoices);
	virtual ~QuestionMC();
	bool checkAnswer(std::string);
	void showQuestion();
};

