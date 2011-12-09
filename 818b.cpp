/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/18 19:15:09
 * File Name: 818b.cpp
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
int p[1005];
double per[1005];
double f[10001];
int main() {
    int n,m;
    while(1){
    cin>>n>>m;
    if(n == 0 && m==0) break;
    for( int i = 0;i < m;i++)
        cin>>p[i]>>per[i];
    //sort(id,id+m,cmp);
    //for(int i = 0;i < m;i++)
        //cout<<id[i]<<endl;
    double ans = 0;
    memset(f,0,sizeof f);
    for(int i = 0;i < m;i++)
       for(int j = n; j >= 0;j--) 
       if(j - p[i] <0) f[j] = f[j];
       else
           f[j] = max( f[j], -f[j-p[i]]*per[i]+f[j-p[i]]+per[i]);
    ans = f[n];
    ans *= 100;
    printf("%.1lf%%\n",ans);
    }
    return 0;
}

