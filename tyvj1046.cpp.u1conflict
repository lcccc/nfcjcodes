/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 14:00:40
 * File Name: tyvj1046.cpp
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
string s1,s2;
int k,l1,l2;
int f[2005][2005];
int min(int a,int b)
{
    if( a < b) return a;
    else return b;
    }
void init(){
    cin>>s1>>s2>>k;
    l1 = s1.size();
    l2 = s2.size();
    memset(f,0,sizeof f);
    for(int i = 1; i <= l2;i++)
        f[0][i] = i*k;
    for(int i = 1; i <= l1;i++)
        f[i][0] = i*k;

}
void dp(){
    for(int i = 1;i <= l1;i++)
        for(int j = 1;j <= l2;j++)
        f[i][j] = min(min(f[i-1][j] +k, f[i][j-1]+k),f[i-1][j-1] + fabs(s1[i-1]-s2[j-1]));
    cout<<f[l1][l2]<<endl;    
}
int main() {
    init();
    dp();
    return 0;
}

