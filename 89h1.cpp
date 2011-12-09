/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 17时00分12秒
 * File Name: 89h1.cpp
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

typedef long long lint;
const lint maxint = ~0ull>>2;
const int maxn = 35 + 10;
int CS,n,m;
lint a[maxn],total,tmp;
bool visit[maxn];
struct node{
    lint x;
    int cnt;
};
node ans;

lint absolute(lint x){
    if (x < 0) return -x;
    else return x;
}
void dfs(int k,lint x,int dep){
    if (dep == 0){
        if (absolute(x) < absolute(tmp)) tmp = x;
        return ;
    }
    if (k > n){
        return;
    }
    dfs(k + 1,x,dep);
    dfs(k + 1,x + a[k],dep - 1);
}

int main() {
    while (scanf("%d",&n) != EOF){
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin>>a[i];
        total = 0;
        for (int i = 1; i <= n; i++) total += a[i];
        ans.x = maxint; ans.cnt = maxint;
        m = min(n,18);
        for (int i = 1; i <= m; i++){
            memset(visit,0,sizeof(visit));
            tmp = maxint;
            dfs(1,0,i);
            if (tmp < maxint){
                if (ans.x > absolute(tmp)){
                    ans.x = absolute(tmp); ans.cnt = i;
                }
            }
        }
        for (int i = 1; i <= n - m; i++){
            tmp = maxint;
            dfs(1,0,i);
            if (tmp < maxint){
                if (ans.x > absolute(total - tmp)){
                    ans.x = absolute(tmp); ans.cnt = n - i;
                }
            }
        }
        cout<<ans.x<<" "<<ans.cnt<<endl;
    }
    return 0;
}

