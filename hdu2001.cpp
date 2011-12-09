/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时03分52秒
 * File Name: hdu2001.cpp
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
double len(double x1,double y1,double x2,double y2)
{
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
int main() {
    double x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2)
       // cout<<len(x1,y1,x2,y2)<<endl;
        printf("%.2lf\n",len(x1,y1,x2,y2));
    
    return 0;
}

