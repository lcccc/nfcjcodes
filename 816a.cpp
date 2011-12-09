/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 12时48分15秒
 * File Name: 816a.cpp
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
const double g = 9.8;
void red(double h,double vx,double vy)
{
    double t ;
    t = vy + sqrt( vy*vy + 2*g*h);
    t /= g;
    //cout<<t<<endl;
    //cout<<vx*t<<endl;
    printf("%.3lf\n",vx*t);
}
void yellow(double h,double vx,double vy,double t)
{
    double tg,x,len = 0;
    tg = vy + sqrt( vy*vy + 2*g*h);
    tg /= g;
    if(tg<=t)
        //cout<<vx*tg<<endl;
    printf("%.3lf\n",vx*tg);
    else {
        x = vy*t-g*t*t/2;
        len = vx*t;
        h += x;
        vy = vy-g*t;
        vy*=2;
        vx*=2;
        t = vy + sqrt( vy*vy + 2*g*h);
        t /= g;
        len += vx*t;
       //cout<<len<<endl;
       printf("%.3lf\n",len);
    }
}
void blue(double h,double vx,double vy,double t,double vx1,double vx2,double vx3)
{
    double tg,x,len = 0;
    tg = vy + sqrt( vy*vy + 2*g*h);
    tg /= g;
    if(tg<=t)
        //cout<<vx*tg<<endl;
    printf("%.3lf\n",vx*tg);
    else {
        x = vy*t-g*t*t/2;
        len = vx*t;
        h += x;
        vy = vy -g*t;
        t = vy + sqrt( vy*vy + 2*g*h);
        t /= g;
        //cout<<len+vx1*t<<' '<<len+vx2*t<<' '<<len+vx3*t<<endl;
        printf("%.3lf %.3lf %.3lf\n",len+vx1*t,len+vx2*t,len+vx3*t);
    }
}
int main() {
    double h,vx,vy,t,vx1,vx2,vx3;
    string cmd;
    while(cin>>h)
    {
        cin>>cmd;
        if(cmd == "Red"){
            cin>>vx>>vy;
            red(h,vx,vy);
        }
        if(cmd == "Yellow"){
            cin>>vx>>vy>>t;
            yellow(h,vx,vy,t);
        }
        if(cmd == "Blue"){
            cin>>vx>>vy>>t>>vx1>>vx2>>vx3;
            blue(h,vx,vy,t,vx1,vx2,vx3);
        }
    }
    return 0;
}

