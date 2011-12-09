/*
 * Team : FreePascal
 * Created Time:  2011年08月13日 星期六 15时50分45秒
 * File Name: 813e.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "queue"
using namespace std;
#define SZ(v) ((int)(v).size())
int F[120][120][120];
bool inq[120][120][120];

const int dx[]={-1, 0, 1, 0};
const int dy[]={0, 1, 0, -1};

struct pnt{
    int x, y;
}pos[200];
int all[101][101];
int tot = 0;
int lvl = 0;
int N, M;
void allocid(int x, int y)
{
       all[x][y] = ++tot;
       pos[tot].x=x;
       pos[tot].y=y;
}
        
char G[101][101];
int S, E, X1, X2, B1, B2;

int mann[110][110];
int man(int S, int T)
{
    return mann[S][T]==-1?(mann[S][T]=abs(pos[S].x - pos[T].x) + abs (pos[S].y + pos[T].y)):mann[S][T];
}

struct state {
    int s, x1, x2;
    int g;
    int h () const {
           return  min (man(S, X1)+man(X1, X2), man(S,X2)+man(X2, X1)) +  min(man(x1, B1) + man(x2, B2), man(x1, B2) + man(x2, B1));
                   
    }
    
    bool operator < (const state &t) const
    {
        return g + h()*3 > t.g+t.h()*3;
    }
};



bool check(state ans)
{
    switch(lvl)
    {
        case 0: return ans.s == E ;
        case 1: return (ans.s == E)&& (ans.x1 == B1 || ans.x2 == B1);
        case 2: return (ans.s == E)&& ((ans.x1 == B1 && ans.x2 == B2) ||
                                      (ans.x1 == B2 && ans.x2 == B1) );
    }
    return false;
}
int ans;
queue <state> q;
void try_enqueue(int s, int x1, int x2, int cost)
{
    if (F[s][x1][x2] == -1 || F[s][x1][x2] > cost)
    {
        F[s][x1][x2] = cost;
        if (!inq[s][x1][x2])
        {
                state st={s, x1, x2, F[s][x1][x2]};
                if (check(st)) {
                    ans = min(ans, F[s][x1][x2]);
                    return;
                }
                q.push(st);
                inq[s][x1][x2]=true;   
        }
    }   

}

void dp()
{
     memset(mann, -1, sizeof(mann));
     ans = (-1u)>>1;
     state s0 = {S, X1, X2};
     q.push(s0);
     for (int i=0; i<=tot; i++)
         for (int j=0; j<=tot; j++)
             for (int k=0; k<=tot; k++)
                 F[i][j][k] = -1,
                 inq[i][j][k]=false;
     F[S][X1][X2] = 0;
     inq[S][X1][X2] = true;
         int que = 0;
     while (!q.empty())
     {
            
        state st = q.front(); q.pop();
        int cx = pos[st.s].x, cy = pos[st.s].y;
        inq[st.s][st.x1][st.x2] = false;
        if (F[st.s][st.x1][st.x2]<st.g) continue;
        if (F[st.s][st.x1][st.x2]>=ans) continue;
        if (check(st)) 
        {
            ans = min(ans, F[st.s][st.x1][st.x2]);
            continue;
        }
       
        que++;
        
        for (int i=0; i<4; i++) {
            //try_push(i);
            int tx = cx + dx[i], ty = cy + dy[i];
            int num = all[tx][ty];
            int xum = all[tx+dx[i]][ty+dy[i]];
            if (num == st.x1 && xum!=st.x2 
                    && G[tx+dx[i]][ty+dy[i]] != '#')
            {
               try_enqueue(num, xum, st.x2, F[st.s][st.x1][st.x2]+1);
            }
            if (num == st.x2 && xum!=st.x1
                    && G[tx+dx[i]][ty+dy[i]] != '#')
            {
               try_enqueue(num, st.x1, xum, F[st.s][st.x1][st.x2]+1);
            } 
        }
        for (int i=0; i<4; i++) {
            //try_move(i);
            int tx = cx + dx[i], ty = cy + dy[i];
            int num = all[tx][ty];
            if (num != st.x1 && num !=st.x2 && G[tx][ty] != '#')
               try_enqueue(num, st.x1, st.x2, F[st.s][st.x1][st.x2]+1);
        }
     }
     printf("Proc:%d\n", que);
     if (ans == (-1u)>>1)
         printf("impossible\n");
     else
         printf("%d\n", ans);
}

int main() 
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &N, &M);
        tot = 0;
        X1 =  0;
        X2 =  0;
        B1 =  0;
        B2 =  0;
        for (int i=0; i<N; i++)
            scanf("%s", G[i]);
        lvl = 0;
        int lvi = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
            {
                if (G[i][j] != '#') 
                {
                    allocid(i, j);   
                    switch(G[i][j])
                    {
                        case 'S': S = all[i][j]; break;
                        case 'E': E = all[i][j]; break;
                        case 'X': if (X1 == 0) X1=all[i][j], lvi=1; else X2=all[i][j], lvi=2; break;
                        case 'B': if (B1 == 0) B1=all[i][j], lvl=1; else B2=all[i][j], lvl=2; break;
                    }
                }
            }
         if (lvi < lvl)
         {
             printf("impossible\n"); continue;
         }
         dp();
    }
    return 0;
}

