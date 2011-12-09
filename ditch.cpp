/*
ID:lc757692
TASK:ditch
LANG:C++

 * Team : FreePascal
 * Created Time:  2011年08月20日 星期六 19时41分21秒
 * File Name: ditch.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
const int maxint = -1u>>2;
const int maxn = 200+5;
const int maxm = 200+5;
struct Graph{
    struct Adj{
        int v,c,b;
        Adj(int _v,int _c,int _b):v(_v),c(_c),b(_b){}
        Adj(){}
    };
    int n,S,T,h[maxn],cnt[maxn];
    vector<Adj> adj[maxn];
    void clear(){
        for(int i = 0; i < n;i++){
            adj[i].clear();
        }
        n = 0;
    }
    void insert(int u ,int v,int c,int d = 0){
        get_max(n,max(u,v)+1);
        adj[u].push_back(Adj(v,c,adj[v].size()));
        adj[v].push_back(Adj(u,c*d,adj[u].size()-1));
        //printf("%d %d %d\n",u,v,c);
    }
    int maxflow(int _s,int _t){
        S = _s;T = _t;
        fill(h,h+n,0);
        fill(cnt,cnt + n,0);
        int flow = 0;
        while( h[S] < n){
            flow += dfs(S,maxint);
        }
        return flow;
    }
    int dfs(int u,int flow){
        if( u == T){
            return flow;
        }
        int minh = n -1,ct = 0;
        for(vector<Adj>::iterator it = adj[u].begin();flow && it != adj[u].end();++it){
            if( it-> c){
                if( h[it->v] + 1 == h[u]){
                    int k = dfs(it->v,min(it->c,flow));
                    if(k){
                        it->c -= k;
                        adj[it->v][it->b].c+=k;
                        flow -= k;
                        ct += k;
                    }
                    if( h[S] >= n){
                        return ct;
                    }
                }
                get_min(minh,h[it->v]);
            }
        }
        if (ct){
            return ct;
        }
        if (--cnt[h[u]] == 0){
            h[S] = n;
        }
        h[u] = minh + 1;
        ++ cnt[h[u]];
        return 0;
    }
};
int tmp[205][205];
int main() {
    ifstream cin("ditch.in");
    ofstream cout("ditch.out");
    Graph g;
    int n,m,a,b,c;
    cin>>n>>m;
    memset(tmp,0,sizeof tmp);
    for(int i = 0; i < n;i++)
    {
        cin>>a>>b>>c; 
        tmp[a][b] += c;
    }
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= m;j++)
            if(tmp[i][j] > 0)
                g.insert(i,j,tmp[i][j]);
    cout<<g.maxflow(1,m)<<endl;    
    g.clear();
    return 0;
}

