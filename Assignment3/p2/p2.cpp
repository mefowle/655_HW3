/*
*		Assignment 3 Part 2
*	
*		Consider the infinite series
*
*		infinite		1
*			SUM			 ---
*		 n = 1			n
*
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]){

	float sum = 0;
	float temp;

	for(float	n = pow(10, 2); n < pow(10, 3); n++){
		if(n !=0){
			temp = 1/n;
			sum = sum + temp;
	
			cout << n << " " << sum << endl;
		}
	}

	
	return 0;
}
