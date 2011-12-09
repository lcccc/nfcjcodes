/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 15时58分04秒
 * File Name: e.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "sstream"
using namespace std;
#define SZ(v) ((int)(v).size())

typedef long long lint;
const lint maxint = ~0ull >> 2;
const int maxl = 100 + 100;
const int maxlen = 1000 + 100;
const int maxn = 1000 + 100;

int CS,n,len[maxn];
lint l,w,sum[maxn][maxn],f[maxl][maxn];
char ss[2097152];

void init(){
    int tot = 1;
    scanf("%lld%lld\n",&l,&w);
    //printf("%d %d\n",l,w);
    while (gets(ss))
    {
        int ltot = tot;
        string s;
        stringstream str(ss);
        while (str >> s)
            len[tot++] = s.size();
        if (tot == ltot) break;
    }
    n = tot - 1;
}
void makesum(){
    int suml[maxn];
    memset(sum,0,sizeof(sum));
    suml[0] = 0;
    sum[0][0] = w * w * w;
    for (int i = 1; i <= n; i++) suml[i] = suml[i - 1] + len[i];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++){
            lint x = w - (suml[j] - suml[i - 1]) - (j - i);
            if (x < 0) sum[i][j] = maxint;
            else sum[i][j] = x * x * x;
        }
    for (int i = 1; i <= n; i++) sum[i + 1][i] = maxint;
}
void dpwork(){
    memset(f,0,sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) f[0][i] = maxint;
    for (int i = 1; i <= l; i++) f[i][0] = f[i - 1][0] + w * w * w;
    for (int i = 1; i <= l; i++){
        for (int j = 1; j <= n; j++){
            f[i][j] = maxint;
            f[i][j] = min(f[i][j],f[i - 1][j] + w * w * w);
            //printf("%d %d\n",i,j);
            for (int k = j - 1; k >= 0; k--){
                if (sum[k + 1][j] == maxint) break;
                f[i][j] = min(f[i][j],f[i - 1][k] + sum[k + 1][j]);
                //printf("%d %d %lld\n",i,j,f[i][j]);
            }
        }
    }
}

int main() {
    freopen("e.in","r",stdin);
    scanf("%d",&CS);
    while (CS--){
        init();
        makesum();
        //printf("%lld\n",maxint);
        dpwork();
        if (f[l][n] == maxint) printf("%d\n",-1);
        else printf("%lld\n",f[l][n]);
    }
    return 0;
}

