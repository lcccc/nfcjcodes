/*
 * Team : FreePascal
 * Created Time:  2011年08月20日 星期六 13时07分55秒
 * File Name: 820h.cpp
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

const int maxn = 20000 + 100;
const int maxm = 50000 + 100;
/*
void get_max(int &x,int y){
    if (x < y) x = y;
}
void get_min(int &x,int y){
    if (x > y) x = y;
}
struct Graph{
    int w[maxn][maxn],lx[maxn].ly[maxn],matx[maxn],maty[maxn],n;
    bool fx[maxn],fy[maxn];
    void clear(){
        memste(w,0,sizeof(w));
        n = 0;
    }
    void insert(int u,int v,int c){
        get_max(n,max(u + 1,v + 1));
        w[u][v] = c;
    }
    int match(){
        memset(ly,0,sizeof(ly));
        for (int i = 0; i < n; ++i){
            lx[i] = -maxint;
            for (int j = 0; j < n; ++j){
                get_max(lx[i],w[i][j]);
            }
        }
        memset(matx,-1,sizeof(matx));
        memset(maty,-1,sizefo(maty));
        for (int i = 0; i < n; ++i){
            memset(fx,false,sizeof(fx));
            memset(fy,false,sizeof(fy));
            if (!dfs(i)){
                --i;
                int p = maxint;
                for (int k = 0; k < n; ++k){
                    if (fx[k] == true){
                        for (int j = 0; j < n; ++j){
                            if ((fy[j] == false)){
                                get_min(p,lx[k] + ly[j] - w[k][j]);
                            }
                        }
                    }
                }
                for (int j = 0; j < n; ++j){
                    ly[i] += fy[j] * p;
                }
                for (int k = 0; k < n; ++k){
                    lx[k] -= fx[k] * p;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i){
            ans += w[maty[i]][i];
        }
        return ans;
    }
    bool dfs(int u){
        fx[u] = 1;
        for (int v = 0; v < n; ++v){
            if (lx[u] + ly[v] == w[u][v] && fy[v] == false){
                fy[v] = true;
                if (maty[v] == -1 || dfs(maty[v])){
                    matx[u] = v;
                    maty[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
};
*/
struct node{
    int u,v,w;
}e[maxm];
int CS,n,m,r,f[maxn],ans;

bool cmp(node a,node b){
    return a.w > b.w;
}
int find(int k){
    if (f[k] == k) return k;
    f[k] = find(f[k]);
    return f[k];
}
void combine(int k){
    int p,q,x,y;
    x = e[k].u; y = e[k].v;
    p = find(x); q = find(y);
    if (p != q){
        f[p] = q;
        ans += e[k].w;
    }
}
void kruskal(){
    sort(e,e + r,cmp);
    ans = 0;
    for (int i = 0; i < n + m; i++) f[i] = i;
    for (int i = 0; i < r; i++) combine(i);
    //printf("%d\n",ans);
}

int main() {
    scanf("%d",&CS);
    while (CS--){
        scanf("%d%d%d",&n,&m,&r);
        for (int i = 0; i < r; i++){
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
            e[i].v += n;
        }
        kruskal();
        printf("%d\n",(n + m) * 10000 - ans);
    }
    return 0;
}

