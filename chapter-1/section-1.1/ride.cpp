/*
ID: abdnime1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet;
    string group;
    string res;
    fin >> comet >> group;
    int cometProd = 1;
    int groupProd = 1;
    for(int i = 0; i < comet.size(); i++){
        cometProd *= ( ((int)comet.at(i)) - ((int)'A') + 1);
    }
    for(int i = 0; i < group.size(); i++){
        groupProd *= ((int)group.at(i)) - ((int)'A') + 1;
    }
   	if((groupProd%47)==(cometProd%47)){
        res = "GO";
   	} else{
        res = "STAY";
   	}
    fout << res << endl;
    return 0;
}
