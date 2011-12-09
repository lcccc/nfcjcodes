/*
 * Author: FreePascal
 * Created Time:  2011/10/29 20:32:43
 * File Name: cf116a.cpp
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
int maxt = 0,n,k,np = 0;
int main() {
    cin>>n;
    while(n--)
    {
        cin>>k;
        np -=k; if(np > maxt) maxt = np;
        cin>>k;
        np +=k; if(np > maxt) maxt = np;
    }
   cout<<maxt<<endl; 
    return 0;
}

