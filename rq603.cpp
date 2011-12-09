/*
 * Author: FreePascal
 * Created Time:  2011/10/11 11:51:12
 * File Name: rq603.cpp
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
int n,m;
int t[105];
int w[10005];
int fmin(){
    int min = maxint,id = 0;
    for(int i = 0;i < m;i ++)
        if( t[i] < min)
        {
            min = t[i] ;
            id = i;
        }
    return id;
}
int main() {
    cin>>n>>m;
    for(int i = 0;i < n;i ++)
        cin>>w[i];
    memset(t,0,sizeof t);
    for(int i = 0;i < n;i ++)
    {
        t[fmin()] += w[i];
    }
    cout<< *(max_element(t,t+m)) << endl;
    return 0;
}

