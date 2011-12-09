/*
 * Team : FreePascal
 * Created Time:  2011年08月08日 星期一 12时38分32秒
 * File Name: c.cpp
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

const double a[7] = {9.23076,1.84523,56.0211,4.99087,0.188807,15.9803,0.11193};
const double b[7] = {26.7,75,1.5,42.5,210,3.8,254};
const double c[7] = {1.835,1.348,1.05,1.81,1.41,1.04,1.88};
int CS,p[10];
long long ans;
int main() {
    freopen("c.in","r",stdin);
    scanf("%d",&CS);
    while (CS--){
        ans = 0;
        for (int i = 0; i < 7; i++) scanf("%d",&p[i]);
        for (int i = 0; i < 7; i++){
            double tmp;
            if (i == 0 || i == 3 || i == 6){
                tmp = a[i] * pow(b[i] - p[i],c[i]);
            }
            else tmp = a[i] * pow(p[i] - b[i],c[i]);
            ans = ans + (long long) tmp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

