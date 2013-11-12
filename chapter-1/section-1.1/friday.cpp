/*
ID: abdnime1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;

    int daysOfMonth [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int freqs[7] = {0};
    int year = 1900;
    int month = 0;
    int dayOfWeek = 2;
    int bump;
    for(int j = 0; j < n; j++){

        for(int i = 0; i < 12; i++){
            // get to the 13th
            //cout << "Month " << month << " starts on Day " << dayOfWeek << endl;
            dayOfWeek = (dayOfWeek + 12) % 7;
            //cout << "On Month " << month << ", 13th is on Day " << dayOfWeek << endl;
            freqs[dayOfWeek] += 1;

            // get the starting day of the next month
            bump = daysOfMonth[month] - 13 + 1;
            if(month==1){ // it's february!
                bump += ( (year%4==0 && year%100!=0) || (year%100==0 && year%400==0) ) ? 1 : 0; // account for leap years
            }
            dayOfWeek = (dayOfWeek + bump) % 7;

            // go to next month
            month++;
            month %= 12;
        }
        year++;
    }
    int total = 0;
    for(int i = 0; i < 7; i++){
        total += freqs[i];
        if(i==6)
            fout << freqs[i] << endl;
        else
            fout << freqs[i] << " ";
    }
    assert(total==(12*n));
    //cout << res << endl;
    return 0;
}
