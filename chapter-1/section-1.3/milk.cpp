/*
ID: abdnime1
PROG: milk
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

typedef struct MilkSale MilkSale;
struct  MilkSale{
    int price;
    int amt;
};

bool myfunction (MilkSale i,MilkSale j) {
     return (i.price<j.price);
}

int main() {

    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n, m;
    int total = 0;
    fin >> n >> m;

    MilkSale *sales = new MilkSale[m];

    for(int i = 0; i < m; i++){
        MilkSale s;
        fin >> s.price >> s.amt;
        sales[i] = s;
        //cout << sales[i].amt << " " << sales[i].price << endl;
    }

    vector<MilkSale> v(sales, sales+m);
    sort (v.begin(), v.end(), myfunction);

   // for(int i = 0; i < m; i++){
   //     cout << v.at(i).amt << " " << v.at(i).price << endl;
   // }

    int curFarmer = 0;
    int spent = 0;
    while(true){
        if(n==total) break;
        if(n-total <= v.at(curFarmer).amt){
            spent += (n-total)*v.at(curFarmer).price; // only buy needed
            break;
        } else{
            spent += v.at(curFarmer).amt*v.at(curFarmer).price; // buy out
            total += v.at(curFarmer).amt;
            curFarmer++;
        }
    }

    fout << spent << endl;
    return 0;
}
