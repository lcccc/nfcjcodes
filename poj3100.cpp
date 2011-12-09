/*
 * Author: FreePascal
 * Created Time:  2011/10/22 14:11:10
 * File Name: poj3100.cpp
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
double f(double b,int n)
{
    return pow(b,1/(n+0.0));
} 
int main() {
    double b;
    int n;
    while(cin>>b>>n)
    {
        if(b == 0.0 && n == 0) break;
        int imin,imax;
        imin = floor(f(b,n));
        imax = ceil(f(b,n));
        if( fabs(pow(double(imin),n) - b) < fabs(pow(double(imax),n) - b))
            cout<<imin<<endl;
        else cout<<imax<<endl;
    }
    return 0;
}

