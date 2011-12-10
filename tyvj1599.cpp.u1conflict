/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 15:16:31
 * File Name: tyvj1599.cpp
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
int n,m,st;
int main() {
    int dec[1445];
    string nm;
    int s,t,v;
    memset(dec,0,sizeof dec);
    cin>>n>>m;
    for(int i = 0;i < m;i++)
    {
        cin>>nm>>s>>t>>v;
        for(int j = s;j <= t;j++)
            dec[j]+=v;
    }
    int tag = 1,dt;
    st = n+1;
    for(int i = 1;i <= 1440;i++)
       if( st-dec[i] <= 0) {dt = i;tag = 0;break;}
        else st = st+1-dec[i];
    st--;
    //printf("%s\n",tag?"Accepted":"Runtime Error"); 
    if(tag) printf("%s\n%d\n","Accepted",st);
    else printf("%s\n%d\n","Runtime Error",dt);
    return 0;
}

