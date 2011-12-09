/*
 * Author: FreePascal
 * Created Time:  2011/10/13 10:50:08
 * File Name: poj2271.cpp
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
void hr(){
    for(int i = 0;i < 80 ;i ++)
        printf("-");
}
int main() {
    string s;
    int k = 0;
    while(cin>>s)
    {
       if(s == "<br>") { k = 0;cout<<endl;continue;}
       if(s == "<hr>") { if(k > 0) cout<<endl;k = 0;hr();continue;}
       if( k == 0 ) 
           k = s.size();
       else
       {
           if( k + s.size() + 1 > 80)
           {
               cout<<endl;
               k = s.size();
           }
           else
           {
               cout<<' ';
               k += 1 + s.size();
           }
       }
        cout<<s;
       }
     
    cout<<endl;
    return 0;
}

