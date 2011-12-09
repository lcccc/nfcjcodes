/*
 * Author: FreePascal
 * Created Time:  2011/8/30 15:57:13
 * File Name: poj1002.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
       s2 = "22233344455566670778889990";

int n;
map<string,int> jl;
int getchar(char c){
    if( c <='9' && c >= '0' ) return c;
    if( c <='Z' && c >= 'A' ) return s2[s1.find(c)] ;
    return '\0';
}
string getct(string s)
{
    string ans;
    for(int i = 0;i < s.size(); i++)
        if(!getchar(s[i])) ans+=getchar(s[i]);
    ans.insert(3,"-");
    return ans;
}
void insert(string s)
{
    jl[getct(s)] ++;
}
void output()
{
    int b = 0;
    map<string,int>:: iterator lp;
    for(lp = jl.begin();lp!=jl.end();lp++)
    {
        if(lp->second != 1)
        {
            cout<<lp->first<<' '<<lp->second<<endl;
            b = 1;
        }
    }
   if(!b ) cout<<"No duplicates."<<endl;
} 
int main() {
    cin>>n;
    string s;
    for(int i = 0;i < n;i++ )
    {
      cin>>s;
      insert(s);
    }
    output();
    return 0;
}

