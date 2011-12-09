/*
ID:lc757692
TASK:numtri
LANG:C++

 * Author: Nfcj
 * Created Time:  2011年07月15日 星期五 15时31分44秒
 * File Name: numtri.cpp
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
int f[1001][1001],nd[1001][1001],R;
int _init(){
    ifstream cin("numtri.in");
    cin>>R;
    memset(f,0,sizeof(f));
    memset(nd,0,sizeof nd);
    
    for(int i = 1;i<= R;i++)
        for(int j = 1;j <= i;j++)
            cin>>nd[i][j];
}
int _dp(){
    for(int i=1;i<=R;i++)
        for(int j=1;j<=i;j++)
        {
            int tm=max(f[i-1][j],f[i-1][j-1]);
            f[i][j]=tm+nd[i][j];
        }
}
int _ouit(){
    ofstream cout("numtri.out");
    int maxn=0;
    for(int i=1;i<=R;i++)
        maxn=max(maxn,f[R][i]);
    cout<<maxn<<endl;
}

int main() {
    _init();
    _dp();
    _ouit();
    return 0;
}

