/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时08分11秒
 * File Name: hdu2002.cpp
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
double mj(double r)
{
    return 4/3.0*3.1415927*r*r*r;
}
int main() {
    double r;
    while(cin>>r)
        //cout<<mj(r)<<endl;
        printf("%.3lf\n",mj(r));
    return 0;
}

