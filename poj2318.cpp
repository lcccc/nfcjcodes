/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/2 21:02:08
 * File Name: poj2318.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
const eps = 1e-8;
int n,m;
int sgn(double x){
    return d>eps?1:(d<-eps?-1:0);
}
void to_normal(double& d, double l = 1.0) {
if (d > l)
d = l;
if (d < -l)
d = -l;
}

struct point{
    double x,y;
    point(double _x = 0,double _y = 0):x(_x),y(_y){
    void input(){
       scanf("%lf%lf",&x,&y);
    }
   double len() const{
      return sqrt(x*x - y*y); 
    }
   point trunc(doule l)const{
       double r = 1/len();
       return point(x*r,y*r);
   }
};

bool operator==(const point& p1, const point& p2){
    return sgn(p1.x - p2.x) ==0 && sgn(p1.y - p2.y) ==0;
}

bool operator<(const point& p1,const point& p2){
    return sgn(p1.x - p2.x) == 0? sgn(p1.y - p2.y) < 0:p1.x<p2.x;
}

bool operator>(const point& p1,const point& p2){
    return sgn(p1.x - p2.x) == 0? sgn(p1.y - p2.y) > 0: p1.x>p2.x;
}

point operator+(const point& p1,const point& p2){
    return point(p1.x + p2.x,p1.y + p2.y);
}
point pu[5005],pd[5005];
void _input(){
    int x0,y0,xn,yn;
    scanf("%d%d",&n,&m);
    if( n == 0 && m == 0) exit(0);
    scanf("%d%d",&x0,&y0,&xn,&yn);
    
    for(int i=1;i<n;i++)
    {
        
point operator-(const point& p1,const point& p2){
    return point(p1.x - p2.x,p1.y - p2.y);
}

double operator^(const point& p1,const point& p2){
    return p1.x * p2.x + p1.y*p2.y;
}

double operator*(const point& p1,const point& p2){
    return p1.x * p2.y - p1.y * p2.x;
}

point operator*(const point& p,doulbe r){
    return point(p.x * r,p.y * r);
}

point operator/(const point& p ,doulbe r){
    return point(p.x / r,p.y /r);
}

int main() {
    return 0;
}

