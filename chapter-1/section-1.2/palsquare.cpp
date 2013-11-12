/*
ID: abdnime1
PROG: palsquare
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


bool checkPalindrome(string s){
    for(int i = 0; i < s.size(); i++){
        if(s.at(i)!=s.at(s.size()-1-i))
            return false;
    }
    return true;
}

int raise(int i, int j){
    if(j==0) return 1;
    if(j==1) return i;
    return i*raise(i,j-1);
}

char digitToChar(int i){
    if(i<10)
        return i + '0';
    else
        return (i-10) + 'A';
}
string turnToBase(int i, int base){
    string res = "";
    int max_digit = 1;
    int curTotal = base;
    while(true){
        if(curTotal>i)
            break;
        curTotal *= base;
        max_digit++;
    }

    //cout << "max digit for " << i << " is " << max_digit << endl;
    int val;
    int digit;
    for(int j = max_digit-1; j >= 0; j--){
        val = raise(base,j);
        digit = i/val;
        //cout << "turning " << (i/val) << " to a char: " << digitToChar(i/val) << " and val is " << val << endl;
        res += digitToChar(digit);
        i -= digit*val;
    }
    return res;
}

int main() {

    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    string square;

    fin >> base;

    for(int i = 1; i <= 300; i++){
        square = turnToBase(i*i, base);
        if(checkPalindrome(turnToBase(i*i, base)))
            fout << turnToBase(i,base) << " " << square << endl;
    }

    return 0;
}
