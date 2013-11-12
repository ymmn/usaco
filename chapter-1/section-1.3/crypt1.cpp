/*
ID: abdnime1
PROG: crypt1
LANG: C++
*/

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> digits;
int res;

bool checkResultValid(int check){
	int place = 1;
	while(check/place!=0){
		place *= 10;
	}
	place /= 10;	
	for(int i = 0; i < 3; i++){
		int dig = (check / place) % 10;
		bool found = false;
		//cout << "checking " << check << ": digit " << dig << endl;
		for(int j = 0; j < digits.size(); j++){
			if(digits.at(j)==dig)
				found = true;
		}
		if(!found){
			return false;
		}
		place /= 10;
	}
	//cout << check << " passed!" << endl;
	return true;
}

void perform(int mul1, int mul2){
	//cout << "checking " << mul1 << " and " << mul2 << endl;
	int pp1 = mul1 * (mul2 % 10);
	int pp2 = (mul1) * (mul2 - (mul2 % 10));
	if(pp1 < 100 || pp1 > 1000) return; 
	if(pp2 < 1000 || pp2 > 10000) return;
	if(checkResultValid(pp1) && checkResultValid(pp2/10) && checkResultValid(pp1 + pp2)){
		//cout << mul1 << " and " << mul2 << " passed" << endl;
		res++;
	} 
}

int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int n;
	int digs[10];
	int poss[1000];
	int pp1, pp2;

	fin >> n;
	int i = 0;
	while(!fin.eof()){
		fin >> digs[i++];
	}

	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				poss[cnt++] = 100*digs[i] + 10*digs[j] + digs[k];
			}
		}
	}
	digits = vector<int>(digs, digs+n);

	res = 0;
	int len = n*n*n;
	for(int i = 0; i < len; i++){
		for(int j = 0; j < n*n; j++){
			perform(poss[i], poss[j]%100);
		}
	}


	fout << res << endl;

	return 0;
}