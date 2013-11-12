/*
ID: abdnime1
PROG: barn1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_STALLS 200
#define MAXPLANKS 50



typedef struct Plank Plank;
struct Plank{
    int start;
    int end;
};

Plank planks[MAXPLANKS];

int solve(int *occupied, int m, int c){
    // loop over all possible extra breaks
    if(m==1){
        planks[0].start = occupied[0];
        planks[0].end = occupied[c-1];
        return occupied[c-1] - occupied[0];
    }
    solve(occupied, m-1, c);
    int maxSaved = 0;
    int splitAtIndex;
    int plankToReplace;
    for(int p = 0; p < m; p++){

    }
    for(int i = 1; i < c; i++){
        if(occupied[i] - occupied[i-1] > maxSaved){
            maxSaved = occupied[i] - occupied[i-1];
            splitAtIndex = i-1;
        }
    }
    planks[1].end = planks[0].end;
    planks[0].end = occupied[splitAtIndex];
    planks[1].start = occupied[splitAtIndex + 1];

    return 0;
}

int gaps[MAX_STALLS];

void buildGaps(vector<int> occupied, int c){
    for(int i = 0; i < c-1; i++){
        gaps[i] = occupied.at(i+1) - occupied.at(i);
    }
}

int getSol(int init, int m, int c, vector<int> v){
    int res = init;
    for(int i = 0; i < m-1; i++){
        res -= v.at(v.size() - i - 1);
        //cout << "subtracting " << v.at(v.size()-i-1) << endl;
    }
    return res + m;

}

int main(){
    ifstream fin ("barn1.in");
    ofstream fout ("barn1.out");
    int m, s, c;
    int occupied[MAX_STALLS];

    fin >> m >> s >> c;

    for(int i = 0; i < c; i++){
        fin >> occupied[i];
       // cout << occupied[i] << endl;
    }

    solve(occupied, 2, c);
    vector<int> v1(occupied, occupied+c);
    sort(v1.begin(), v1.end());
    buildGaps(v1, c);

    vector<int> v(gaps, gaps+c-1);
    sort(v.begin(), v.end());

    int init = v1.at(c-1)-v1.at(0);
    int sol;
    if(m > v.size()){
        sol = c;
    } else{
        sol = getSol(init, m, c, v);
    }

    //cout << "Solution: " << sol <<  endl;
    for(int i = 0; i < c-1; i++){
        //cout << "Plank " << i << " starts at " << planks[i].start << " and ends at " << planks[i].end << endl;
        //cout << "Gap " << i << ": " << v.at(i) << endl;
    }

    fout << sol << endl;
    //cout << m << " " << s << " " << c << endl;
    return 0;
}
