/*
 * Author: FreePascal
 * Created Time:  2011/10/6 18:23:00
 * File Name: growbact.cpp
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
    int n;
    cin>>n;
    vector<double> f(10000);
    double l;
    f[0]  = 0;
    f[1]  = n;
    f[2]  = n;
    int i;
    for(i = 3;i < 10000;i ++)
    {
        f[i] = f[i-1] + f[i-2];
        l = f[i] + f[i-1] + f[i-2] + f[i-3];
        if( l >= 1000000000000LL ) {
            cout<<i <<endl;
            break;
        }
       cout<<i << l <<endl; 
    }
    return 0;
}

