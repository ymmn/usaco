/*
ID: abdnime1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

char charToNum(char c){
    if(c>='A' && c<='C')
        return '2';
    if(c>='D' && c<='F')
        return '3';
    if(c>='G' && c<='I')
        return '4';
    if(c>='J' && c<='L')
        return '5';
    if(c>='M' && c<='O')
        return '6';
    if(c>='P' && c<='S')
        return '7';
    if(c>='T' && c<='V')
        return '8';
    if(c>='W' && c<='Y')
        return '9';
}

bool isValidChar(char c, char num){
    return charToNum(c)==num;
}

int main() {

    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream ftext("dict.txt");
    string num;
    string name;
    vector<string> res;
    bool valid;

    fin >> num;

    while(!ftext.eof()){
        ftext >> name;
        if(num.size()!=name.size()){
            continue;
        }
        valid = true;
        for(int i = 0; i < num.size(); i++){
            if(!isValidChar(name.at(i), num.at(i))){
                valid = false;
                break;
            }
        }
        if(valid) res.push_back(name);
    }

    for(int i = 0; i < res.size(); i++){
        fout << res.at(i) << endl;
    }

    if(res.size()==0)
        fout << "NONE" << endl;
    //fout << result << endl;
    return 0;
}
