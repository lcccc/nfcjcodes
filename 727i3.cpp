/*
 * Author: Nfcj
 * Created Time:  2011年07月27日 星期三 14时35分14秒
 * File Name: 727i3.cpp
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
int tag[1000005],F[1000005],pm[1000005],ct[1000005];
int main() {
    memset(pm,0,sizeof tag);
    for(int i=1;i<=1000000;i++)
        {
            for(int j=1;i*j <=1000000;j++)
                pm[i*j]++;
        }
    memset(ct,0,sizeof ct);
    for(int i=2;i<=1000000;i++)
    {
        F[i] = ct[pm[i]];
        ct[pm[i]]++;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",F[n]);
    return 0;
}

