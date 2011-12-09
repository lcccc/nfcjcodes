/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/1 19:48:37
 * File Name: 81-2.cpp
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
int p[2005],n,init,a,b;
int main() {
    long long ans = 0;
    cin>>n>>init;
    ans = init;
    for(int i=1;i <= n;i++)
        cin>>p[i];
    for(int i=1;i <= n;i++)
        for(int j = i+1;j <= n;j++)
           if( init / p[i] * p[j] + init % p[i] > ans )
              ans = init / p[i] * p[j] + init % p[i];
   cout<<ans<<endl;
 
    return 0;
}

