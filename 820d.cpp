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
#include "iomanip"
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

Gen Point <T> inter(Line<T> u, Line <T> v)
{
  //  printf("%lf %lf %lf %lf\n", u.a.x, u.a.y, u.b.x, u.b.y);
  //  printf("%lf %lf %lf %lf\n", v.a.x, v.a.y, v.b.x, v.b.y);
    Point <T> ret = u.a;
    double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
        /   ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x += (u.b.x-u.a.x)*t;
    ret.y += (u.b.y-u.a.y)*t;
    return ret;
}


Gen double disTo(Point <T>a, Point <T>b, Point <T>c)
{
    return fabs( mul(a,b,c) ) / dis(b, c);
}

Gen double disInter(Point <T>a, Point <T> b, Point <T>c)
{
    return fabs( mul(a,b,c) ) / (dis(a, b) + dis(b, c) + dis(c, a));
}

Gen int sgn(T x) { return (x>1e-9)-(x<-1e-9);}

double getTheta(double A, double B, double angle)
{
    double l = 0.0001, r = angle;
    double ratio = A/B;
    while (fabs(l-r) > 1e-9)
    {
        double mid = (l+r) / 2;
        int k = sgn(sin(mid) / sin(angle-mid) - ratio);
        if (k == 1) r = mid;
        else if (k==-1) l = mid;
        else {l=mid; break;}
    }
    //printf("%lf %lf %lf %lf\n", A/B, sin(l), sin(angle-l), sin(l) / sin(angle-l)); 
    return l;
}
const double pi = acos(-1.0);
Gen Line <T> PointAngle(Point <T> base, double angle)
{
    return (Line<T>){base, (Point <T>){base.x+cos(angle),  base.y+sin(angle)}};
}



Gen Point <T> SolvePoint(Point<T> a,Point<T> b,Point<T> c){
   // 
    //Point <T>center = Bary(a,b,c);
    //Point <T> centerref[] = {
           //get_refl(center, b, c),
           //get_refl(center, c, a),
           //get_refl(center, a, b),
    //};
    //return outer(centerref[0], centerref[1], centerref[2]);
   // 
    if ( sgn(mul (b, a, c)) > 0) swap(a, c);
    double area   = fabs(mul(a,b,c));
    double _a     = dis(b, c);
    double _b     = dis(c, a);
    double _c     = dis(a, b); 
    double B      = asin( area / (_a * _c));
    double theta1 = getTheta( _a, _c, B) + atan2(c.y-b.y, c.x-b.x);
    double C      = asin( area / (_a * _b)) ;
    double theta2 = -getTheta( _a, _b, C) + atan2(b.y-c.y, b.x-c.x);;
    return inter( PointAngle(b, theta1), PointAngle(c, theta2));
}


int main() {
    Point<double> a,b,c;
    double p;
    while (scanf("%f%f%f%f%f%f%f", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &p)!=EOF)
    {
        Point <double> q = SolvePoint(a, b, c);
        double x = q.x, y = q.y;
        printf("%.2f %.2f\n", x, y);
    }
    return 0;
}

/*

*/
