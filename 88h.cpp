/*
 * Team : FreePascal
 * Created Time:  2011年08月08日 星期一 14时44分58秒
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
const int maxp = 200 + 100;
const int maxm = 5000;
int CS,n,m,p,ans,a[maxn][maxn],path[maxp];
void floyd(){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] > a[i][k] + a[k][j]) a[i][j] = a[i][k] + a[k][j];
}
int find(int k){
    int u,v,sum;
    u = path[k];
    sum = maxint;
    for (int i = k + 2; i <= n; i++){
        v = path[i];
        if (a[u][v] <= i - k){
            sum = i - k - 1;
            break;
        }
    }
    if (k + 2 > n) sum = 1;
    if (sum == maxint) sum = n - k;
    return sum;
}

int main() {
    freopen("h.in","r",stdin);
    scanf("%d",&CS);
    while (CS--){
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) a[i][j] =maxint;
        for (int i = 1; i <= m; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y] = 1;
            a[y][x] = 1;
        }
        for (int i = 1; i <= n; i++) a[i][i] = 0;
        floyd();
        scanf("%d",&p);
        for (int i = 1; i <= p; i++) scanf("%d",&path[i]);
        ans = 0;
        for (int i = 1; i < p; i++){
            int u = path[i], v = path[i + 1];
            if (a[u][v] > 1){
                int t1,t2;
                t1 = find(i + 1);
                t2 = find(i);
                ans = ans + min(t1,t2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

