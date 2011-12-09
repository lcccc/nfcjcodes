/*
 * Team : FreePascal
 * Created Time:  2011年08月20日 星期六 16时19分36秒
 * File Name: 820f.cpp
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

const int maxn = 500 + 100;
const int maxm = 20000 + 100;
int n,m,d[maxn],cnt;
bool a[maxn][maxn],visit[maxn],flag,can[maxn][maxn];

void cpy(bool a[][maxn],bool b[][maxn]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) a[i][j] = b[i][j];
}
void dfs1(int k){
    visit[k] = true;
    for (int i = 0; i < n; i++)
        if (!visit[i] && a[k][i]) dfs1(i);
}
void dfs(int s,int t,int k){
    if (cnt >= 2) return ;
    for (int i = 0; i < n; i++)
        if (can[k][i]){
            can[k][i] = false; can[i][k] = false;
            if (i != t) dfs(s,t,i);
            else if (k != s){
                cnt++;
                if (cnt < 2) dfs(s,t,s);
                if (cnt >= 2) return;
            }
        }
}

int main() {
    while (scanf("%d%d",&n,&m) != EOF){
        if (n == 0 && m == 0) break;
        memset(a,false,sizeof(a));
        memset(d,0,sizeof(d));
        for (int i = 0; i < m; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y] = true; a[y][x] = true;
            d[x]++; d[y]++;
        }
        memset(visit,0,sizeof(visit));
        dfs1(0);
        flag = true;
        for (int i = 0; i < n; i++)
            if (!visit[i] || d[i] < 3){
                flag = false;
                break;
            }
        if (!flag) {
            puts("NO");
            continue;
        }
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++){
                cpy(can,a);
                cnt = 0;
                dfs(i,j,i);
                if (cnt < 2){
                    flag = false;
                    break;
                }
            }
        if (!flag) puts("NO");
        else puts("YES");
    }
    return 0;
}

