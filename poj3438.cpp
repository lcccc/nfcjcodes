/*
 * Author: FreePascal
 * Created Time:  2011/10/22 13:09:19
 * File Name: poj3438.cpp
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
void f(string s)
{
    string ans;
    int len = 1;
    char nch = s[0];
    for(int i= 1;i < s.size();i ++)
    {
        //out(s[i]);
        //out(nch);
       if(s[i] != nch)
       {
          cout<<len;
          cout<<nch;
          len = 1;
          nch = s[i];
       }
       else 
       {
          len ++; 
        }
    }
    cout<<len<<nch<<endl;
}
int main() {
    int cs;
    string s;
    cin>>cs;
    while(cs--)
    {
       cin>>s;
       f(s);
    } 
    return 0;
}

