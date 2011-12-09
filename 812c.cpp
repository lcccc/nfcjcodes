/*
 * Team : FreePascal
 * Created Time:  2011年08月12日 星期五 15时16分13秒
 * File Name: 812c.cpp
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

int N, M;
int G[50][50];
int Ans[50];
int bitmap[50];
int map[50][50];
int ans;
int tot;
int place[50][50];
struct Pa{
    int x, y;
    int v;
    bool operator <(const Pa & b) const {
        return v<b.v || v==b.v && 
            (  x<b.x || x==b.x &&
            (  y<b.y )
                     );
    }
}P[10010];



bool check(int x, int y)
{
    int x1 = (1<<(y-3)) | (1<<(y+3));
    if ((x >= 1) && (bitmap[x-1] & x1)) return false;
    if ((x < N-1) && (bitmap[x+1] & x1)) return false;
    int x2 = (1<<(y-1)) | (1<<(y+1));
    if ((x >= 3) && (bitmap[x-3] & x2)) return false;
    if ((x < N-3) && (bitmap[x+3] &x2)) return false;
    return true;
}

#define try_select(a, b, z)\
    do{\
        for (int i = place[a][b]+1; i<tot; i++)\
            dfs(P[i].x, P[i].y, score z);\
    }while(0)

#define select(x, y)\
    do{\
    bitmap[x] ^= (1<<y);\
    try_select(x, y, +G[x][y]);     \
    bitmap[x] ^= (1<<y);\
    }while(0);

#define unselect(x, y)\
    do{\
     try_select(x, y, );     \
    }while(0);

int cnt;
int lastans;
bool stop = false;
int times;
void dfs (int x, int y, int score)
{
    if (stop) return;
    if (++cnt > times) {
        if (ans > lastans) { lastans = ans; cnt = 0;}   
        else {times /= 2; if (times == 0) {stop = true; return ;}}
    } 
    if (map[x][y] > 0)  { try_select(x, y, +G[x][y]); }
    if (map[x][y] == 0) { if(check(x, y)) select(x, y);}
    if (map[x][y] <= 0) { try_select(x, y, ); } 
    if (ans < score){
          ans=score;    
          memcpy(Ans, bitmap, sizeof(Ans));
    }
}

int main() 
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &M);
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
             scanf("%d", &G[i][j]), map[i][j] = 0;
        memset(Ans,   0,  sizeof(Ans));
        memset(bitmap, 0, sizeof(bitmap));

        int Q;
        scanf("%d", &Q);
        for (int i=0; i<Q; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            map[u][v]=1;
            bitmap[u] |= (1<<v);
        }
        scanf("%d", &Q);
        for (int i=0; i<Q; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            map[u][v]=-1;
        }
        tot = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
            {
                P[tot].x = i;
                P[tot].y = j;
                P[tot].v = G[i][j];
                tot++;
            }
        sort(P, P+tot);
        for (int i=0; i<tot; i++)
            place[P[i].x][P[i].y] = i;
        static int ncase = 0;
        ans = 0;
        cnt = 0;
        lastans = 0;
        stop = false;
        times = 1<<16;
        dfs(P[0].x, P[0].y, 0);
                

        printf("Case %d: %d\n", ++ncase, ans);
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
            {
                if (Ans[i] % 2)
                    printf("%d %d\n", i, j);
                Ans[i]>>=1;
            }
            
    }
    return 0;
}

