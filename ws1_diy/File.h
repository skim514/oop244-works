/***********************************************************************
// OOP244 Workshop 1 p2: File header file
//
// File  GPA.h
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

#ifndef SDDS_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_FILE_H

// Your header file content goes here
namespace sdds
{
	bool openFile(const char fileName[]);
	void closeFile();
	bool readName(char studentName[]);
	bool readGPA(double* gpa);
	bool readStudentNum(int* studentNum);
}

#endif