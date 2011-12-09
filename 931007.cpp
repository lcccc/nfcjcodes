/*
 * Author: FreePascal
 * Created Time:  2011/9/3 16:13:09
 * File Name: 931007.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 1000 + 100;
int x[maxn],y[maxn];
int n,r,ans;
struct node{
    int x1,y1,x2,y2,cnt;
}a[5];

void solve(int k){
    a[k].cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[k].x1 <= x[i] && a[k].y1 <= y[i] && a[k].x2 >= x[i] && a[k].y2 >= y[i]) a[k].cnt++;
    if (a[k].cnt > ans) ans = a[k].cnt;
}

int main() {
    while (scanf("%d%d",&n,&r) != EOF){
        for (int i = 0; i < n; i++) scanf("%d%d",&x[i],&y[i]);
        for (int i = 0; i < n; i++){
            a[0].x1 = x[i]; a[0].y1 = y[i]; 
            a[0].x2 = x[i] + r; a[0].y2 = y[i] + r;
            a[1].x1 = x[i] - r; a[1].y1 = y[i];
            a[1].x2 = x[i]; a[1].y2 = y[i] + r;
            a[2].x1 = x[i] - r; a[2].y1 = y[i] - r;
            a[2].x2 = x[i]; a[2].y2 = y[i];
            a[3].x1 = x[i]; a[3].y1 = y[i] - r;
            a[3].x2 = x[i] + r; a[3].y2 = y[i];
            a[4].x1 = x[i] - r / 2; a[4].y1 = y[i] - r / 2;
            a[4].x2 = x[i] + r / 2; a[4].y2 = y[i] + r / 2;
            if (r % 2 == 1){
                a[4].x2++; a[4].y2++;
            }
            for (int j = 0; j < 5; j++){
                solve(j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

