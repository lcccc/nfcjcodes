/*
 * Author: FreePascal
 * Created Time:  2011/10/13 20:16:47
 * File Name: poj3619.cpp
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
int n,k,s,t,r;
int f(int s,int t,int r)
{
    int rd = 0,rt = 0;
    while(rd < n)
    {
        if( rd + s*t >= n)
        {
            rt+= (ceil)((n - rd+ 0.0) /s);
            rd = n;
        }
        else
        {
            rd+= s*t;
            rt += t + r;
        }
    }
    return rt;
}
int main() {
    cin>>n>>k;
    while(k--)
    {
        cin>>s>>t>>r;
        cout<<f(s,t,r)<<endl;
    }
    return 0;
}

