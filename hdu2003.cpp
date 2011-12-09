/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时10分10秒
 * File Name: hdu2003.cpp
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
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        printf("%.2lf\n",fabs(n));
    }
    return 0;
}

