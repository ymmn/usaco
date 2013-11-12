/*
ID: abdnime1
PROG: dualpal
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

    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n;
    int s;
    int cnt;
    int found=0;
    string square;

    fin >> n >> s;

    for(int i = s+1; ; i++){
        cnt = 0;
        for(int j=2; j <= 10; j++){
            if(checkPalindrome(turnToBase(i, j))){
                cnt++;
            }
            if(cnt>=2){
                fout << i << endl;
                found++;
                break;
            }
        }
        if(found>=n){
            break;
        }
    }

    return 0;
}
