/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 13时52分59秒
 * File Name: 8161004.cpp
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
const int maxn = 30;
int CS,X,Y,n;
lint k,P,Q,indexp,f[maxn][maxn][maxn];

void prework(){
    memset(f,0,sizeof(f));
    f[0][0][0] = 1;
    for (int i = 1; i < 20; i++)
        for (int j = 0; j <= 20; j++)
            for (int k = 0; k <= 20 - j; k++){
                if (j + k > i) break;
                f[i][j][k] = 8 * f[i - 1][j][k];
                if (j > 0) f[i][j][k] += f[i - 1][j - 1][k];
                if (k > 0) f[i][j][k] += f[i - 1][j][k - 1];
            }
}
lint calc(lint k){
    int a[maxn],n;
    lint cnt;
    n = 0; cnt = 0;
    while (k > 0){
        a[++n] = k % 10;
        k = k / 10;
    }
    while (n < 19) a[++n] = 0;
    int x = X,y = Y;
    for (int i = n; i > 0; i--){
        if (a[i] <= 4) cnt += a[i] * f[i - 1][x][y];
        else if (a[i] <= 7){
            cnt += (a[i] - 1) * f[i - 1][x][y];
            if (x != 0) cnt += f[i - 1][x - 1][y];
        }
        else {
            cnt += (a[i] - 2) * f[i - 1][x][y];
            if (x != 0) cnt += f[i - 1][x - 1][y];
            if (y != 0) cnt += f[i - 1][x][y - 1];
        }
        if (a[i] == 4) x--;
        if (a[i] == 7) y--;
        if (x < 0 || y < 0) break;
    }
    return cnt;
}
bool check(lint k){
    int a[maxn],n = 0;
    int x,y;
    while (k > 0){
        a[++n] = k % 10;
        k = k / 10;
    }
    while (n < 19) a[++n] = 0;
    x = 0; y = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 4) x++;
        else if (a[i] == 7) y++;
    if (x == X && y == Y) return true;
    else return false;
}

int main() {
    prework();
    scanf("%d",&CS);
    int cs = 0;
    while (CS--){
        printf("Case #%d:\n",++cs);
        cin>>P>>Q>>X>>Y;
        indexp = calc(P + 1);
        scanf("%d",&n);
        while (n--){
            cin>>k;
            k--;
            //cout<<k<<endl;
            lint ans = -1;
            unsigned long long l,r;
            lint mid;
            l = P + 1; r = Q;
            //cout<<k<<" "<<indexp<<endl;
            while (l <= r){
                mid = (l + r) >> 1;
                //cout<<mid<<": ";
                lint index = calc(mid);
                //cout<<index<<endl;
                if (k + indexp == index){
                    if (check(mid)) ans = mid;
                }
                if (k + indexp < index) r = mid - 1;
                else l = mid + 1;
            }
            if (ans == -1) puts("Nya!");
            else cout<<ans<<endl;
        }
    }
    return 0;
}

