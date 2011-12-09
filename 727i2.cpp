/*
 * Author: Nfcj
 * Created Time:  2011年07月27日 星期三 14时25分13秒
 * File Name: 727i2.cpp
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
int a[1000005],pm[1000005],ct[100000];
int main() {
    memset(pm,0,sizeof pm);
    for(int i=1; i<=1000000;i++)
        for(int j=1;j*i<=1000000;j++)
            pm[i*j]++;
    for(int i=1;i<=1000000;i++)
    {
        a[i] = ct[pm[i]];
        ct[pm[i]]++;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",a[n]);

    return 0;
}

