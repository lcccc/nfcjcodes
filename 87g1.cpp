/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 15时16分54秒
 * File Name: 87g.cpp
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
const int maxn = 30010;
int dn, hd[maxn], un, hu[maxn];

template <typename T>
int sgn(T f)
{
    if (f>1e-6) return 1;
    if (f<-1e-6) return -1;
    return 0;
}
struct point;
extern point inf;

struct point {
    long long x, y, w;
    long long operator *(const point &b) const {
        return x*b.y-y*b.x;
    }
    point operator -(const point &b) const {
        return (point){x-b.x, y-b.y};   
    }
    bool operator <(const point &b) const {
        return dis2(inf) < b.dis2(inf) || !(b.dis2(inf) < dis2(inf))
            &&(
            x<b.x || (x==b.x && 
                ( y<b.y || y==b.y)));
    }
    
    long long dis2(const point &b) const {
        return (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y);
    }
};
point inf={10000000000000ll, 1000000000000ll};
void get_convex_hull(point *p, int n, point *pol, int &m)
{
    if (n<=3)
    {
        m=0;
        for (int i=0; i<n; i++)
         pol[m++]=p[i];
        return ;   
    }
    sort(p, p+n);
    dn = un = 2;
    
    hd[0]=hu[0]=0;
    hd[1]=hu[1]=1;
    for (int i=2; i<n; i++){
        for (;dn>1 && sgn((p[hd[dn-1]]-p[hd[dn-2]])*(p[i]-p[hd[dn-1]]))<=0; dn--);
        for (;un>1 && sgn((p[hu[un-1]]-p[hu[un-2]])*(p[i]-p[hu[un-1]]))>=0; un--);
        hd[dn++]=hu[un++]=i;
    }
    m=0;
    for (int i=0; i<dn-1; i++)
        pol[m++] = p[hd[i]];
    for (int i=un-1; i>0; i--)
        pol[m++] = p[hu[i]];
}

int N1, N2;
point a[30001], b[30001];
point ha[30001], hb[30001];
int hn1, hn2;

int next(int a, int b)
{
    if (a==b) return 0;
    return a;   
}

long long tri(point *a, int a1, point *b, int &b1, int bn)
{
    long long ret = 0;
    long long cbn = bn;
    while (bn > 0)
    {
        int x1 = b1 + bn/3 + 2;
        int x2 = x1 + bn/3 + 2;
        x1 %= cbn;
        x2 %= cbn;
        long long q1[] = {a[a1].dis2(b[b1]), a[a1].dis2(b[x1]), a[a1].dis2(b[x2])};
        int ind[]={x2, b1, x1};
        int l = max_element(q1, q1+3) - q1;
        ret = max(ret, q1[l]);
        b1 = ind[l];
        bn = bn * 2 / 3;
    }   
    return ret;
    
}
#include "ctime"
int main() 
{
    int T;
    srand(time(0));
    scanf("%d", &T);
    while (T--)
    {
        int N;
        scanf("%d", &N);
        N1=N2=0;
        for (int i=0; i<N; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);   
            a[N1].x=u; a[N1].y=v; a[N1].w=w; N1++;

            /*
            else
            {
                b[N2].x=u; b[N2].y=v; N2++;   
            }*/
        }
        sort(a, a+N1);
            long long ans2 = 0;
        if (N1 < 1000)
            for (int i=0; i<N1; i++)
                for (int j=0; j<N1; j++)
                                if (a[i].w != a[j].w)
                {
                    long long l=a[i].dis2(a[j]);
                   if (l >= ans2) ans2 = l;
                  // if (a[i].dis2(a[j]) >= ans2 - ans2/3);
                }
        else
        {

            for (int i=0; i<N1; i++)
            {
                static int p[30001];
                for (int i=0; i<N; i++)
                    p[i] = i;
                
                random_shuffle(p, p+N);
                for (int j=0; j<1000; j++)
                    if (a[i].w != a[p[j]].w)
                    {
                        long long l=a[i].dis2(a[p[j]]);
                       if (l >= ans2) ans2 = l;
                  // if (a[i].dis2(a[j]) >= ans2 - ans2/3);
                       else break;
                    }
            }
        }
        /*
        get_convex_hull(a, N1, ha, hn1);
        get_convex_hull(b, N2, hb, hn2);
        long long ans2=0;
        int xx = hn1/2;
        int yy = hn2/2;
        int cnt = 100;
        while(cnt--)
        {
            ans2 = max (ans2, tri(ha, xx, hb, yy, hn2));
            ans2 = max (ans2, tri(hb, yy, ha, xx, hn1));            
        }*/
        printf("%.0lf\n", floor(sqrt(ans2*1.0)+1e-6));
    }
    return 0;
}

