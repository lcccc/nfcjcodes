/*
 * Team : FreePascal
 * Created Time:  2011年08月08日 星期一 15时53分40秒
 * File Name: 88h.cpp
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

const int maxint = ~0u>>2;
const int maxn = 100 + 100;
const int maxm = 5000;
const int maxp = 200 + 100;
int CS,n,m,p,f[maxp][maxn],b[maxp];
bool a[maxn][maxn];
int main() {
    freopen("h.in","r",stdin);
    scanf("%d",&CS);
    while (CS--){
        scanf("%d",&n);
        if (n == 0) break;
        memset(a,0,sizeof(a));
        for (int i = 1; i <= m; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y] = true; a[y][x] = true;
        }
        for (int i = 1; i <= n; i++) a[i][i] = true;
        scanf("%d",&p);
        for (int i = 1; i <= p; i++) scanf("%d",&b[i]);
        for (int i = 1; i <= p; i++){
            for (int j = 1; j <= n; j++){
                f[i][j] = maxint;
                for (int k = 1; k <= n; k++)
                    if (a[j][k]) f[i][j] = min(f[i][j],f[i - 1][k] + (!(j == b[i])));
            }
        }
        int ans = maxint;
        for (int i = 1; i <= n; i++) ans = min(ans,f[p][i]);
        printf("%d\n",ans);
    }
    return 0;
}

