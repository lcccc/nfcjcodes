/*
ID:lc757692
TASK:concom
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月19日 星期二 16时42分28秒
 * File Name: concom.cpp
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
int n,cp[101][101],c[101],vi[101];
int dfs(int x)
{
    vi[x]=1;
    for(int i=1;i<=100;i++)
        c[i]+=cp[x][i];
    for(int i=1;i<=100;i++)
        if(c[i]>=50&&!vi[i])
            dfs(i);
}
int main() {
    ifstream cin("concom.in");
    ofstream cout("concom.out");
    cin>>n;
    int a,b,ic;
    memset(cp,0,sizeof cp);
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>ic;
        cp[a][b]=ic;
    }
    for(int i=1;i<=100;i++)
    {
        memset(c,0,sizeof c);
        memset(vi,0,sizeof vi);
        dfs(i);
        for(int j=1;j<=100;j++)
            if(i!=j&&c[j]>=50)cout<<i<<' '<<j<<endl;
    }
    return 0;
}

