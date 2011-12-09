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
    if (f<1e-6) return -1;
    return 0;
}
struct point {
    long long x, y;
    long long operator *(const point &b) const {
        return x*b.y-y*b.x;
    }
    point operator -(const point &b) const {
        return (point){x-b.x, y-b.y};   
    }
    bool operator <(const point &b) const {
        return x<b.x || (x==b.x && y<b.y);
    }
    
    long long dis2(const point &b) const {
        return (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y);
    }
};
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
int main() 
{
    int T;
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
            if (w==0)
            {
                a[N1].x=u; a[N1].y=v; N1++;
            }
            else
            {
                b[N2].x=u; b[N2].y=v; N2++;   
            }
        }
        get_convex_hull(a, N1, ha, hn1);
        get_convex_hull(b, N2, hb, hn2);
        long long ans2=0;
        int xx = min_element(ha, ha+hn1)-ha;
        int yy = max_element(hb, hb+hn2)-hb;
        
        for (int t = xx; ; t=next(t+1, hn1))
        {    
            
                   long long ans =0;
                   for(int s = yy; ; s=next(s+1, hn2))
                   {
                          long long dis2 = ha[t].dis2(hb[s]);
                           if (dis2 >= ans)
                               ans = dis2;
                           else
                                  break;
                           if ( next(s+1, hn2)==yy) break;
                   }
                   for(int s = yy-1; ; s=(s-1)==-1?(hn2-1):(s-1))
                   {
                          long long dis2 = ha[t].dis2(hb[s]);
                           if (dis2 >= ans)
                               ans = dis2;
                           else
                               break;
                           if ( next(s+1, hn2)==yy) break;
                   }
                   ans2 = max(ans, ans2);
                   if ( next(t+1, hn1) == xx) break;
                //for (int s = yy; ; s=next(s+1, hn2))
                //{
                           //long long dis2 = ha[t].dis2(hb[s]);
                           //if (dis2 >= ans)
                               //ans = dis2;
                           //ans2 = max(ans, ans2);
                           //if ( next(s+1, hn2)==yy) break;
                // 
                //}
                //if ( next(t+1, hn1) == xx) break;
        }
        /*
        for (int i=0; i<hn1; i++)
            for (int j=0; j<hn2; j++)
            {
                //printf("%lld %lld %lld %lld %lld\n", ha[i].x, ha[i].y, hb[j].x, hb[j].y, ha[i].dis2(hb[j]));
                ans2 = max(ans2, ha[i].dis2(hb[j]));
            }
        */
        printf("%.0lf\n", sqrt(ans2*1.0)-0.5, ans2);
    }
    return 0;
}

