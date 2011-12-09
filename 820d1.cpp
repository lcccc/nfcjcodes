/*
 * Team : FreePascal
 * Created Time:  2011年08月20日 星期六 12时42分28秒
 * File Name: 820d.cpp
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

#define Gen template <typename T>
Gen struct Point {T x, y;};

Gen struct Line{Point <T> a, b;};

Gen double mul(Point <T> a, Point <T> b, Point <T> c)
{
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);   
}

Gen double dis (Point <T> a, Point <T> b){
    return hypot(a.x-b.x, a.y-b.y);
}
Gen T sqr(T a){return a*a;}
Gen double dis2 (Point <T> a, Point <T> b){
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

Gen double len (Line <T> a)
{
    return dis(a.a, a.b);   
}

double min_dis;

Gen Point <T> inter(Line<T> u, Line <T> v)
{
    Point <T> ret = u.a;
    double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
        /   ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x += (u.b.x-u.a.x)*t;
    ret.y += (u.b.y-u.a.y)*t;
    return ret;
}

Gen Point<T> inpoint(Point <T> a, Point <T> b, Point <T>c)
{
    Line <T> u, v;
    double m, n;   
    u.a=a;
    m=atan2(b.y-a.y, b.x-a.x);
    n=atan2(c.y-a.y, c.x-a.x);
    u.b.x = u.a.x+cos((m+n)/2);
    u.b.y = u.a.y+sin((m+n)/2); 
    v.a=b;
    m=atan2(a.y-b.y, a.x-b.x);
    n=atan2(c.y-b.y, c.x-b.x);
    v.b.x = v.a.x+cos((m+n)/2);
    v.b.y = v.a.y+sin((m+n)/2); 
    return inter(u, v);
}

Gen double disTo(Point <T>a, Point <T>b, Point <T>c)
{
    return fabs( mul(a,b,c) ) / dis(b, c);
}

Gen double disInter(Point <T>a, Point <T> b, Point <T>c)
{
    return fabs( mul(a,b,c) ) / (dis(a, b) + dis(b, c) + dis(c, a));
}

Gen int sgn(T x) { return (x>1e-6)-(x<-1e-6);}

double getTheta(double A, double B, double angle)
{
    double l = 0.0001, r = angle;
    double ratio = A/B;
    while (fabs(l-r) > 1e-6)
    {
        double mid = (l+r) / 2;
        int k = sgn(sin(mid) / sin(angle-mid) - ratio);
        if (k == 1) r = mid;
        else if (k==-1) l = mid;
        else return mid;
    }
    return l;
}
const double pi = acos(-1.0);
Gen Line <T> PointAngle(Point <T> base, double angle)
{
    return (Line<T>){base, (Point <T>){base.x+cos(angle),  base.y+sin(angle)}};
}


Gen Point <T> get_refl(const Point <T> &p, const Point <T> &p1, const Point <T> &p2){
    double len = dis2(p1, p2);
    double d   = 2*(mul(p, p1, p2) / len);
    return (Point <T>){ p.x+d*(p2.y-p1.y) ,  p.y-d*(p2.x-p1.x) };
}
        
Gen Point <T> outer(const Point <T> &a, const Point <T>&b, const Point <T> &c)
{
    Line <T> u, v;
    u.a.x = (a.x+b.x)/2;
    u.a.y = (a.y+b.y)/2;
    v.a.x = (a.x+c.x)/2;
    v.a.y = (a.y+c.y)/2;
    u.b.x = u.a.x-a.y+b.y;
    u.b.y = u.a.y+a.x-b.x;
    v.b.x = v.a.x-a.y+c.y;
    v.b.y = v.a.y+a.x-c.x;
    return inter(u, v);
}

Gen Point <T> Bary(Point<T> a,Point<T> b,Point<T> c){
    Line <T> u, v;
    u.a.x = (a.x+b.x)/2;
    u.a.y = (a.y+b.y)/2;
    u.b=c;
    v.a.x = (a.x+c.x)/2;
    v.a.y = (a.y+c.y)/2;
    v.b=b;
    return inter(u, v);
}

Gen Point <T> SolvePoint(Point<T> a,Point<T> b,Point<T> c){
    Point <T>center = Bary(a,b,c);
    Point <T> centerref[] = {
           get_refl(center, b, c),
           get_refl(center, c, a),
           get_refl(center, a, b),
    };
    return outer(centerref[0], centerref[1], centerref[2]);
}


int main() {
    Point<double> a,b,c;
    double p;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &p)!=EOF)
    {
        min_dis = 2*fabs(mul(a,b,c)) / (dis2(b, c) + dis2(c,a) + dis2(a,b));
        Point <double> q = SolvePoint(a, b, c);
        printf("%.2lf %.2lf\n", q.x, q.y);        
    }
    return 0;
}

