/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 16时06分19秒
 * File Name: 1007n.cpp
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

struct Graph {
    vector <int> link;
    vector <int> cycle;
}g[2];
int N, M;
Graph *cug;
vector <int> G[100010];
bool vst[100010];
bool end;
void dfs(int p, int pa, int len)
{
    vst[p] = true;
    bool dfsed = false;
    for (vector <int>::iterator it = G[p].begin(), ed = G[p].end(); it!=ed; it++)
    {
        if (!vst[*it])
        {
                dfs(*it, p, len+1);
                if (end) return;
                dfsed=true;
                break;
        }
    }
    if (end) return ;
    if (!dfsed)
    {
        if (G[p].size () == 1)
            cug->link.push_back(len);
        else
            cug->cycle.push_back(len);
        end = true;
    }
}

void doG(int k)
{
           Graph &g = ::g[k];
           g.link.clear();
           g.cycle.clear();
           cug = &::g[k];
           memset(vst, 0, sizeof(int)*N);
           for (int i=0; i<N; i++)
           {           
               if (!vst[i] && G[i].size()==0)
                {
                   end = false;
                   dfs(i, -1, 0);
                }
            }
           for (int i=0; i<N; i++)
           {           
               if (!vst[i] && G[i].size()==1)
                {
                   end = false;
                   dfs(i, -1, 0);
                }
            }
           for (int i=0; i<N; i++)
           {           
               if (!vst[i] && G[i].size()==2)
                {
                   end = false;
                   dfs(i, -1, 0);
                }
            }

           sort(g.link.begin(), g.link.end());
           sort(g.cycle.begin(), g.cycle.end());
           //for (int i=0; i<(int)g.link.size(); i++)              printf("L %d\n", g.link[i]);
           //for (int i=0; i<(int)g.cycle.size(); i++)               printf("C %d\n", g.cycle[i]);
           
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
    {

        scanf("%d%d", &N, &M);
        for (int i=0; i<N; i++) G[i].clear();
        for (int i=0; i<M; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        doG(0);
        
        scanf("%d%d", &N, &M);
        for (int i=0; i<N; i++) G[i].clear();
        for (int i=0; i<M; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        doG(1);
        bool ok = true;
        if (g[0].link.size() == g[1].link.size() && g[0].cycle.size() == g[1].cycle.size())
        {
                for (int i=0; i<(int)g[0].link.size() && ok; i++)
                    if (g[0].link[i] != g[1].link[i]) ok=false;
                for (int i=0; i<(int)g[0].cycle.size() && ok; i++)
                    if (g[0].cycle[i] != g[1].cycle[i]) ok=false;
        }
        else
            ok= false;
        static int ncase = 0;
        printf("Case #%d: %s\n", ++ncase, ok?"YES":"NO");
    }
    return 0;
}

