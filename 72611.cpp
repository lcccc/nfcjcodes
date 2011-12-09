/*
 * Author: Nfcj
 * Created Time:  2011年07月26日 星期二 14时36分19秒
 * File Name: 72611.cpp
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
void zscore(int n)
    {
        double nm[10001];
        double mx,sum=0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lf",&nm[i]);
            sum+=nm[i];
        }
        mx = sum / n;
        double sdx=0;
        for(int i = 0;i < n;i++)
            sdx+= (( nm[i] - mx)*(nm[i]-mx));
        sdx /=n;
        sdx = sqrt(sdx);
        for(int i = 0;i < n;i++)
        {
           printf("%.2lf",(nm[i]-mx)/sdx);
           if( i != n-1)printf(" ");
           else printf("\n");
        }
    } 
void ttest(int n)
{
    double nm[10001];
    double mpop,sum=0,sdx=0,mx;
    scanf("%lf",&mpop);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&nm[i]);
        sum+=nm[i];
    }
    mx = sum / n; 
    for(int  i=0;i<n;i++)
        sdx+= (nm[i]-mx)*(nm[i]-mx);
    sdx/=(n-1);
    sdx = sqrt(sdx);
    double sex = sdx/sqrt(n);
    printf("%.2lf\n",(mx-mpop)/sex);
}
void pr(int n){
    double X[10001],Y[10001],sdx=0,sdy=0,mx,my,sumx=0,sumy=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&X[i]);
        sumx+=X[i];
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&Y[i]);
        sumy+=Y[i];
    }
    mx = sumx / n;
    my = sumy / n;
    for( int i = 0 ;i < n; i ++){
        sdy+=((Y[i]-my)*(Y[i]-my));
        sdx+=((X[i]-mx)*(X[i]-mx));    
    }
    sdx/=n;sdy/=n;
    sdx = sqrt(sdx);sdy = sqrt(sdy);
    double rxy = 0;
    for(int i = 0;i< n; i++)
       rxy+= ((X[i]-mx)*(Y[i]-my));
    rxy/= n*sdx*sdy;
   printf("%.2lf\n",rxy); 
} 

void ab(int n){
    double X[10001],Y[10001],sdx=0,sdy=0,mx,my,sumx=0,sumy=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&X[i]);
        sumx+=X[i];
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&Y[i]);
        sumy+=Y[i];
    }
    mx = sumx / n;
    my = sumy / n;
    for( int i = 0 ;i < n; i ++){
        sdy+=((Y[i]-my)*(Y[i]-my));
        sdx+=((X[i]-mx)*(X[i]-mx));    
    }
    sdx/=n;sdy/=n;
    sdx = sqrt(sdx);sdy = sqrt(sdy);
    double rxy = 0;
    for(int i = 0;i< n; i++)
       rxy+= ((X[i]-mx)*(Y[i]-my));
    rxy/= n*sdx*sdy;
   //printf("%.2lf\n",rxy); 
    double a,b;
    b = rxy*(sdy/sdx);
    a = my - b*mx;
    printf("%.2lf %.2lf\n",a,b);
} 

int main() {
    int p,n;
    while(scanf("%d%d",&p,&n)!=EOF)
    {
        if( p == 1) zscore(n);
        if( p == 2) ttest(n);
        if( p == 3) pr(n);
        if( p == 4) ab(n);
    }
    return 0;
}

