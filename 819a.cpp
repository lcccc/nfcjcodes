/*
 * Team : FreePascal
 * Created Time:  2011年08月19日 星期五 14时42分34秒
 * File Name: 819a.cpp
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
const int maxn = 200 + 100;
int CS,n,m,ans,col[maxn],lik[maxn],path[maxn],tmpath[maxn];
bool a[maxn][maxn],visit[maxn],use[maxn];

bool find(int x){
    for (int i = 0; i < n; i++){
        if (a[x][i] && !visit[i]){
            visit[i] = true;
            if (lik[i] == -1 || find(lik[i])){
                lik[i] = x;
                return true;
            }
        }
    }
    return false;
}
void compare(){
    int tmp[maxn];
    tmp[0] = 0;
    for (int i = 0; i < n; i++)
        if (use[i]) tmp[++tmp[0]] = i;
    for (int i = 0; i <= tmp[0]; i++)
        if (path[i] < tmp[i]) break;
        else if (path[i] > tmp[i]){
            copy(tmp,tmp + tmp[0] + 1,path);
            break;
        }
}
void breakedge(){
    for (int i = 0; i < n; i++) 
        if (lik[i] != -1) a[lik[i]][i] = false;
}

int main() {
    scanf("%d",&CS);
    while (CS--){
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++) scanf("%d",&col[i]);
        memset(a,false,sizeof(a));
        memset(lik,-1,sizeof(lik));
        for (int i = 0; i < m; i++){
            int x,y,p,q;
            scanf("%d%d",&x,&y);
            if (col[x] == col[y]) continue;
            if (col[x] == 0) p = x,q = y;
            else p = y,q = x;
            a[p][q] = true;
        }
        ans = -1; path[0] = maxint;
        int cnt = 0;
        while (true){
            cnt++;
            if (cnt > 1000) break;
            int tmp = 0;
            for (int i = 0; i < n; i++){
                memset(visit,false,sizeof(visit));
                if (find(i)) tmp++;
            }
            if (ans == -1) ans = tmp;
            else if (ans != tmp) break;
            memset(use,0,sizeof(use));
            for (int i = 0; i < n; i++)
                if (lik[i] != -1) use[min(lik[i],i)] = true;
            compare();
            breakedge();
        }
        printf("%d ",ans);
        for (int i = 1; i < path[0]; i++) printf("%d ",path[i]);
        printf("%d\n",path[path[0]]);
    }
    return 0;
}

