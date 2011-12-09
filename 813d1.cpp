/*
 * Team : FreePascal
 * Created Time:  2011年08月13日 星期六 13时17分22秒
 * File Name: 813d.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())

typedef long long lint;
const int maxn = 50;
const int maxm = 1 << 21;
int CS,n,len;
lint f[2][maxm];
struct que{
    int state,len;
    que(int _state,int _len): state(_state),len(_len) {};
};
queue<que> q;
struct node{
    int l,r;
}pos[maxn];
char s[maxn],st[maxn];
/*
void spfa(){
    int state,len,now;
    memset(f,0,sizeof(f));
    q.push(que(0,0)); f[0][0] = 1;
    while (!q.empty()){
        que tmp = q.front(); q.pop();
        state = tmp.state; len = tmp.len + 1;
        printf("%d\n",state);
        for (int i = 0; i < cnt; i++){
            if (st[i] > s[len - 1]) break;
            for (int j = pos[i].l; j <= pos[i].r; j++)
                if ((state & (1 << j)) == 0){
                    now = state | (1 << j);
                    f[len][now] += f[len - 1][state];
                    q.push(que(now,len));
                    break;
                }
        }
    }
}
*/

lint calc(int x){
    lint sum;
    for (int i = 1; i <= x; i++) sum = sum * i;
    return sum;
}
void dpwork(){
    int t;
    memset(f,0,sizeof(f));
    t = 0;
    for (int i = 0; i < (1 << n); i++) f[t][i] = 0;
    f[0][0] = 1;
    for (int i = 1; i <= len; i++){
        t = t ^ 1;
        //for (int j = 1; j < (1 << n) - 1; j++)
        for (int j = (1 << n) - 1; j >= 0; j--){
            f[t][j] = 0;
            for (int k = 0; k < n; k++){
                if (st[k] > s[len - 1]) break;
                for (int p = pos[k].l; p <= pos[k].r; p++)
                    if ((j & (1 << p)) == 0){
                        f[t][j | (1 << p)] +=  f[t ^ 1][j];
                        //f[t][j] += f[t ^ 1][j | (1 << p)];
                        //cout<<f[j]<<endl;
                    }
            }
        }
    }
}

int main() {
    scanf("%d",&CS);
    while (CS--){
        scanf("%s",s);
        len = strlen(s);
        strcpy(st,s);
        sort(st,st + len);
        n = 0;
        memset(pos,0,sizeof(pos));
        pos[n].l = 0;
        for (int i = 1; i < len; i++){
            if (st[i] == st[i - 1]) pos[n].r = i;
            else{
                pos[++n].l = i; pos[n].r = i;
            }
        }
        n++;
        //spfa();
        dpwork();
        cout<<f[1][(1 << n) - 1]<<endl;
    }
    return 0;
}

