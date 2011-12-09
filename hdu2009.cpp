/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时56分55秒
 * File Name: hdu2009.cpp
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
    double n,ans;
    int m;
    while(scanf("%lf%d",&n,&m)!=EOF){
        ans = 0;
            while(m--)ans+=n,n=sqrt(n);
        printf("%.2lf\n",ans);
        }
    return 0;
}

