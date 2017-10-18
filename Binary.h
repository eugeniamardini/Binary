//----------------------------------------------------------------------------
//Binary.h
//Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
//DESCRIPTION: Class Binary implements an abstract data type for binary numbers
//             of arbitrary length. The data type is implemented using an array 
//			   of boolean values (1 0) to represent the binary number. 
//FUNCTIONALITY: 
//	--converts an integer into a binary and vice versa
//	--handles both positive and negative numbers
//	--can intake user data
//	--adds and subtracts binary numbers
//	--compares 2 binary numbers among themselves
//	--outputs the binary number to the console w/o spaces and leading zeroes;
//	  if binary number is negative the negative sign is also output to the con
//	  sole.
//	--returns a bit at specific index
//	--sets a bit to a true/false at a specific index
//	--can flip/toggle the value of the bit at a particular index
//ASSUMPTIONS:
//	--user must enter an integer when using >>
//	--in <, a binary numner is displayed with no spaces between or surrounding 
//	  the bits (with a preceding “–” if it is negative),w/o leading zeros.
//	--the out of bounds index will be ignored, or in getBit() be returned as 0
//	--error messages are not printed
//-----------------------------------------------------------------------------

#pragma once
#include <iostream>
using namespace std;

class Binary
{
//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class Binary
// Preconditions: a binary number must be of size at least 0
// Postconditions: the binary number's values (bits) are sent to the output w/o
//spaces and leading zeroes; with preceding "-", if negative; w/o endl;
friend ostream& operator<<(ostream& , const Binary &);

//-----------------------------  >>  ----------------------------------------
// Overloaded input operator for class Binary
// Preconditions: none
// Postconditions: a new binary number is created, based on the user's integer 
//input
friend istream& operator>>(istream & , Binary &);

public:
	//-------------------------------Default Constructor-----------------------
	//Preconditions:none
	//Postconditions: a new binary object of size 1 created with the bit value 
	//false(0) and a positive sign
	Binary();

	//-----------------------------Constructor---------------------------------
	//Preconditions:none
	//Postconditions: a new binary object is created
	Binary(int );

	//--------------------------------Copy Constructor-------------------------
	//makes a copy of a binary number
	//Preconditions: none
	//Postconditions: num is copied into *this
	Binary(const Binary &);

	//-----------------------------------setBit(int )--------------------------
	//sets a binary number's bit to true
	//Preconditions: none
	//Postconditions:the value of a bit gets set to true if its index is valid;
	//if index is out of bounds, the change of a bit doesn't occur
	void setBit(int );

	//-----------------------------------clearBit(int )------------------------
	//sets a binary number's bit to false (o)
	//Preconditions: none
	//Postconditions: the value of a bit gets set to 0 if its index is valid;
	//if index is out of bounds, the change of a bit doesn't occur
	void clearBit(int );

	//-----------------------------------getBit(int )--------------------------
	//returns a value of a bit
	//Preconditions: none
	//Postconditions:a value of a bit at a specific index gets returned; 0
	//is returned if index is out of bounds
	bool getBit(int ) const;

	//-------------------------------toggleBit( int )--------------------------
	//switches the value of a bit from 0 to 1, or vice versa
	//Preconditions: none
	//Postconditions: the value of a bit at a specific index gets switched to  
	//opposite value
	void toggleBit (int );

	//----------------------------  +  ----------------------------------------
	//adds two binary numbers together
	//Preconditions: none
	//Postconditions: the binary numbers are nonverted into integers, added, &
	//converted back to binary format; the new binary number gets created and 
	//assigned the value of a sum.
	Binary operator+(const Binary &);

	//----------------------------  -  ----------------------------------------
	//subtracts two binary numbers 
	//Preconditions: none
	//Postconditions: the binary numbers are converted into integers,subtracted
	//&converted back to binary format; the new binary number gets created and 
	//assigned the value of the difference.
	Binary operator-(const Binary &);

	//----------------------------------  =  ----------------------------------
	//assignes one binary number to another (making a deep copy)
	//Preconditions: none
	//Postconditions: num is copied into *this
	const Binary& operator=(const Binary &);

	//------------------------------  +=  -------------------------------------
	//adds the binary num to *this
	//Preconditions: none
	//Postconditions: current object = current object + parameter 
	const Binary& operator+= (const Binary & );

	//------------------------------  -=  -------------------------------------
	//subtracts the binary num from *this
	//Preconditions: none
	//Postconditions: current object = current object - parameter (num)
	const Binary& operator-=(const Binary &);

	//------------------------------  ==  -------------------------------------
	// Determine if two binary numbers are equal.
	// Preconditions: two binary numbers are of at least size 0
	// Postconditions: true is returned if the numbers are the same size, sign,
	// & values at the same indeces; the leading zeroes are ignored.
	bool operator==(const Binary &) const;

	//------------------------------  !=  -------------------------------------
	// Determine if two binary numbers are not equal.
	// Preconditions: none
	// Postconditions:false is returned if the numbers are the same size, sign,
	// & values at the same indeces; the leading zeroes are ignored.
	bool operator!=(const Binary &) const;

	//---------------------------- Destructor ---------------------------------
	// Destructor for class Binary
	// Preconditions: this array points to memory on the heap
	// Postconditions: array "binary" is deallocated
	~Binary();

private: 
	int size;
	bool *binary;
	bool negative;

	//-------------------------------toBinary----------------------------------
	//converts an integer into a binary number
	//Preconditions: none
	//Postconditions: an integr is converted into a binary; size and sign of 
	//the binary number get initialized
	void toBinary(int );

	//--------------------------------empty------------------------------------
	//deallocates the array
	//Preconditions: none
	//Postconditions: the dynamic array is deallocated
	void empty();
};

