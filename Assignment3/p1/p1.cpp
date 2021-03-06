/*
*		Assignment 3 Part 1
*
*		f(x) = tan(x) and consider the finite-difference approximation
*
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;


double calculate(double x, double h);
double relativeError(double actual, double approximate);

int main(int argc, char * argv[]){

	double input = atoi(argv[1]);


	double actual = pow((1 / cos(input)), 2);


	double approximate = calculate(input, 0.01);

	double error = relativeError(actual, approximate);

	cout << "Input: " << input << endl;
	cout << "Actual: " << actual << endl;
	cout << "Approximate: " << approximate << endl;

	cout << "Relative Error: " << error << endl;

	ofstream output;
	output.open("data.dat");

	double h;


	int i = 0;
	for(double k = 1; k <= 16; k = k + 0.5){
		h = pow(10, (-k));
		approximate = calculate(input, h);
		error = relativeError(actual, approximate);

		output << k << " " << error << endl;


	}

	output.close();

	return 0;
}

double calculate(double x, double h){
	double x1 = (x + h);
	double x2 = (x - h);

	return ((tan(x1) - tan(x2)) / (2 * h));
}

double relativeError(double actual, double approximate){
	return abs(actual - approximate) / actual;
}
