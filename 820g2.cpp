/*
 * Team : FreePascal
 * Created Time:  2011年08月20日 星期六 15时35分01秒
 * File Name: 820g2.cpp
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
const double eps  = 1e-6;
int sgn(double i)
{
    return i>eps?1:(i<-eps?-1:0);
    }
struct point{ double x,y;};
double mult(point sp,point ep,point op){
    return (sp.x - op.x) * (ep.y - op.y) + (ep.x - op.x) * (sp.y-op.y);
}
bool operator <(const point &l,const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[],int n,point res[]){
    int i,len,k = 0,top = 1;
    sort(pnt,pnt + n);
    if(n == 0 ) return 0; res[0] = pnt[0];
    if(n == 1 ) return 1; res[1] = pnt[1];
    if(n == 2 ) return 2; res[2] = pnt[2];
    for(i = 2; i < n; i++){
        while(top && sgn(mult(pnt[i],res[top],res[top-1])>=0))
            top--;
        res[++top] = pnt[i];
    }
    len = top;res[++top] = pnt[n-2];
    for( i  = n-3; i >= 0;i --){
        while(top!=len && sgn(mult(pnt[i],res[top],res[top-1]))>=0) top--;
        res[++top] = pnt[i];
    }
    return top;
}
double len(point p1,point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y - p2.y)*(p1.y-p2.y);
}
int main() {
    int n,t;
    point pn1[100000+5],pn2[100000+5],res1[100000+5],res2[100000+5];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%lf%lf",&(pn1[i].x),&(pn1[i].y));
    for(int i = 0;i < n;i++)
        scanf("%lf%lf",&(pn2[i].x),&(pn2[i].y));
 
    int r1,r2;
    r1 = graham(pn1,n+1,res1);
    r2 = graham(pn2,n+1,res2);
    cout<<r1<<' '<<r2<<endl;
    double ans = 10e30;
    for(int i = 0;i < r1;i++)
        for(int j = 0;j < r2;j++)
            if( len(res1[i],res2[j]) < ans) ans = len(res1[i],res2[j]);
    printf("%.3lf\n",sqrt(ans));
    }
    return 0;
}

