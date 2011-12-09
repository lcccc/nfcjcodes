/*
 * Author: FreePascal
 * Created Time:  2011/10/13 20:04:59
 * File Name: poj3781.cpp
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
vector<int> f(10);
int p,cs = 1;
bool mycmp(int a,int b)
{
    return a>b;
}
int main() {
    cin>>p;
    for(;cs<=p;cs++)
    {
        int tm;
        cin>>tm;
        for(int i = 0;i < 10;i ++)
            cin>>f[i];
        sort(f.begin(),f.end(),mycmp);
        cout<<cs<<' '<<f[2]<<endl;
    }  
    return 0;
}

