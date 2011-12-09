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
    freopen("823h.out","w",stdout);
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
        int k = t / dt;
        printf("%.3lf\n",ans);
    }
    return 0;
}

