/*
 * Team : FreePascal
 * Created Time:  2011年08月23日 星期二 12时25分59秒
 * File Name: 823d.cpp
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

const int maxn = 20;
int n,path[maxn],cnt;
bool a[maxn][maxn];
bool visit[maxn];

void dfs(int k,int s){
    visit[k] = true;
    path[cnt++] = k;
    if (a[k][s]){
        for (int i = 0; i < cnt; i++) printf("%d",path[i]);
        printf("\n");
    }
    for (int i = s + 1; i < n; i++)
        if (!visit[i] && a[k][i]){
            dfs(i,s);
        }
    visit[k] = false;
    cnt--;
}

int main() {
    while (scanf("%d",&n) != EOF){
        memset(a,0,sizeof(a));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                int x;
                scanf("%d",&x);
                if (x == 1) a[i][j] = true;
                else a[i][j] = false;
            }
        for (int i = 0; i < n; i++){
            memset(visit,0,sizeof(visit));
            cnt = 0;
            dfs(i,i);
        }
        printf("\n");
    }
    return 0;
}

