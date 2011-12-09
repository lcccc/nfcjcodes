/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 13时38分45秒
 * File Name: 1001.cpp
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

typedef int typef;
typedef double typec;
const typef inff = 0x3f3f3f3f;
const typec infc = 0x3f3f3f3f;
const int maxint = ~0u>>2;
const double esp = 1e-8;
const int maxn =100;
const int maxm = maxn * maxn * 3;
int CS,n,x[maxn],y[maxn];
double dis[maxn][maxn];

struct network{
    int nv,ne,pnt[maxm * 2],nxt[maxm * 2];
    int vis[maxn],que[maxn],head[maxn],pv[maxn],pe[maxn];
    typef flow,cap[maxm * 2];
    typec cost,dis[maxm * 2],d[maxn];
    void add_edge(int u,int v,typef c,typec w){
        pnt[ne] = v; cap[ne] = c; dis[ne] = +w;
        nxt[ne] = head[u]; head[u] = (ne++);
        pnt[ne] = u; cap[ne] = 0; dis[ne] = -w;
        nxt[ne] = head[v]; head[v] = (ne++);
    }
    
    typec min_cost(int src,int sink){
        int p,k,f,r;
        typef mxf;
        for (flow = 0,cost = 0;;){
            memset(pv,-1,sizeof(pv));
            memset(vis,0,sizeof(vis));
            for (int i = 0; i < nv; ++i) d[i] = infc;
            d[src] = 0; pv[src] = src; vis[src] = 1;
            for (f = 0, r = 1,que[0] = src; r != f;){
                p = que[f++];
                vis[p] = 0;
                if (maxn == f) f = 0;
                for (k = head[p]; k != -1; k = nxt[k])
                    if (cap[k] && dis[k] + d[p] < d[pnt[k]]) {
                        d[pnt[k]] = dis[k] + d[p];
                        if (0 == vis[pnt[k]]) {
                            vis[pnt[k]] = 1;
                            que[r++] = pnt[k];
                            if (maxn == r) r = 0;
                        }
                        pv[pnt[k]] = p;
                        pe[pnt[k]] = k;
                    }
            }
            if (-1 == pv[sink]) break;
            for (k = sink,mxf = inff; k != src; k = pv[k])
                if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
            flow += mxf;
            cost += d[sink] * mxf;
            for (k = sink; k != src; k = pv[k]){
                cap[pe[k]] -= mxf;
                cap[pe[k] ^ 1] += mxf;
            }    
        }
        return cost;
    }
    void build(int v,int e){
        nv = v; ne = 0;
        memset(head,-1,sizeof(head));
    }
}g;
double calc(int x,int y,int xx,int yy){
    return (double)sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

int main() {
    scanf("%d",&CS);
    int cs = 0;
    while (CS--){
        scanf("%d%d",&x[0],&y[0]);
        scanf("%d",&n);
        for (int i = 1; i <= 2 * n; i++) scanf("%d%d",&x[i],&y[i]);
        memset(dis,0,sizeof(dis));
        g.build(4 * n + 4,0);
        for (int i = 0; i <= 2 * n; i++)
            for (int j = 0; j <= 2 * n; j++) dis[i][j] = calc(x[i],y[i],x[j],y[j]);
        for (int i = 1; i <= 2 * n; i++){
            g.add_edge(0,i,1,dis[0][i]);
            g.add_edge(i + 2 * n,4 * n + 1,1,0);
        }
        for (int i = 1; i <= 2 * n; i++)
            for (int j = i + 1; j <= 2 * n; j++){
                if (dis[0][i] + dis[i][j] < dis[0][j] + dis[j][i]) g.add_edge(i,j + 2 * n,1,dis[i][j]);
                else g.add_edge(j,i + 2 * n,1,dis[j][i]);
            }
        g.add_edge(4 * n + 2,0,n,0);
        g.add_edge(4 * n + 1,4 * n + 3,n,0);
        printf("Case #%d: ",++cs);
        printf("%.2lf\n",g.min_cost(4 * n + 2,4 * n + 3));
    }
    return 0;
}

