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
int min(vector<int> v, vector<int> inc){
  int min = -1, min_index;
  for(int i = 0; i<v.size(); v++){
    if(inc[i] == 0 && v[i] < min)
      min = v[i], min_index = v;
  }
  return min_index;
}

//helper function to print vectors
void printMatrix(vector<vector<int>> v){
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j <v[i].size(); j++){
      if (j == 0)
	cout << "[" << i << "] ";
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

//implementation taking a matrix and a starting node
vector<vector<int>> djikstra(vector<vector<int>> v, int s){
  int small = 0;
  //vector to keep track of visited nodes. 0 is false, 1 is true
  vector<int> visited;
  //vector to keep track of order visited. pushes back node number when visited
  vector<int> order;
  //vector to keep track of distances from source node
  vector<int> distance
  for(int i = 0; i<v[s].size; i++)
    visited.push_back(0), distance.push_back(INT_MAX);
  for(int i = 0; i<v[s].size(); i++){
    small = min(small, v[s][i]);
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
