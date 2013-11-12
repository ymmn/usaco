/*
ID: abdnime1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
 

using namespace std;

char par[20000]={'\0'};
int Len;
 
inline bool isAlpha(char c)
{
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}
inline char toLower(char c)
{
    return c|=32;
}
 
// if pal, then return size of it,else 0;
// works for both odd/even
int findpal(int &i, int &j)
{
    int odd=i==j;
    int len=0;
    for( ;i>=0&&j<Len;)
    {
        if( isAlpha(par[i]) && isAlpha(par[j]) )
        {
            if( toLower(par[i]) == toLower(par[j] ) )
            {i--;j++; len++;}
            else break;
        }
        else 
        {   if(!isAlpha(par[i])) i--;
            if(!isAlpha(par[j])) j++;
        }
    }
    i++;j--;
 
    return len*2-odd;
    
}
 
int main() {
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out"); 
    
    //open file 
    string par1;
    while(!fin.eof())
    {
        par[Len++]=fin.get();
    }
    int mi=0,mj=0;
 
    int m=0;
    int clen=0;
    int x,y;
    
    for( int i=0;i<Len;i+=1)
    {
        x=i;y=i;
        // for odd
        clen=findpal(x,y);
        if(clen>m){m=clen;mi=x;mj=y;}
        // for even
        y=y+1;
        clen=findpal(x,y);
        if(clen>m) {m=clen;mi=x;mj=y;}
    }
    //count alphas
    int c=0;
    for(int i=mi;i<=mj;i++)
    {
        if(isAlpha(par[i])) c++;
    }
    //trim from left and right 
    for(int i=mi;i<=mj;i++)
        if(isAlpha(par[i])) {mi=i;break;}
    for(int i=mj;i>=0;i--)
        if(isAlpha(par[i])) { mj=i;break;}
    
    fout<<c<<endl;
    for(int i=mi;i<=mj;i++)
        fout<<par[i];
    fout<<endl;
    return 0;
}
