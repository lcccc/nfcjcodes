/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 13:05:14
 * File Name: tyvj1045.cpp
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
int sum[25][25],f[25][25],n,k,arr[25];
void init()
{
    cin>>n>>k;
    for(int i = 1;i <= n;i++)
        cin>>arr[i];
    for(int i = 1;i < 25;i++)
        for(int j = 1;j < i;j++)
            sum[i][j] = 1;
    memset(f,0,sizeof f);
    for(int i = 1;i <= n;i++)sum[i][i] = arr[i];
    for(int i = 1;i <= n;i++)
        for(int j = i+1;j <= n;j++)
            sum[i][j] = sum[i][j-1] + arr[j];
}
void dp(){
    for(int i = 1;i <= n;i++)
        f[i][0] = sum[1][i];
    //cout<<sum[2][2]<<endl;
    for(int i = 2;i <= n;i++)
        for(int j = 1;j <= k;j++)
            for(int l =j;l<i;l++)
            {
                f[i][j] = max(f[i][j],f[l][j-1]*sum[l+1][i]);
                //cout<<"sum  "<<sum[l+1][i]<<endl;
                //cout<<"f    "<<f[l][j-1]<<endl;
                //cout<<i<<' '<<j<<' '<<l<<' '<<f[i][j]<<endl;
            }
                //for(int i = 1;i <= n;i++)
        //for(int j=1;j <= k;j++)
            //cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
    cout<<f[n][k]<<endl;
}
int main() {
    init();
    dp();
    return 0;
}

