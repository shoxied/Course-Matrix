#include <iostream>
#include <vector>
#include <exception>
#include "Matrix.h"

using namespace std;

int main()
{
	Matrix f({ {5, 6}, {7, 8} }), d({ {1, 2}, {3, 4} }), a;
	int x;

	cout << "matrix f";
	f.Print();
	cout<<endl << "matrix d";
	d.Print();

	cout << endl << "assignment";
	a = f;
	a.Print();

	cout << endl << "summation with accumulation";
	try {
		a += f;
	}
	catch (const exception& error) {
		cout << error.what();
	}
	a.Print();

	cout << endl << "summation with accumulation with number";
	a += 2;
	a.Print();

	cout << endl << "subtraction with accumulation";
	try {
		a -= f;
	}
	catch (const exception& error) {
		cout << error.what();
	}
	a.Print();

	cout << endl << "subtraction with accumulation with number";
	a -= 2;
	a.Print();

	cout << endl << "summation";
	try {
		a = f + d;
	}
	catch (const exception& error) {
		cout << error.what();
	}
	a.Print();

	cout << endl << "subtraction";
	try {
		a = f - d;
	}
	catch (const exception& error) {
		cout << error.what();
	}
	a.Print();

	cout << endl << "matrix minus number";
	a = d - 4;
	a.Print();

	cout << endl << "number minus matrix";
	a = 4 - d;
	a.Print();

	cout << endl << "matrix plus number";
	a = d + 4;
	a.Print();

	cout << endl << "number plus matrix";
	a = 4 + d;
	a.Print();

	cout << endl << "multiplication";
	try {
		a = f * d;
	}
	catch (const exception& error) {
		cout << error.what();
	}
	a.Print();

	cout << endl << "multiplication of a matrix by a number";
	a = d * 4;
	a.Print();

	cout << endl << "multiply the number by the matrix";
	a = 4 * d;
	a.Print();

	cout << endl << "increment post";
	f++;
	f.Print();

	cout << endl << "decrement post";
	f--;
	f.Print();

	cout << endl << "increment pref";
	++f;
	f.Print();

	cout << endl << "decrement pref";
	--f;
	f.Print();

	cout << endl << "Comparison for equality";
	if (f == d)
		cout << endl << "TRUE";
	else
		cout << endl << "FALSE" << endl;

	cout << endl << "Comparison for inequality";
	if (f != d)
		cout << endl << "TRUE" << endl;
	else
		cout << endl << "FALSE";

	cout << endl << "segmentation";
	try {
		a = f / d;
	}
	catch (const exception& error) {
		cout << error.what();
	}
	a.Print();

	cout << endl << "segmentation of a matrix by a number";
	a = d / 4;
	a.Print();

	cout << endl << "segmentation the number by the matrix";
	a = 4 / d;
	a.Print();

	cout << endl << "inverse matrix";
	a = d.Inverse();
	a.Print();

	cout << endl << "taking an element";
	x = f.Element(1, 0);
	cout << endl << x << endl;

	cout << endl << "amount of elements";
	cout << endl << f.Size() << endl;

	cout << endl << "transposed matrix";
	a = f.Transpose();
	a.Print();

	return 0;
}