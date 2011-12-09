/*
 * Team : FreePascal
 * Created Time:  2011年08月11日 星期四 12时49分12秒
 * File Name: 811c.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())

const int maxint = ~0u>>4;
const int maxn = 100 + 100;
int CS,n,m,d[maxn],a[maxn][maxn];
bool inq[maxn];
queue<int> q;

void spfa(){
    int u;
    memset(inq,true,sizeof(inq));
    for (int i = 1; i <= n; i++) q.push(i);
    while (!q.empty()){
        u = q.front(); q.pop(); inq[u] = false;
        for (int i = 1; i <= n; i++)
            if (d[i] > d[u] + a[u][i]){
                d[i] = d[u] + a[u][i];
                if (!inq[u]){
                    q.push(i);
                    inq[i] = true;
                }
            }
    }
}
void print(){
    int cnt = 0;
    bool visit[maxn];
    for (int i = 1; i <= n; i++) printf("%d %d\n",i,d[i]);
    memset(visit,false,sizeof(visit));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < n; j++){
            for (int k = j + 1; k <= n; k++)
                if (i != j && i != k && d[i] == d[j] + d[k]) {
                    visit[i] = true;
                    break;
                }
            if (visit[i]) break;
        }
    }
    for (int i = 1; i <= n; i++)
        if (visit[i]) cnt++;
    printf("%d\n",cnt);
}

int main() {
    scanf("%d",&CS);
    while (CS--){
        scanf("%d",&n);
        for (int i = 1; i <= n; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            d[x] = y;
        }
        for (int i = 1; i <= n; i++) d[i]--;
        scanf("%d",&m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) a[i][j] = maxint;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i] == d[j]){
                    a[i][j] = 0;
                    a[j][i] = 0;
                }
        for (int i = 1; i <= m; i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y] = min(a[x][y],z);
        }
        spfa();
        print();
    }
    return 0;
}

