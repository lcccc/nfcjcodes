/*
 * Team : FreePascal
 * Created Time:  2011年08月23日 星期二 13时02分03秒
 * File Name: 823h.cpp
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
const double g = 9.80;
const double dt = 0.0001;
int main() {
    int ct;
    //freopen("823h.out","w",stdout);
    double x1,x2,y1,y2,t;
    cin>>ct;
    while(ct--)
    {
        cin>>x1>>y1>>x2>>y2>>t;
        if (t == 0){
            printf("Impossible.\n");
            continue;
        }
        double ans = 0;
        double vx,vy;
        double px1,px2,py1,py2;
        vx = ( x2 - x1) / t;
        vy = ( y2 - y1 + 0.5*g*t*t) / t;
        //ans = -1 / 3 * pow((sqr(vy - g * t) - vx * vx),1.5) / (vy - g * t) / g;
        //ans += 1 / 3 * ((vy * vy - vx * vx),1.5) / vy / g;

        px1 = x1;
        py1 = y1;
        int k = t / dt;
        //cout<<k<<endl;
        for(int i = 0;i <= k; i ++)
        {
            px2 = px1 + vx*dt;
            py2 = py1 + vy*dt - 0.5*g*dt*dt;
            vy -= g*dt;
            //cout<<"px2 py2"<<px2<<' '<<py2<<endl;
            ans+= sqrt( (px2-px1)*(px2-px1) + (py2-py1)*(py2-py1));
            px1 = px2;
            py1 = py2;
        }
//*/
        printf("%.3lf\n",ans);
    }
    return 0;
}


