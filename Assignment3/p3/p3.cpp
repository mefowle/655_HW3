/*
*		Assignment 3 Part 3
*	
*		Calculate the 1-norm and the infinity norm
*
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <ctime>


using namespace std;

int oneNorm(int *matrix, int rows, int columns);
int infinityNorm(int *matrix, int rows, int columns);

int main(int argc, char *argv[]){

	int rows, columns;
	rows = 100;
	columns = 100;
	
	clock_t start, end;
	double time;
	
	int *test = new int[rows * columns];
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			test[(i*rows)+j] = i+j;
		}
	}
	
	
	start = clock();
	cout << "1-norm: " << oneNorm(test, rows, columns) << endl;
	end = clock();
	time = (end - start)/(double) CLOCKS_PER_SEC;
	cout << "Time for 1-norm: " << time << endl;
	
	start = clock();
	cout << "infinity-norm: " << infinityNorm(test, rows, columns) << endl;
	end = clock();
	time = (end - start)/(double) CLOCKS_PER_SEC;
	cout << "Time for infinity-norm: " << time << endl;

	return 0;
}

int oneNorm(int *matrix, int rows, int columns){

	int sums[columns];
	int sum;
	int max = 0;
	
	//Outer for will move across matrix
	for(int j = 0; j < columns; j++){
		sum = 0;
		//inner for will move down row
		for(int i = 0; i < rows; i++){
			sum = sum + matrix[(j*columns)+i];
		}
		sums[j] = sum;
	}
	
	for(int i = 0; i < columns; i++){
		if(max < sums[i]){
			max = sums[i];
		}
	}
	
	return max;
	
}

int infinityNorm(int *matrix, int rows, int columns){

	int sums[rows];
	int sum;
	int max = 0;
	
	//Outer for will move down matrix
	for(int i = 0; i < rows; i++){
		sum = 0;
		//inner for will move across row
		for(int j = 0; j < columns; j++){
			sum = sum + matrix[(i*rows)+j];
		}
		sums[i] = sum;
	}
	
	for(int i = 0; i < rows; i++){
		if(max < sums[i]){
			max = sums[i];
		}
	}
	
	return max;

}
