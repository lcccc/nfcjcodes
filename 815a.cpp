/*
 * Team : FreePascal
 * Created Time:  2011年08月15日 星期一 12时59分48秒
 * File Name: 815a.cpp
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
const int maxn = 10000 + 100;
int CS,n,num[maxn];
lint f[maxn];
bool visit[maxn];
struct node{
    int v,w;
    node(int _v,int _w): v(_v),w(_w) {};
};
vector<node> e[maxn];

void dfs(int k){
    int u;
    visit[k] = true;
    for (int i = 0; i < (int)e[k].size(); i++){
        u = e[k][i].v;
        //pa[u] = k;
        if (visit[u]) continue;
        dfs(u);
        num[k] += num[u];
        f[k] += f[u] + (lint)e[k][i].w * num[u];
    }
}
void treedp(int k){
    int u;
    visit[k] = true;
    for (int i = 0; i < (int)e[k].size(); i++){
        u = e[k][i].v;
        if (visit[u]) continue;
        f[u] = f[k] + (n - num[u] - num[u]) * e[k][i].w;
        treedp(u);
        //f[u] = f[k] + (n- num[u] - num[u]) * e[k][i].v;
    }
}

int main() {
    scanf("%d",&CS);
    while (CS--){
        scanf("%d",&n);
        for (int i = 0; i <= n; i++) e[i].clear();
        for (int i = 0; i < n; i++) num[i] = 1;
        for (int i = 1; i < n; i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            e[x].push_back(node(y,z));
            e[y].push_back(node(x,z));
        }
        memset(f,0,sizeof(f));
        memset(visit,0,sizeof(visit));
        dfs(0);
        //for (int i = 0; i < n; i++) printf("%d\n",f[i]);
        //for (int i = 0; i < n; i++) printf("%d\n",num[i]);
        memset(visit,0,sizeof(visit));
        treedp(0);
        //for (int i = 0; i < n; i++) printf("%d\n",f[i]);
        double ans = 0;
        for (int i = 0; i < n; i++) ans = ans + f[i];
        ans = ans / 2 / (n * (n - 1) / 2);
        printf("%.7lf\n",ans);
    }
    return 0;
}

