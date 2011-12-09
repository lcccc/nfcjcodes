/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时51分11秒
 * File Name: hdu2008.cpp
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
    double k;
    int n;
    int nf,nl,nz;
    while(scanf("%d",&n)!=EOF)
    {
        if( n == 0) break;
        nf = nl = nz = 0;
        for(int i = 0;i < n;i++)
        {
           scanf("%lf",&k);
          k>0?nz++:(k==0?nl++:nf++);
        }
        printf("%d %d %d\n",nf,nl,nz);
    }
    return 0;
}

