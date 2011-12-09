/*
 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 14时39分30秒
 * File Name: d.cpp
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
int s,m,p;
double x;
double tbs(double pp,int m){
    double ans=0;
    double tpp=pp;
    for(int i=1;i<=m;i++){
        ans+=pp;
        pp*=tpp;
    }
   return ans+1;
} 
int main() {
    scanf("%d%d%d",&s,&m,&p);
    double pp;
    pp=  (100+p)/100.0;
    x= s*pow(pp,m)/tbs(pp,m-1);
    printf("%.6f\n",x);
    return 0;
}

