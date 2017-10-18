 //HW1.cpp
 //This is a simple driver to perform basic testing on student code for CSS 343 HW1.
 //If your code compiles with this driver, it should compile with the (much more extensive)
 //driver that I will be testing with.
 //Author: Clark Olson

#include "Binary.h"
#include <iostream>
using namespace std;

// main: driver for HW1
// preconditions: 	None (note that the preconditions are run-time issues, not compile-time issues)
// postconditions: 	Outputs results to the console window and returns 0.
//					Should NOT crash if Binary class is correct.
int main()
{
	Binary a(30), b(12), c(b), f(4), d=-13, x, y = x + 1;
	cout << a << "  " << b << " " << c <<" "<< d<< " x" << x<< "  y" << y <<"  x" << x<<endl;
	
	//b.setBit(1);
	b.toggleBit(3);
	cout<< b <<" ";
	cout << b << " " <<f<<endl;
	cout << ( (b == f) ? "b == f" : "b != f") << endl << endl;
	//b.clearBit(1);
	b.toggleBit(2);
	cout<<b;
	b.toggleBit(2);
	b.toggleBit(3);
	cout << "  " << b;
	cout << "Enter integer to be converted to binary:  ";
	cin >> a;

	cout << "The binary representation of this number is: " << endl;
	cout << a << endl;
	cout << "The 4th bit (four bits away from bit 0) is: " << endl;
	cout << a.getBit(4) << endl << endl;

	cout << "Compute c = a + b  c = 101010 + 1100 " << a << " + "<<b << endl;
	c = a + b;
	cout << "c = " << c << "a "<<a << " b " <<b<< endl;
	cout << "Compute d = a + b - c" << endl;
	d = a + b - c;
	cout << "d = " << d << "a "<<a<<"b "<<b<<"c "<<c<< endl << endl;

	cout << "Does a == c? " << endl;
	cout << ( (a == c) ? "a == c" : "a != c") << endl << endl;
	cout << a << "  a" << b << "  b" << c <<"  c"<< " d " << d<< " x" << x<< "  y" << y <<"  x" << x<<endl;
   	cout << "Test assignment operators" << endl;

   	x = c = d = d;   
		y += a -= b += b;
   	cout << "x = " << x << "    y = " << y << endl << endl;


   	a.setBit(-1);			// handle bad input
	a.setBit(3);			// set 3rd bit (three over from bit zero)
	a.setBit(1000);			// set 1000th bit; handle as desired, but don't crash
	a.clearBit(3);			// clear 3rd bit
	a.clearBit(10000);		// clear 10000th bit
	a.toggleBit(3);			// toggle 3rd bit

	return 0;
}