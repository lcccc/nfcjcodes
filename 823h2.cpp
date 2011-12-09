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
    double x1,x2,y1,y2,t;
    cin>>ct;
    while(ct--)
    {
        cin>>x1>>y1>>x2>>y2>>t;
        double ans = 0;
        double vx,vy;
        double px1,px2,py1,py2;
        vx = ( x2 - x1) / t;
        vy = ( y2 - y1 + 0.5*g*t*t) / t;
        px1 = x1;
        py1 = y1;
        ans = vy/(2*vx)*x2*x2-x2*x2*x2/(6*g*vx*vx)+y1*x2;
        ans -= vy/(2*vx)*x1*x1-x1*x1*x1/(6*g*vx*vx)+y1*x1;
        cout<<ans<<endl; 
        //printf("%.3lf\n",ans);
    }
    return 0;
}


