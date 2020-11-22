#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector> 
#include <streambuf>

using namespace std;

//basic helper function to determine which value is smaller
int min(int a, int b){
    return (a > b)? a:b;
}

//helper function to print vectors
void printMatrix(vector<vector<int>> v){
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j <v[i].size(); j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
int main(){
    //setting up the inputs
  vector<vector<int>> in1;
  vector<vector<int>> in2(7);
  vector<vector<int>> in3;
  //Test a in vector in1, b in in2 and c in in3
  in2[0] = {0, 2, 4, -1, -1, 7, -1};
  in2[1] = {2, 0, 3, 3, -1, -1, -1};
  in2[2] = {4, 3, 0, 4, 3, 8, -1};
  in2[3] = {-1, 3, 4, 0, 6, -1, -1};
  in2[4] = {-1, -1, 3, 6, 0, 6, 8};
  in2[5] = {7, -1, 8, -1, 6, 0, 12};
  in2[6] = {-1, -1, -1, -1, 8, 12, 0};
  printMatrix(in2);
  return 0;
}
