/*
 * Team : FreePascal
 * Created Time:  2011年08月20日 星期六 15时10分09秒
 * File Name: 820g.cpp
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
const double eps = 1e-8;
int sgn(double d)
{
    if( d > eps) return 1;
    if( d < -eps) return -1;
    return 0;
}
#define Gen template <typename T>
#define op(__, _) operator _(const __&a, const __&b)

Gen struct Point {T x, y;};

Gen bool op(Point<T>, <)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);   
}
    
Gen struct Line{Point <T> a, b;};

Gen T mul(Point <T> a, Point <T> b, Point <T> c)
{
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);   
}

Gen double dis (Point <T> a, Point <T> b){
    return hypot(a.x-b.x, a.y-b.y);
}

Gen T sqr(T a){return a*a;}

Gen T dis2 (Point <T> a, Point <T> b){
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}


const int maxn = 100011;

int dn, hd[maxn];
int un, hu[maxn];
Gen void get_convex_hull(Point<T> *p, int n, int *out, int &m)
{
    sort(p, p+n);   
    dn = un = 2;
    hd[0] = hu[0] = 0; hd[1] = hu[1] = 1;
    for (int i=2; i<n; i++){
        while (dn>1 && sgn(mul(p[hd[dn-1]], p[hd[dn-2]], p[i]))>=0) dn--;
        while (un>1 && sgn(mul(p[hu[un-1]], p[hu[un-2]], p[i]))<=0) un--;
        hd[dn++] = hu[un++] = i;
    }
    m=0;
    for (int i=0; i<dn-1; i++) out[m++] = hd[i];
    for (int i=un-1; i>0; i--) out[m++] = hu[i];
}

Point <long long> partA[maxn];
Point <long long> partB[maxn];
int h1[maxn], h2[maxn];
int N, N1, N2;
int T;


int main() {
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N); 
        for (int i=0; i<N; i++) scanf("%I64d%I64d", &partA[i].x, &partA[i].y);
        for (int i=0; i<N; i++) scanf("%I64d%I64d", &partB[i].x, &partB[i].y);
        get_convex_hull(partA, N, h1, N1);
        get_convex_hull(partB, N, h2, N2);
        long long ans = dis2(partA[h1[0]], partB[h2[0]]);
        for (int i=0; i<N1; i++)
            for (int j=0; j<N2; j++)
                ans = min(ans, dis2(partA[h1[i]], partB[h2[j]]));
        printf("%.3lf\n", sqrt(ans*1.0));
    }
    return 0;
}


