/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 23时17分56秒
 * File Name: hdu2569.cpp
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
int main() {
    double f[45];
    int c;
    f[0] = 0;
    f[1] = 3;
    f[2] = 9;
    f[3] = 21;
    for(int i=4;i<=40;i++)
        f[i] = 2 * f[i-2] + f[i-1];
    cin>>c;
    while(c--)
    {
        int k;
        cin>>k;
        if( k < 1) printf("0\n");
        else 
        printf("%.0lf\n",f[k]);
    }
    return 0;
}

