/*
ID:lc757692
TASK:money
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月19日 星期二 10时45分11秒
 * File Name: money-sub.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
int v,n;
long long ans[26][10001];
int mz[26];
void _input(){
    ifstream cin("money.in");
    cin>>v>>n;
    for(int i=1;i<=v;i++)
        cin>>mz[i];
    memset(ans,0,sizeof 0);
    for(int i=0;i<=v;i++)
        ans[i][0]=1;
}
void _dp(){
    for(int i=1;i<=v;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=j/mz[i];k++)
                //if(i-1>=1)
                ans[i][j]+=ans[i-1][j-mz[i]*k];
}
void _output(){
    ofstream cout("money.out");
    //for(int i=0;i<=v;i++){
    //    for(int j=0;j<=n;j++)
    //        cout<<ans[i][j]<<' ';
    //    cout<<endl;
   // }
    cout<<ans[v][n]<<endl;
}
int main() {
    _input();
    _dp();
    _output();
    return 0;
}

