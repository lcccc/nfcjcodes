/*
 * Team : FreePascal
 * Created Time:  2011年08月11日 星期四 15时59分00秒
 * File Name: 811b.cpp
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

const int maxn = 50;
int n,m,a[maxn][maxn],cont;
bool mark[maxn],visit[maxn][maxn],flag;

int shrink();
void dfsB(int k,int cnt);
void dfsR(int k,int cnt);

int shrink(){
    for (int i = 0; i < n; i++){
        for (int j= 0; j < n; j++){
            if (a[i][j] >= 2){
                if (!mark[j]){
                    mark[j] = true;
                    a[i][j] = a[j][i] = 1;
                    for (int k = 0; k < n; k++){
                        if (!mark[k]){
                            a[i][k] += a[i][j] + a[j][k];
                        }
                    }
                }
            }
        }
    }
    int cnt;
    for (int i = 0; i < n; i++)
        if (!mark[i]) cnt++;
    return cnt;
}
void dfsB(int k,int cnt){
    cont++;
    if (cont > 1000) return;
    for (int i = 0; i < n; i++)
        if (!visit[k][i]){
            visit[k][i] = true;
            cnt = shrink();
            if (cnt == 1){
                flag = true;
                return ;
            }
            dfsR(i,cnt);
            visit[k][i] = false;
        }
}
void dfsR(int k,int cnt){
    cont++;
    if (cont > 1000) return;
    for (int i = 0; i < n; i++)
        if (!visit[k][i]){
            visit[k][i] = true;
            dfsB(i,cnt);
            visit[k][i] = false;
            if (flag) return;
        }
}

int main() {
    while (scanf("%d%d",&n,&m) != EOF){
        if (n == -1 && m == -1) break;
        memset(a,0,sizeof(a));
        memset(mark,false,sizeof(mark));
        for (int i = 1; i <= m; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]++; a[y][x]++;
        }
        flag = false;
        int cnt = shrink();
        if (cnt == 1){
            puts("YES");
            continue;
        }
        cont = 0;
        for (int i = 0; i < n; i++){
            dfsR(i,cnt);
            if (flag) break;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}

