/*
*		Assignment 3 Part 6
*
*		Write a program to determine the orbit parameters a, b, c, d, e.
*
*   ay^2 + bxy + cx + dy + e = x^2
*
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <iomanip>


using namespace std;

struct pivot{
  int x;
  int y;
};

int main (void ){

  double observations[2][10];

  double matrix[10][6];

  double in;

  ifstream input;
  input.open("input");

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 10; j++){
      input >> in;
      observations[i][j] = in;
    }
  }


  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 6; j++){
      if(j == 0){
        matrix[i][j] = observations[1][i] * observations[1][i];   //y^2
      }
      if(j == 1){
        matrix[i][j] = observations[1][i] * observations[0][i];   //y * x
      }
      if(j == 2){
        matrix[i][j] = observations[0][i];                        //x
      }
      if(j == 3){
        matrix[i][j] = observations[1][i];                        //y
      }
      if(j == 4){
        matrix[i][j] = 1;
      }
      if(j == 5){
        matrix[i][j] = observations[0][i] * observations[0][i];   //x^2
      }
    }
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 6; j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
/*
  double divisor;
  pivot point;
  point.x = 0;
  point.y = 0;


  for(int k = 0; k < 5; k++){
    for(int i = 0; i < 5; i++){
      divisor = matrix[i][point.y] / matrix[point.x][point.y];
      if(i != point.y){
        for(int j = k; j < 6; j++){
          matrix[i][j] = matrix[i][j] + (-divisor * matrix[point.x][j]);
        }
      }
    }
    point.x++;
    point.y++;
  }

  cout << fixed;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
      cout << setprecision(4) << matrix[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << endl;

  point.x = 0;
  point.y = 0;

  double multiplier;

  for(int i = 0; i < 5; i++){
    multiplier = 1 / matrix[point.x][point.y];
    for(int j = 0; j < 6; j++){
      matrix[i][j] = matrix[i][j] * multiplier;
    }
    point.x++;
    point.y++;
  }


  cout << fixed;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
      cout << setprecision(4) << matrix[i][j] << " ";
    }
    cout << endl;
  }

  double a, b, c, d, e;

  a = matrix[0][5];
  b = matrix[1][5];
  c = matrix[2][5];
  d = matrix[3][5];
  e = matrix[4][5];

  cout << endl;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  cout << "e: " << e << endl;

  if(((a * observations[1][5]) + (b * observations[0][5] * observations[1][5]) + (c * observations[0][5]) + (d * observations[1][5]) + e) != (observations[0][5] * observations[0][5])){
    cout << "Not correct\n";
  }
  else{
    cout << "Worked!!" << endl;
  }
  */

}
