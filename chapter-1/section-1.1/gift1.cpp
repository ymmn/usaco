/*
ID: abdnime1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

int toNum(string s){
    return atoi(s.c_str());
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string name;
    string receiver;
    string giver;
    string money;
    string numReceivers;
    string line;
    getline(fin, line, '\n');
    int NP = toNum(line);
    string pplNames [NP];
    map<string, int> ppl;
    for(int i = 0; i < NP; i++){
        getline(fin, name, '\n');
        ppl[name] = 0;
        pplNames[i] = name;
    }
    while(getline(fin, giver, '\n')){
        getline(fin, money, ' ');
        getline(fin, numReceivers, '\n');
        //cout << giver << endl << toNum(money) << " " << toNum(numReceivers) << endl;
        for(int i = 0; i < toNum(numReceivers); ++i){
            getline(fin, receiver, '\n');
        //    cout << receiver << endl;
            ppl[giver] -= toNum(money)/toNum(numReceivers);
            ppl[receiver] += toNum(money)/toNum(numReceivers);
        }
       // if(toNum(numReceivers)>0)
        //    ppl[giver] += (toNum(money)) % (toNum(numReceivers));
    }
    for(int i = 0; i < NP; ++i){
        fout << pplNames[i] << " " << ppl[pplNames[i]] << endl;
    }
    //fout << res << endl;
    return 0;
}
