/*
 * Author: FreePascal
 * Created Time:  2011/10/13 15:37:50
 * File Name: poj3077.cpp
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
int main() {
    int num[100];
    string s;
    int n,l;
    cin>>n;
    while(n--)
    {
        cin>>s;
        memset(num,0,sizeof num);
        l = s.size();
        for(int i = 0;i < s.size();i ++)
            num[i+1] = s[i] - '0';
       if( l == 1)
          cout<<s<<endl;
       else
       {
          for(int j = l-1;j >= 1;j --)
          {
             if(num[j+1] >= 5)
                num[j]++;
            num[j+1] = 0;
          }
          if(num[0] == 1) cout<<'1';
          for(int i = 1;i <= l;i ++)
              cout<<num[i];
          cout<<endl;
       }
       } 
    return 0;
}

