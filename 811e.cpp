/*
 * Team : FreePascal
 * Created Time:  2011年08月11日 星期四 14时16分48秒
 * File Name: 811e.cpp
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

int T, N;
int G[100][100];
int choose[100];
int nm[100];
int sum[100];
int ans = 0;

void dfs(int index, int d, int l, int r, int nm, int score = 0)
{
    if (index == N) {
        ans = max(ans, score);
        //for (int i=0; i<N; printf("%3d\n", G[i][choose[i]]), i++)
            //for (int j=0; j<N; j++)
            //{
                //if (choose[i] == j) putchar('*');
                //else putchar('.');   
            //}
        //printf("-----------------------------\n");
        return;
    }
    int kd = d, kl = l, kr = r, ki = 1, rel = G[index][index];
    for (int i=0; i<N; i++)
    {
        if ( !(kd & 1) && !(kl & 1) && !(kr & 1) )
        {
            //choose[index] = i;
            int scr = score + G[index][i];
            if (scr + nm <= ans) continue;
            dfs(index+1, d|ki, (l|(ki))  << 1, (r|(ki)) >>1, nm-rel, scr);
        }
        kd >>=1;
        kl >>=1;
        kr >>=1;
        ki <<=1;
    }
}

int main() 
{

    
    for (scanf("%d", &T); T--;)
    {
        scanf("%d", &N);      
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                scanf("%d", &G[N-i-1][N-j-1]); 
        //for (int i=0; i<N; i++, puts(""))
            //for (int j=0; j<N; j++)
                //printf("%d ", G[i][j]);
        int sum = 0;
        for (int i=0; i<N; i++)
            sum += G[i][i];
        ans = 0;
        dfs(0, 0, 0, 0, sum, 0);
        printf("%d\n", ans);
    }
    return 0;
}

