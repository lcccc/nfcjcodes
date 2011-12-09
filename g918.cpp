/*
 * Author: FreePascal
 * Created Time:  2011-9-18 14:41:53
 * File Name: g.cpp
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

const int maxn = 50000 + 10;
int CS,n,m,ar[maxn * 4];
char st[maxn];

int lowbit(int t){
    return t & (-t);
}
void add(int i,int v){
    for (; i <= n; ar[i] += v, i += lowbit(i));
}
int sum(int i){
    int s = 0;
    for ( ; i > 0; s += ar[i], i -= lowbit(i));
    return s;
}

int main() {
    scanf("%d",&CS);
    int cs = 0;
    while (CS--){
        scanf("%d%d",&n,&m);
        scanf("%s",st);
        //out(st);
        memset(ar,0,sizeof(ar));
        for (int i = 3; i <= n; i++){
            if (st[i - 3] == 'w' && st[i - 2] == 'b' && st[i - 1] == 'w'){
                add(i,1);
                //out(i);
            }
        }
        //for (int i = 1; i <= n; i++) out(ar[i]);
        printf("Case %d:\n",++cs);
        for (int i = 0; i < m; i++){
            int c;
            scanf("%d",&c);
            if (c == 0){
                int l,r;
                scanf("%d%d",&l,&r);
                l++; r++;
                printf("%d\n",sum(r) - sum(l+1 ));
            }
            else{
                int x; char s[2];
                scanf("%d%s",&x,s);
                if (st[x - 2] == 'w' && st[x - 1] == 'b'){
                    if (st[x] == 'b' && s[0] == 'w') add(x + 1,1);
                    else if (st[x] == 'w' && s[0] == 'b') add(x + 1,-1);
                }
                if (st[x - 1] == 'w' && st[x + 1] == 'w'){
                    if (st[x] == 'w' && s[0] == 'b') add(x + 2,1);
                    else if (st[x] == 'b' && s[0] == 'w') add(x + 2,-1);
                }
                if (st[x + 1] == 'b' && st[x + 2] == 'w'){
                    if (st[x] == 'b' && s[0] == 'w') add(x + 3,1);
                    else if (st[x] == 'w' && s[0] == 'b') add(x + 3,-1);
                }
                st[x] = s[0];
            }
        }
    }
    return 0;
}

