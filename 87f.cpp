/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 13时58分41秒
 * File Name: 
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
const lint maxint = ~0ull>>3;
const int maxn = 100000 + 100;
const int maxk = 300 + 100;
int CS,n,m,k,s,t;
struct node{
    int v,w;
    node (int _v,int _w):
        v(_v),w(_w) {};
    node() {}
};
vector<node> e[maxn],oe[maxn];
int q[maxn];
lint ds[maxn],dt[maxn];
bool inq[maxn];
void spfa(int s,int t,vector<node> e[],lint d[]){
    int head,tail,u,v;
    memset(inq,0,sizeof(inq));
    for (int i = 1; i <= n; i++) d[i] = maxint;
    head = 0; tail = 1; q[1] = s; inq[s] = true; d[s] = 0;
    while (head != tail){
        head++; 
        if (head >= maxn) head = 1;
        u = q[head]; inq[u] = false;
        for (int i = 0; i < (int)e[u].size(); i++){
            v = e[u][i].v;
            if (d[v] > d[u] + e[u][i].w){
                d[v] = d[u] + e[u][i].w;
                if (!inq[v]){
                    tail++; 
                    if (tail >= maxn) tail = 1;
                    q[tail] = v; inq[v] = true;
                }
            }
        }
    }
}
int main() {
    freopen("f.in","r",stdin);
    scanf("%d",&CS);
    while (CS--){
        scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
        for (int i = 1; i <= m; i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            e[x].push_back(node(y,z));
            oe[y].push_back(node(x,z));
        }
        spfa(s,t,e,ds);
        spfa(t,s,oe,dt);
        lint ans = ds[t];
        for (int i = 1; i <= k; i++){
            int x,y,z;
            lint tmp;
            scanf("%d%d%d",&x,&y,&z);
            tmp = min(ds[x] + dt[y] + z,ds[y] + dt[x] + z);
            ans = min(ans,tmp);
        }
        if (ans == maxint) printf("-1\n");
        else printf("%lld\n",ans);
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1; i <= n; i++) oe[i].clear();
    }
    return 0;
}

