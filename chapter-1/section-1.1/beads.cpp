/*
ID: abdnime1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int moveBack(int n, int cnt){
    if(cnt==0)
        return n-1;
    else
        return cnt-1;
}

int moveForward(int n, int cnt){
    if(cnt==(n-1))
        return 0;
    else
        return cnt+1;
}


int main() {

    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int best = 0;
    int currentBest;
    int n;
    int start;
    int end;
    int cnt = 0;
    char colorA;
    char colorB;
    string beads;

    fin >> n;
    fin >> beads;

    for(int i = 0; i < n; i++){
        currentBest = 0;
        start = i;
        end = moveBack(n, start);
        colorA = beads.at(start);
        colorB = beads.at(end);

        // take off the first bead and move forward
        currentBest++;
        cnt = moveForward(n, start);
        while(cnt!=start && (beads.at(cnt)==colorA || beads.at(cnt)=='w')){
            currentBest++;
            cnt = moveForward(n, cnt);
        }
        if(cnt==start){ // looped all around, so already found best solution
            best = currentBest;
            break;
        }

        // take off first bead and move backwards
        currentBest++;
        cnt = moveBack(n, end);
        while(cnt!=end && (beads.at(cnt)==colorB || beads.at(cnt)=='w' || colorB=='w')){
            currentBest++;
            if(colorB=='w')
                colorB = beads.at(cnt);
            cnt = moveBack(n, cnt);
        }

        //cout << "at pos " << i << ", the best sol is " << currentBest << endl;
        if(currentBest > best){
            best = currentBest;
        }
    }
    if(best > n)
        best = n;
    fout << best << endl;
    return 0;
}
