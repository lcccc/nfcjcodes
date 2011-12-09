/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/16 0:21:58
 * File Name: hdu1013.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int f(string x)
{
    long long ans =0;
    for(int i = 0;i<x.size();i++)
        ans += x[i] - '0';
    long long tm = 0 ;
    if(ans < 10) return ans;
    while(ans >= 10)
    {
        tm = 0;
        while(ans>0)
        {
            tm += ans % 10;
               ans/=10;
        }
        if(tm < 10) return tm;
        else ans = tm;
    }
}

int main() {
    string n;
    while(cin>>n)
    {
        if(n == "0") break;
        else printf("%d\n",f(n));
    }
    return 0;
}

