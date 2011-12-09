/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 16时32分38秒
 * File Name: 89g.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#include "queue"
#define SZ(v) ((int)(v).size())
static queue<int> q;
int N;
char G[20][20];
int bc, wc, cc;
int wa, wt, ba, bt;
//B=1
//W=0
#define PACK(STATE, B, W) (((STATE)<<8) | ((B)<<4) | ((W)))
#define BCHESS(PACKSTATE) ((PACKSTATE) & 0xF0)
#define WCHESS(PACKSTATE) ((PACKSTATE) & 0x0F)
#define STATE(PACKSTATE)  ((PACKSTATE) >> 8)
int cost [ PACK(0x800, 16, 16) ];
int inq  [ PACK(0x800, 16, 16) ];

void try_enqueue(int state, int cst)
{
    if (cost[state] == -1 || cost[state] > cst)
    {
        cost[state] = cst;
        if (!inq[state])
        {
            inq[state]=true;
            q.push(state);
        }
    }
}

void try_moveb(int b, int w, int n, int r)
{
    int cost = bc;
    int rs =r >> 8;
    if ( ((rs>>n) & 1) == 0) cost = 2*bc;
    try_enqueue(PACK(rs | (1<<n), n, w), ::cost[r]+cost);
}

void try_movew(int w, int b, int n, int r)
{
    int cost = wc;
    int rs =r >> 8;
    if ( (rs>>n) & 1)  cost = 2*wc;
    try_enqueue(PACK(rs & ~(1<<n), b, n), ::cost[r]+cost);
}

void try_movewb(int b, int i, int w, int j, int r)
{
    if (i==j) return;
    int cost = cc;
    int rs = r >> 8;
    if ( ((rs>>i) & 1) == 0) cost += cc;
    if ( (rs>>j) & 1     ) cost += cc;
    if (cost == 3*cc) cost += cc;
    try_enqueue ( PACK( ((rs & ~(1<<j)) | (1<<i)),  i, j),  ::cost[r]+cost);
}

int spfa()
{
    memset(inq, 0, sizeof(inq));
    memset(cost, -1, sizeof(cost));
    int start = PACK (1<<ba , ba, wa);
    cost[start]=0;inq[start]=1;
    q.push(start);
    while (!q.empty())
    {

        int r = q.front(); q.pop();
        //printf("%012x %d\n", r, cost[r]);
        int b = BCHESS(r);
        int w = WCHESS(r);
        for (int i=0; i<N; i++)
            if (G[b][i]) try_moveb(b, w, i, r);    
        for (int i=0; i<N; i++)
            if (G[w][i]) try_movew(w, b, i, r);
        for (int i=0; i<N; i++)
            if (G[b][i])
            for (int j=0; j<N; j++)
                if (G[w][j])
                    try_movewb(b, i, w, j, r);
    }
    int ans = -1;
    for (int i=0; i<0x800; i++)
    {
        int t = PACK(i, bt, wt);
        if (cost[t] != -1 && (ans == -1 || cost[t] < ans))
            ans = cost[t];
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i=0; i<N; i++)
        {
                 scanf("%s", (char *)&G[i]);
                 for (int j=0; j<N; j++)
                     G[i][j]-='0';
                G[i][i]=0;
        }
        scanf("%d%d%d", &wc, &bc, &cc);
        scanf("%d%d%d%d", &wa, &wt, &ba, &bt);
        ba--, bt--, wa--, wt--;
        static int ncase = 0;
        int r = spfa();
        if (r==-1)
            printf("Case #%d: Stalemate\n", ++ncase);
        else
            printf("Case #%d: %d\n", ++ncase, r);
    }
    return 0;
}

