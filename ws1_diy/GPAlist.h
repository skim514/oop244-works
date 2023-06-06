/***********************************************************************
// OOP244 Workshop 1 p2: GPAlist header file
//
// File  GPAlist.h
// Version 1.0
// Date  winter 2023
// Author Suna Kim
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

/*
NAME: Suna Kim
E-MAIL: skim514@myseneca.ca
STUDENT ID: 104690227
DATE: Jan 22nd, 2023
*/

#ifndef SDDS_GPALIST_H
#define SDDS_GPALIST_H

namespace sdds { //같은 네임스페이스안에 있지 않으면 struct라고 써주어야 함. 같은 네임스페이스면 struct 안써도 됨.

	bool gpaQuery(const char* fileName); // compare the user input value and data. And print it.
	void gpaSorting(struct GPA* student, int arrayLength);
	bool studentGPA(const GPA* student, const char option, double userGPA);
	void displayStudent(const GPA* student);
	void displayOptionGPA(const char option, double inputGPA);
}

#endif