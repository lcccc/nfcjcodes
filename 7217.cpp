/*
 * Author: Nfcj
 * Created Time:  2011年07月21日 星期四 12时33分55秒
 * File Name: 7217.cpp
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
    int a,b,c;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
       double d;
        d= (double)b*b-(double)4*a*c;
        
        if(d<0){
            printf("NO\n");
            continue;
        }
        if(d==0){
            printf("%.2lf\n",-(b+0.0)/(double)2*a);
            continue;
        }
        if(d>0){
            double ans1=(double)(-b-sqrt(d))/(double)2*a;
            double ans2=(double)(-b+sqrt(d))/(double)2*a;
            printf("%.2f %.2f\n",min(ans1,ans2),max(ans1,ans2));
        }
    }
    return 0;
}

