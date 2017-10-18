//----------------------------------------------------------------------------
//Binary.cpp
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

#include "Binary.h"
#include <iostream>
using namespace std;

//-------------------------------Default Constructor---------------------------
//Preconditions:none
//Postconditions: a new binary object of size 1 is created with the bit value 
//false(0) and a positive sign
Binary::Binary()
{
	toBinary(0);
}

//-----------------------------Constructor-------------------------------------
//Preconditions:none
//Postconditions: a new binary object is created
Binary::Binary(int num)
{
	toBinary(num);
} 

//--------------------------------Copy Constructor----------------------------
//makes a copy of a binary number
//Preconditions: none
//Postconditions: num is copied into *this
Binary::Binary(const Binary &num)
{
	*this = num;
}

//-----------------------------------setBit(int )------------------------------
//sets a binary number's bit to true
//Preconditions: none
//Postconditions: the value of a bit gets set to true if its index is valid;
//if index is out of bounds, the change of a bit doesn't occur
void Binary::setBit(int i)
{
	if(i < 0 || i > this->size)
	{
		return;
	}
	else
	{
		binary[i] = true;
	}
	
}

//-----------------------------------clearBit(int )----------------------------
//sets a binary number's bit to false (o)
//Preconditions: none
//Postconditions: the value of a bit gets set to false(0) if its index is valid;
//if index is out of bounds, the change of a bit doesn't occur
void Binary::clearBit(int i)
{
	if(i < 0 || i > this->size)
	{
		return;
	}
	else
	{
		binary[i] = false;
	}
}

//-----------------------------------getBit(int )------------------------------
//returns a value of a bit
//Preconditions: none
//Postconditions: a value of a bit at a specific index gets returned; 0(false)
//is returned if index is out of bounds
bool Binary::getBit(int i) const
{
	if(i < 0 || i > this->size)
	{
		return false;
	}
	else
	{
		return binary[i];
	}
}

//-------------------------------toggleBit( int )------------------------------
//switches the value of a bit from 0 to 1, or vice versa
//Preconditions: none
//Postconditions: the value of a bit at a specific index gets switched to the 
//opposite value
void Binary::toggleBit(int i)
{
	if (i >= 0 && i <= this->size)
	{
		if (this->getBit(i) == false)
		{
			this->setBit(i);
		}
		else 
		{
			this->clearBit(i);
		}
	}
	else
	{
		return;
	}
}

//----------------------------  +  -------------------------------------------
//adds two binary numbers together
//Preconditions: none
//Postconditions: the binary numbers are nonverted into integers, added, and
//converted back to binary format; the new binary number gets created and 
//assigned the value of a sum.
Binary Binary::operator+(const Binary &num)
{
	Binary bin;
	int num1 = 0, num2 = 0;
	for (int i = this->size-1; i >= 0; i--)
	{
		if (this->getBit(i) == 1)
		{
			num1=((num1*2) + 1);
		}
		else
		{
			num1 = (num1*2);
		}
	}

	if (this->negative == true)
	{
		num1 = -num1;
	}

	for (int i = num.size-1; i >= 0; i--)
	{
		if (num.getBit(i) == 1)
		{
			num2 = ((num2*2) + 1);
		}
		else
		{
			num2 = (num2*2);
		}
	}

	if (num.negative == true)
	{
		num2 = -num2;
	}

	int sumOfnums = num1 + num2;
	bin.toBinary(sumOfnums);
	return bin;
}

//----------------------------  -  --------------------------------------------
//subtracts two binary numbers 
//Preconditions: none
//Postconditions: the binary numbers are converted into integers, subtracted, &
//converted back to binary format; the new binary number gets created and 
//assigned the value of the difference.
Binary Binary::operator-(const Binary &num)
{
	Binary bin;
	int num1 = 0, num2 = 0;
	for (int i = this->size-1; i >= 0; i--)
	{
		if (this->getBit(i) == 1)
		{
			num1 = (num1*2 + 1);
		}
		else
		{
			num1 = (num1*2);
		}
	}

	if (this->negative == true)
	{
		num1 = -num1;
	}

	for (int i = num.size; i >= 0;i--)
	{
		if (num.getBit(i) == 1)
		{
			num2=(num2*2 + 1);
		}
		else
		{
			num2 = (num2*2);
		}
	}

	if (num.negative == true)
	{
		num2 = -num2;
	}
	int diffOfnums = num1 - num2;
	bin.toBinary(diffOfnums);
	return bin;
}

//----------------------------------  =  --------------------------------------
//assignes one binary number to another (making a deep copy)
//Preconditions: none
//Postconditions: num is copied into *this
const Binary& Binary::operator=(const Binary &num)
{
	if (this == &num)
	{
		return *this;
	}
	else
	{
		if (this->size > 0)
		{
			this->empty();
			
		}
		this->size = num.size;
		this->negative=num.negative;
		binary = new bool[this->size];
		for (int i = 0; i < num.size; i++)
		{
			this->binary[i] = num.binary[i];
		}
		return *this;
	}
	return *this;
}

//------------------------------  +=  -----------------------------------------
//adds the binary num to *this
//Preconditions: none
//Postconditions: current object = current object + parameter 
const Binary& Binary::operator+=(const Binary &num)
{
	*this = *this + num;
	return *this;
}

//------------------------------  -=  -----------------------------------------
//subtracts the binary num from *this
//Preconditions: none
//Postconditions: current object = current object - parameter (num)
const Binary& Binary::operator-=(const Binary &num)
{
	*this = *this - num;
	return *this;
}

//------------------------------  ==  -----------------------------------------
// Determine if two binary numbers are equal.
// Preconditions: two binary numbers are of at least size 0
// Postconditions: true is returned if the numbers are the same size, sign, and 
//values at the same indeces; the leading zeroes are ignored.
bool Binary::operator==(const Binary &num) const
{
	bool equal = false;
	int val1 = this->size-1;
	int count1 = 0, count2 =0;
	while (this->getBit(val1) == false && val1 >= 0)
	{
		val1--;
		count1++;
	}

	int curSize1 = this->size - count1;
	int val2 = num.size-1;
	while (num.getBit(val2) == false && val2 >= 0)
	{
		val2--;
		count2++;
	}

	int curSize2 = num.size - count2;
	if (curSize1 == curSize2 && this->negative == num.negative)
	{
		while (curSize1 >0 
			   && this->getBit(curSize1-1) == num.getBit(curSize2-1))
		{
			curSize1--;
			equal = true;
		}
	}		
	else
	{
		equal = false;
	}
	return equal;
}

//------------------------------  !=  -----------------------------------------
// Determine if two binary numbers are not equal.
// Preconditions: none
// Postconditions: false is returned if the numbers are the same size, sign, and 
//values at the same indeces; the leading zeroes are ignored.
bool Binary::operator!=(const Binary &num) const
{
	return !(*this == num);
}

//-------------------------------toBinary--------------------------------------
//converts an integer into a binary number
//Preconditions: none
//Postconditions: an integr is converted into a binary; size and sign of the
//binary number get initialized
void Binary::toBinary(int num)
{
	int remainder;
	int numCopy = num; 
	int count = 0;
	if (num == 0)
	{
		size = 1;
		binary = new bool[size];
		this->binary[count] = false;
		negative = false;
	}
	else
	{
		while (numCopy != 0)
		{
			numCopy /= 2;
			count++;
		}

		if (num < 0)
		{
			this->negative = true;
		}
		else
		{
			this->negative = false;
		}

		binary = new bool[count];
		this->size = count;
		int index = 0;
		while (num != 0)
		{
			remainder = num % 2;
			if (remainder == 0)
			{
				binary[index] = false;
			}
			else
			{
				binary[index] = true;
			}
			num /= 2;
			index++;
		}
	}
}

//--------------------------------empty----------------------------------------
//deallocates the array
//Preconditions: none
//Postconditions: the dynamic array is deallocated
void Binary::empty ()
{
	delete [] binary;
	binary = NULL;
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class Binary
// Preconditions: a binary number must be of size at least 0
// Postconditions: the binary number's values (bits) are sent to the output w/o
//spaces and leading zeroes; with preceding "-", if negative; w/o endl;
ostream& operator<<(ostream &output, const Binary &num)
{
	int val = (num.size)-1;
	while (num.getBit(val) == false && val >= 0)
	{
		val--;
	}
	
	if( val == -1)
	{
		output << false;
	}
	else
	{
		if (num.negative == true)
		{
			output<<"-";
		}
		for (int i = val; i >= 0; i--)
		{
			output << num.getBit(i);
		}
	}
	return output;
}

//-----------------------------  >>  ----------------------------------------
// Overloaded input operator for class Binary
// Preconditions: none
// Postconditions: a new binary number is created, based on the user's integer 
//input
istream& operator>>(istream &input, Binary &num)
{
	int x;
	input >> x;
	Binary binNum (x);
	num = binNum;
	return input;
}

//---------------------------- Destructor -------------------------------------
// Destructor for class Binary
// Preconditions: this array points to memory on the heap
// Postconditions: array "binary" is deallocated
Binary::~Binary()
{
	this->empty();
}
