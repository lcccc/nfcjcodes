/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 12:19:31
 * File Name: tyvj1016.cpp
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
int id[5000+5],sc[5000+5],rank[5000+5];
bool cmp(int a,int b)
{
    return sc[a]>sc[b] || sc[a] == sc[b] && id[a]<id[b];
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n;i++)
    {
        cin>>id[i]>>sc[i];
        rank[i] = i;
    }
    sort(rank,rank+n,cmp);
    int fsx,k=0;
    fsx= sc[rank[(int)(m*1.5)-1]];
    for(int i = 0;i < n;i++)
        if( sc[rank[i]] >= fsx ) k++;
    cout<<sc[rank[(int)(m*1.5)-1]]<<' '<<k<<endl;
    for(int i = 0;i <k;i++)
        cout<<id[rank[i]]<<' '<<sc[rank[i]]<<endl;
    return 0;
}

