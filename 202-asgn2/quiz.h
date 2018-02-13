/************************************************************************
*	Program:		Quiz												*
*	Description:	This program quizes the user with a short answer,	*
*					true/false, multiple choice format					*
*	Author:			Cody Potter											*
*	Date:			February 6 2018										*
*	Compilation:	make												*
*	File:			quiz.h												*
*																		*
************************************************************************/
#pragma once

#include"question.h"
#include<vector>

class Quiz {
private:
	std::vector<Question*> questions;
	std::string filename;
	bool filenameIsValid;
	int numCorrect;
	int numIncorrect;
public:
	Quiz(std::string);
	Quiz();
	~Quiz();
	bool loadQuestions(std::string dataFileName);
	void dumpQuestions();
	int deliverQuiz();
	int totalQuestions();
	int getNumCorrect();
	int getNumIncorrect();
};
