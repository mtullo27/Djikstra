#include <limits.h>
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
  int min = INT_MAX, min_index;
  for(int i = 0; i<v.size(); i++){
    if(inc[i] == 0 && v[i] < min)
      min = v[i], min_index = i;
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

//helper method for printing vectors
void printVector(vector<int> v){
  for(int i = 0; i<v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

//implementation taking a matrix and a starting node
//first vector is the distances and second vector is the order
vector<vector<int>> djikstra(vector<vector<int>> v, int s){
  //return vector
  vector<vector<int>> ret;
  int small = INT_MAX;
  //vector to keep track of visited nodes. 0 is false, 1 is true
  vector<int> visited;
  //vector to keep track of order visited. pushes back node number when visited
  vector<int> order;
  //vector to keep track of distances from source node
  vector<int> distance;
  for(int i = 0; i<v[s].size(); i++)
    visited.push_back(0), distance.push_back(INT_MAX);
  distance[s] = 0;
  for(int i = 0; i < v.size(); i++){
    cout<< "===========STEP " << i << " START============" << endl; 
    //finding the min distance to next node
    small = min(distance, visited);
    //Marking the next node as visited
    visited[small] = 1;
    order.push_back(small);
    //changing the distance vectors
    for(int j = 0; j< v.size(); j++){
      //updating the distance only if it has not been visited yet, if there is a means of getting to the new node, and the new edge weight is less than its current edge weight
      if(visited[j] == 0 && v[small][j] != INT_MAX && distance[small] != INT_MAX && distance[small] + v[small][j] < distance[j])
	distance[j] = distance[small] + v[small][j];
    }
    //printing in an easy to read format
    cout << "Visited Nodes: ";
    printVector(order);
    cout << endl;
    cout<< "Distances to each Node: ";
    printVector(distance);
    cout << endl;
  }
  ret.push_back(distance);
  ret.push_back(order);
  return ret;
}

int main(){
    //setting up the inputs
  vector<vector<int>> in1;
  vector<vector<int>> in2(7);
  vector<vector<int>> in3;
  //Test a in vector in1, b in in2 and c in in3
  in2[0] = {0, 2, 4, INT_MAX, INT_MAX, 7, INT_MAX};
  in2[1] = {2, 0, 3, 3, INT_MAX, INT_MAX, INT_MAX};
  in2[2] = {4, 3, 0, 4, 3, 8, INT_MAX};
  in2[3] = {INT_MAX, 3, 4, 0, 6, INT_MAX, INT_MAX};
  in2[4] = {INT_MAX, INT_MAX, 3, 6, 0, 6, 8};
  in2[5] = {7, INT_MAX, 8, INT_MAX, 6, 0, 12};
  in2[6] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 8, 12, 0};
  cout<<"===========INPUT MATRIX=========="<<endl;
  printMatrix(in2);
  cout<< endl;
  vector<vector<int>> temp = djikstra(in2, 1);
  return 0;
}
