/*
 * Author: FreePascal
 * Created Time:  2011/9/3 13:36:07
 * File Name: 931001.cpp
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


struct node {
    int a, b, c, d;
    bool operator < (const node &n) const {
        #define cmp(a)\
        if (a < n.a) return true;\
        if (a > n.a) return false;
        cmp(a);
        cmp(b);
        if (d > n.d) return true;
        if (d < n.d) return false;
        return false;      
        #undef cmp
    }    
}a[10010] = { {0,0,0,0} };

long long F[10010];
int N;

long long getF(int i)
{
    return (F[i]!=-1) ? F[i] :
    ({
        F[i] = 0;
        for (int j=0; j<=N; j++)
        {
            if (i == j) continue;
 
            {
               int _1 = (a[i].a >  a[j].a) + (a[i].b >  a[j].b);
               int _2 = (a[i].a >= a[j].a) + (a[i].b >= a[j].b);
               if ( _2 == 2 && _1 >= a[i].d)
                  if (_1!=0 || i<j) F[i] = max(F[i], getF(j) + a[i].c);
                
            }
            {
               int _1 = (a[i].a >  a[j].b) + (a[i].b >  a[j].a);
               int _2 = (a[i].a >= a[j].b) + (a[i].b >= a[j].a);
               if ( _2 == 2 && _1 >= a[i].d)
                  if (_1!=0 || i<j)   F[i] = max(F[i], getF(j) + a[i].c);
            }    
        }
        F[i]; 
    });   
}
int main() 
{
    freopen("931001.out", "w", stdout);
    while ( ~scanf("%d", &N) && N )
    {
        for (int i=1; i<=N; i++)
            scanf("%d%d%d%d", &a[i].a, &a[i].b, &a[i].c, &a[i].d);
        fill(F, F+N+1, -1LL);
        F[0] = 0;
        long long ans = 0;
        for (int i=1; i<=N; i++)
            ans = max(getF(i), ans);
        printf("%I64d\n", ans);
    }
    return 0;
}

