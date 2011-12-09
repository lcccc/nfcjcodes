/*
 * Team : FreePascal
 * Created Time:  2011年08月19日 星期五 14时22分42秒
 * File Name: 819j.cpp
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

const int maxn = 1000 + 100;
int n,m,n1,n2,n3,x[maxn],y[maxn],a[maxn][maxn],f[maxn][maxn];

void dpwork(){
    memset(f,0,sizeof(f));
    n = n1 - 1; m = n2 - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j- 1] + a[i][j];
            if (i == 1 && j == 1) continue;
            if (f[i][j] != 0) f[i][j]++;
        }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) printf("%d ",f[i][j]);
        printf("\n");
    }
}

int main() {
    while (scanf("%d%d%d",&n1,&n2,&n3) != EOF){
        for (int i = 0; i < n1; i++) scanf("%d",&x[i]);
        for (int i = 0; i < n2; i++) scanf("%d",&y[i]);
        sort(x,x + n1);
        sort(y,y + n2);
        memset(a,0,sizeof(a));
        for (int i = 0; i < n3; i++){
            int xx,yy,j,k;
            scanf("%d%d",&xx,&yy);
            j = lower_bound(x,x + n1,xx) - x;
            k = lower_bound(y,y + n2,yy) - y;
            a[j][k] = 1;
            if (x[j] == xx) a[j + 1][k] = 1;
            if (y[k] == yy) a[j][k + 1] = 1;
            if (x[j] == xx && y[k] == yy) a[j + 1][k + 1] = 1;
        }
        dpwork();
        printf("%d\n",f[n][m]);
    }
    return 0;
}

