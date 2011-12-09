/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 15时09分02秒
 * File Name: 89d.cpp
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

const int maxn = 200 + 100;
int CS,n,m,ans,lin[maxn];
bool a[maxn][maxn],visit[maxn];

bool find(int x){
    for (int i = m + 1; i <= m + n; i++){
        if (a[x][i] && !visit[i]){
            visit[i] = true;
            if (lin[i] == 0 || find(lin[i])){
                lin[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d",&CS);
    int cs = 0;
    while (CS--){
        memset(a,false,sizeof(a));
        memset(lin,0,sizeof(lin));
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= m; i++){
            int p;
            scanf("%d",&p);
            for (int j = 1; j <= p; j++){
                int x;
                scanf("%d",&x);
                a[i][x + m] = true;
            }
        }
        ans = 0;
        for (int i = 1; i <= m; i++){
            memset(visit,false,sizeof(visit));
            if (find(i)) ans++;
        }
        printf("Case %d: ",++cs);
        printf("%d\n",n + m - ans);
    }
    return 0;
}

