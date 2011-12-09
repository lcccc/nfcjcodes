/*
 * Team : FreePascal
 * Created Time:  2011年08月08日 星期一 12时53分08秒
 * File Name: 88j.cpp
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
const lint maxn = 1000;
lint n,m,k,ans,a[maxn][maxn],sum[maxn][maxn];
struct node{
    int x1,y1,x2,y2;
    node(int _x1,int _y1,int _x2,int _y2):
        x1(_x1),y1(_y1),x2(_x2),y2(_y2) {}
    node() {}
};
vector<node> b;
bool cmp(node a,node b){
    return a.x1 < b.x1 || a.x1 == b.x1 && a.x2 < b.x2 || 
        a.x1 == b.x1 && a.x2 == b.x2 && a.y1 < b.y1||
        a.x1 == b.x1 && a.x2 == b.x2 && a.y1 == b.y1 && a.y2 < b.y2;
}

int main() {
    freopen("j.in","r",stdin);
    while (scanf("%lld",&n) != EOF){
        if (n == 0) break;
        scanf("%lld%lld",&m,&k);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) scanf("%lld",&a[i][j]);
        memset(sum,0,sizeof(sum));
        sum[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        ans = maxint;
        b.clear();
        for (int x1 = 1; x1 <= n; x1++)
            for (int y1 = 1; y1 <= m; y1++)
                for (int x2 = x1; x2 <= n; x2++)
                    for (int y2 = y1; y2 <= m; y2++){
                        if ((y2 - y1 + 1) * (x2 - x1 + 1) > k) break;
                        if ((y2 - y1 + 1) * (x2 - x1 + 1) < k) continue;
                        if (x1 != 1 && x2 != n && y1 != 1 && y2 != m) continue;
                        if (y1 == 1 && y2 == m && x1 != 1 && x2 != n) continue;
                        if (x1 == 1 && x2 == n && y1 != 1 && y2 != m) continue;
                        lint tmp = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
                        //printf("%d\n",tmp);
                        if (tmp == ans){
                            b.push_back(node(x1,y1,x2,y2));
                        }
                        if (tmp < ans){
                            ans = tmp;
                            b.clear();
                            b.push_back(node(x1,y1,x2,y2));
                        }
                    }
        printf("%lld %d\n",ans,b.size());
        sort(b.begin(),b.end(),cmp);
        for (int i = 0; i < (int)b.size(); i++) printf("%d %d %d %d\n",b[i].x1,b[i].x2,b[i].y1,b[i].y2);
    }
    return 0;
}

