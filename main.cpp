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
vector<vector<int>> getMatrix(vector<string> v){
    vector<vector<int>> ret;
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            string s = v[i];
            if(s[j].compare(" ")!=0){
                ret[i].push_back(stoi(s[j]));
            }
        }
    }
}


int main(int argc, char* argv[]){
    //opening the input file
    ifstream infile;
    string file;
    infile.open(argv[1]);
    vector<string>lines;
    while(getline(infile, file))
        lines.push_back(file);
    vector<vector<int>> matrix = getMatrix(lines);
    return 0;
}
