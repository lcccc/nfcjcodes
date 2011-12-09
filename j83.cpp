/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/3 16:01:10
 * File Name: j83.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 20 + 50;
struct node {
    int x,y;
}a[5];
int x[maxn],y[maxn],p[3][2];
bool flag;

bool check(){
    int visit[5];
/*
    int cnt = 0;
    for (int i = 1; i <= 20; i++){
        if (x[i] == 2) cnt++;
        if (y[i] == 2) cnt++;
        if (x[i] > 2 || y[i] > 2) return false;
    }
    if (cnt == 2) return true;
    else return false;
*/
/*
    memset(visit,0,sizeof(visit));
    for (int i = 1; i <= 4; i++)
        for (int j = i + 1; j <= 4; j++)
            if (a[i].x == a[j].x || a[i].y == a[j].y){
                visit[i]++;
                visit[j]++;
            }
    for (int i = 1; i <= 4; i++)
        if (visit[i] != 1) return false;
    return true;
*/
    for (int i = 1; i <= 4; i++){
//        if (x[a[i].x] > 2) return false;
//        if (y[a[i].y] > 2) return false;
//        if (x[a[i].x] != 2 && y[a[i].y] != 2) return false;
//        if (x[a[i].x] == 2 && y[a[i].y] == 2) return false;
        if (x[a[i].x] + y[a[i].y] != 3) return false;
    }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (i != j && a[i].x == a[j].x && a[i].y == a[j].y) return false;
    return true;
}
void dfs(int k,int dep){
    if (flag) return;
    if (dep == 0){
        if (check()){
            flag = true;
            for (int i = 1; i <= 4; i++){
                printf("%d %d\n",a[i].x,a[i].y);
            }
        }
        return ;
    }
    if (k > 4) return ;
    for (int i = 1; i <= 4; i++)
        if (i != k){
            int tx,ty;
            if (a[i].x != a[k].y && a[i].y != a[k].y){
                tx = a[k].x; ty = a[k].y;
                x[tx]--; x[a[i].x]++;
                a[k].x = a[i].x;
                dfs(k + 1,dep - 1);
                x[a[i].x]--;
                x[tx]++;
                a[k].x = tx;

                a[k].y = a[i].y;
                y[ty]--; y[a[i].y]++;
                dfs(k + 1,dep - 1);
                a[k].y = ty;
                y[ty]++; y[a[i].y]--;
            }
            else if (a[i].x == a[k].x){
                for (int j = 1; j <= 4; j++){
                    tx = a[k].x; ty = a[k].y;
                    if (ty + j <= 20){
                        y[ty]--; y[ty + j]++;
                        a[k].y = ty + j;
                        dfs(k + 1,dep - 1);
                        y[ty]++; y[ty + j]--; 
                        a[k].y = ty;
                    }
                    if (ty - j > 0){
                        y[ty]--; y[ty - j]++;
                        a[k].y = ty - j;
                        dfs(k + 1,dep - 1);
                        a[k].y = ty;
                        y[ty - j]--; y[ty]++;
                    }
                }
            }
            else{
                for (int j = 1; j <= 4; j++){
                    tx = a[k].x; ty = a[k].y;
                    if (tx + j <= 20){
                        x[tx]--; x[tx + j]++;
                        a[k].x = tx + j;
                        dfs(k + 1,dep - 10);
                        a[k].x = tx;
                        x[tx + j]--; x[tx]++;
                    }
                    if (tx - j > 0){
                        x[tx]--; x[tx - j]++;
                        a[k].x = tx - j;
                        dfs(k + 1,dep - 1);
                        a[k].x = tx;
                        x[tx - j]--; x[tx]++;
                    }
                }
            }
        }
    dfs(k + 1,dep);
}

int main() {
    freopen("a.in","r",stdin);
    while (scanf("%d%d",&a[1].x,&a[1].y) != EOF){
        flag = false;
        for (int i = 2; i <= 4; i++) scanf("%d%d",&a[i].x,&a[i].y);
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for (int i = 1; i <= 4; i++){
            x[a[i].x]++; y[a[i].y]++;
        }
        for (int i = 0; i <= 2; i++){
            dfs(1,i);
            if (flag) break;
        }
    }
    return 0;
}

