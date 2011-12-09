/*
 * Author: FreeJourney
 * Created Time:  2011/8/1 18:42:22
 * File Name: hdu3896.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 100000;
const int maxm = 500000;
const int maxp = 20;
int n, m, q, Time, dfn[maxn + 5], low[maxn + 5], final[maxn+ 5], deep[maxn + 5], father[maxn + 5][20];
vector<int> adj[maxn + 5];

void dfs(int u, int v,int dep){
    cout << u << endl;
    dfn[u] = low[u] = ++Time;
    deep[u] = dep;
    father[u][0] = v;
    for (int i = 0; i < adj[u].size(); i++) {
        int node = adj[u][i];
        if (!dfn[node]) {
            dfs(node, u, dep + 1);
            low[u] = min(low[u], low[node]);
        }
        else if (node != v) {
            low[u] = min(low[u], dfn[node]);
        }
    }
    final[u] = ++Time;
}

int in_bic(int u, int v) {
    return dfn[v] <= dfn[u] && final[u] <= final[v];
}

int main() {
    freopen ("hdu3896.out","w",stdout);
    while (scanf("%d%d", &n, &m) == 2){
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(low, 0, sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        memset(deep, 0, sizeof(deep));
        memset(father, 0, sizeof(father));
        Time = 0;
        dfs(1, 0, 1);
        //for (int i = 0; i <= maxp; i++) {
            //for (int j = 1; j <= n; j++) {
                //father[j][i + 1] = father[father[j][i]][i];
            //}
        //}
        
        scanf("%d", &q);
        for (int i = 1; i <= q; i++) {
            int op, a, b, c, d;
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d%d%d", &a, &b, &c, &d);
            }
            else {
                scanf("%d%d%d", &a, &b, &c);
            }
        }
    }   
    return 0;
}

