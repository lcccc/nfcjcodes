/*
 * Author: FreePascal
 * Created Time:  2011/10/20 16:06:26
 * File Name: test.cpp
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

int main() {
    return 0;
}

     ret.x+=(u.b.x-u.a.x)*t;
     ret.y+=(u.b.y-u.a.y)*t;
     return ret;
}

Point incenter(Point a, Point b, Point c)
{
    Line u, v;
    double m, n;
    u.a = a;
    m   = atan2( b.y-a.y, b.x-a.x);
    n   = atan2( c.y-a.y, c.x-a.x);
    u.b.x = u.a.x+cos((m+n)/2);
    u.b.y = u.a.y+sin((m+n)/2);
    v.a=b;
    m   = atan2( a.y-b.y, a.x-b.x);
    n   = atan2( c.y-b.y, c.x-b.x);
    v.b.x = v.a.x+cos((m+n)/2);
    v.b.y = v.a.y+sin((m+n)/2);
    return intersection(u, v);
}

Point barycenter(Point a, Point b, Point c)
{
    Line u, v;
    u.a.x=(a.x+b.x)/2;
    u.a.y=(a.y+b.y)/2;
    u.b=c;
    v.a.x=(a.x+c.x)/2;
    v.a.y=(a.y+c.y)/2;
    v.b=b;
    return intersection(u, v);   
}

void work(Point A, Point B, Point C)
{
    Point cc = barycenter(A, B, C);
    Point bb = incenter  (A, B, C);
    //printf("%lf %lf\n",bb.x, bb.y);
    //printf("%lf %lf\n",cc.x, cc.y);
    if ( sgn ( bb.x - cc.x ) == 0 )
    {
              printf("%.5lf %.5lf %.5lf\n", 1.0, 0.0, bb.x);
    }else{
              double k = (bb.y - cc.y) / (bb.x - cc.x);
              double b = bb.y - k * bb.x;
              //printf("k b %lf %lf\n",k,b);
              double aa = k;
              double bb = -1;
              double cc = -b;
              double norm = hypot(k, 1)*sgn(k);
              printf("%.5lf %.5lf %.5lf\n", aa/norm, bb/norm, cc/norm);
    }
}

int main() {
    scanf("%*d");
    Point A, B, C;
    int ncase = 0;
        Point _A = {0, 0}, _B = {2, 0}, _C = {1, sqrt(3)};
        //printf("%lf %lf\n", barycenter(_A, _B, _C));
        //printf("%lf %lf\n", incenter(_A, _B, _C));      
    while (scanf("%d", &ncase)!=EOF)
    {
        printf("%d ", ncase);
        scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
        work(A, B, C);
    }
    return 0;
}

