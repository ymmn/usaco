/*
ID: abdnime1
PROG: milk2
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
#include <vector>
using namespace std;

typedef struct Milktime Milktime;
struct Milktime {
    int start;
    int end;
};

Milktime *milktimes;
int n;

void
addMilktime(int start, int end, int i)
{
    milktimes[i].start = start;
    milktimes[i].end = end;
}

bool myfunction (Milktime i,Milktime j) {
     return (i.start<j.start);
}

int main() {

    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int longestMilking = 0;
    int longestStatic = 0;
    int milStart = 0;
    int milEnd = 0;
    int curStart;
    int statStart;
    int statEnd;
    int s, e;

    fin >> n;
    milktimes = new Milktime[n];
    string *lines = new string[n];
    int *start = new int[n];
    int *end = new int[n];

    for(int i = 0; i < n; i++){
        //fin >> start[i];
        //fin >> end[i];
        fin >> s >> e;
        addMilktime(s,e,i);
        //getline(fin, lines[i]);
       // cout << start[i] << " " << end[i] << endl;
    }

    vector<Milktime> v(milktimes, milktimes+n);
    sort (v.begin(), v.end(), myfunction);

    for(int i = 0; i < n; i++){
  //      cout << v.at(i).start << " " << v.at(i).end << endl;
        start[i] = v.at(i).start;
        end[i] = v.at(i).end;
    }


    for(int i = 0; i < n; i++){
        if(i==0 || !(start[i] >= milStart && start[i] <= milEnd)){
            if(i==0){
                longestMilking = end[i] - start[i];
                statStart = end[i];
            }
            if(milEnd-milStart > longestMilking)
                longestMilking = milEnd - milStart;
            milStart = start[i];
            milEnd = end[i];
            statEnd = start[i];
            if(statEnd-statStart > longestStatic)
                longestStatic = statEnd - statStart;
            statStart = end[i];
        } else{
            if(end[i]>milEnd){
                milEnd = end[i];
                statStart = end[i];
            }
        }


    }
    fout << longestMilking << " " << longestStatic << endl;
    return 0;
}
