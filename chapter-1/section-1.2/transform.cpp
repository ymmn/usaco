/*
ID: abdnime1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
#include <map>
using namespace std;

string *apply90Rot(string *start, int n){
    string *result = new string[n];
    for(int x=0; x < n; x++){
        result[x] = "";
        for(int y=n-1; y >= 0; y--){
            result[x] += start[y].at(x);
        }
    }
    return result;
}

string *apply180Rot(string *start, int n){
    return apply90Rot(apply90Rot(start,n),n);
}

string *apply270Rot(string *start, int n){
    return apply180Rot(apply90Rot(start,n),n);
}

string *reflect(string * start, int n){
    string *result = new string[n];
    for(int y=0; y < n; y++){
        result[y] = "";
        for(int x=n-1; x >= 0; x--){
            result[y] += start[y].at(x);
        }
    }
    return result;
}

bool checkTransform(string *ns, string *goal, int n){
    for(int i = 0; i < n; i++){
        if(ns[i]!=goal[i])
            return false;
    }
    return true;
}

int main() {

    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    int result = 7;

    fin >> n;

    string *start = new string[n];
    string *end = new string[n];

    for(int i = 0; i < n; i++){
        fin >> start[i];
        //cout << start[i] << endl;
    }
    for(int i = 0; i < n; i++){
        fin >> end[i];
        //cout << end[i] << endl;
    }

    // 90 degrees
    if(checkTransform(apply90Rot(start,n), end, n)){
        result = 1;
    } else
    // 180 degrees
    if(checkTransform(apply180Rot(start,n), end, n)){
        result = 2;
    } else
    // 270 degrees
    if(checkTransform(apply270Rot(start,n), end, n)){
        result = 3;
    } else {
        // reflect
        string *reflection = reflect(start,n);
        if(checkTransform(reflection, end, n)){
            result = 4;
        } else
        // combo
        if(checkTransform(apply90Rot(reflection,n), end, n) || checkTransform(apply180Rot(reflection,n), end, n) || checkTransform(apply270Rot(reflection,n), end, n)){
            result = 5;
        } else
        // no change
        if(checkTransform(start, end, n)){
            result = 6;
        }
    }

    fout << result << endl;
    return 0;
}
