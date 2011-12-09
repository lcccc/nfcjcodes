/*
 * Team : FreePascal
 * Created Time:  2011年08月15日 星期一 14时04分30秒
 * File Name: 815d.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

typedef long long lint;
const int maxn = 8000;
const int maxl = 100;
int CS,m,n,q,Max,len[maxn],t,query[50];
lint f[2][maxl];

void dpwork(){
    t = 0;
    memset(f,0,sizeof(f));
    for (int i = 1; i <= m; i++) f[0][len[i]]++;
    for (int i = 2; i <= n; i++){
        //printf("\n%d\n",i);
        t ^= 1;
        memset(f[t],0,sizeof(lint) * (Max + 1));
        //memcpy(f[t],f[t ^ 1],sizeof(f[t]));
        for (int j = 1; j <= m; j++)
            for (int k = len[j]; k <= Max; k++){
                f[t][k] += f[t ^ 1][k - len[j]];
                //cout<<k<<" "<<f[t][k]<<endl;
            }
    }
}
int main() {
    scanf("%d",&CS);
    while (CS--){
        scanf("%d%d%d",&m,&n,&q);
        Max = 0;
        for (int i = 1; i <= m; i++){
            char s[20];
            scanf("%s",s);
            len[i] = strlen(s);
        }
        for (int i = 0; i < q; i++){
            scanf("%d",&query[i]);
            Max = max(Max,query[i]);
        }
        dpwork();
        for (int i = 0; i < q; i++) cout<<f[t][query[i]]<<endl;
    }
    return 0;
}

