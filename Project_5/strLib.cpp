/*
* PROGRAM: CS 202 strLib Side Project
* AUTHOR: Saharath Kleips
* DATE: 02/24/2014
* PURPOSE: To provide useful c-style string helper functions
*/
#include"strLib.h"
#include<iostream>
using namespace std;

/*
* Copies a C-style string into another character array.
* PARAM: *ptrDest - The pointer of the destination character array
*	 *ptrSource - The poitner of the source character array
*/
void strCopy(char *ptrDest, const char *ptrSource)
{
	while (*ptrSource != '\0')
	{
		*ptrDest = *ptrSource;
		ptrDest++;
		ptrSource++;
	}
	*ptrDest = '\0';
}//END strCpy FUNCTION

/*
* Compares two C-style strings to see if they are exactly the same or not.
* PARAM: *ptrString - The pointer to a character array
*	 *ptrString2 - The pointer to a character array
* RETURN: True - The two C-style strings are exactly the same
*	  False - The two C-style strings are different
*/
bool strComp(const char *ptrString, const char *ptrString2)
{
	while (*ptrString2 != '\0')
	{
		if (*ptrString2 != *ptrString)
			return false;
		ptrString2++;
		ptrString++;
	}
	if (*ptrString != '\0')
		return false;
	else
		return true;
}//END strComp FUNCTION

/*
* Appends a C-style string onto another C-style string.
* PARAM: *ptrDest - The pointer of the character array to append to
*	 *ptrSource - The pointer of the character array that will be appended
*/
void strCat(char *ptrDest, const char *ptrSource)
{
	while(*ptrDest != '\0')
	{
		cout << *ptrDest << endl;
		ptrDest++;
	}

	*ptrDest = *ptrSource;
	while(*ptrSource != '\0')
	{
		*ptrDest = *ptrSource;
		ptrDest++;
		ptrSource++;
	}
}//END strCat FUNCTION

/*
* Calculates the length of a C-style string.
* RETURN: int - The length of the character array (null included)
*/
int strLen(const char *ptrString)
{
	int counter = 0;
	while(*ptrString != '\0')
	{
		counter++;
		ptrString++;
	}
	counter++; //Adds 1 for null character
	return counter;
}//END strLen FUNCTION
