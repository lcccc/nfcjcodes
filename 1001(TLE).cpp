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

const int maxint = ~0u>>2;
const double esp = 1e-8;
const int maxn =100;
int CS,n,x[maxn],y[maxn];
double dis[maxn][maxn];

void get_max(int &a,int b){
    if (a < b) a = b;
}
void get_min(int &a,int b){
    if (a > b) a = b;
}
struct Graph{
    struct Adj{
        int v,c,b;
        double w;
        Adj(int _v,int _c,double _w,int _b) : v(_v),c(_c),w(_w),b(_b) {};
    }*st[maxn];
    vector<Adj> adj[maxn];
    int n;
    void clear(){
        for (int i = 0; i < n; ++i){
            adj[i].clear();
        }
        n = 0;
    }
    void insert(int u,int v,int c,double w,int d = 0){
        get_max(n,max(u,v) + 1);
        adj[u].push_back(Adj(v,c,w,adj[v].size()));
        adj[v].push_back(Adj(u,0,-w,adj[u].size() - 1));
        if (d){
            adj[v].push_back(Adj(u,c,w,adj[u].size()));
            adj[u].push_back(Adj(v,0,-w,adj[v].size() - 1));
        }
    }
    pair<int,double> mcmf(int S,int T){
        int d;
        int flow = 0;
        double cost = 0;
        while ((d = bell(S,T))){
            flow += d;
            for (int v = T; v != S; v = adj[st[v]->v][st[v]->b].v){
                cost += st[v]->w * d;
                st[v]->c -= d;
                adj[st[v]->v][st[v]->b].c += d;
            }
        }
        return make_pair(flow,cost);
    }
    int NEXT(int s,int n){
        if (s > n) s = 0;
        return s;
    }
    int bell(int S,int T){
        int bfs[maxn],hash[maxn];
        double d[maxn];
        fill(hash,hash + n,0);
        fill(d,d + n,maxint);
        hash[S] = 1; d[S] = 0; bfs[0] = S;
        for (int s = 0,t = 1; s != t; hash[bfs[s]] = 0, s = NEXT(s + 1,n)){
            int v = bfs[s];
            for (vector<Adj>::iterator it = adj[v].begin(); it != adj[v].end(); ++it){
                if (it->c > 0 && d[v] + it->w < d[it->v]){
                    d[it->v] = d[v] + it->w;
                    st[it->v] = &(*it);
                    if (hash[it->v] == 0){
                        hash[it->v] == 1;
                        bfs[t] = it->v;
                        t = NEXT(t + 1,n);
                    }
                }
            }
        }
        if (fabs(d[T] - maxint) < esp){
            return 0;
        }
        int ans = maxint;
        for (int v = T; v != S; v = adj[st[v]->v][st[v]->b].v){
            get_min(ans,st[v]->c);
        }
        return ans;
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
        for (int i = 0; i <= 2 * n; i++)
            for (int j = 0; j <= 2 * n; j++) dis[i][j] = calc(x[i],y[i],x[j],y[j]);
        for (int i = 1; i <= 2 * n; i++){
            g.insert(0,i,1,dis[0][i]);
            g.insert(i + 2 * n,4 * n + 1,1,0);
        }
        for (int i = 1; i <= 2 * n; i++)
            for (int j = i + 1; j <= 2 * n; j++){
                if (dis[0][i] + dis[i][j] < dis[0][j] + dis[j][i]) g.insert(i,j + 2 * n,1,dis[i][j]);
                else g.insert(j,i + 2 * n,1,dis[j][i]);
            }
        g.insert(4 * n + 2,0,n,0);
        g.insert(4 * n + 1,4 * n + 3,n,0);
        printf("Case #%d: ",++cs);
        printf("%.2lf\n",g.mcmf(4 * n + 2,4 * n + 3).second);
        g.clear();
    }
    return 0;
}

