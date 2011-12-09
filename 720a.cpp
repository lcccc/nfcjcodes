/*
 * Author: Nfcj
 * Created Time:  2011年07月20日 星期三 13时29分08秒
 * File Name: 720a.cpp
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
int  sdk[145][145];
int cs;

bool do_squ(int x,int n)
{
    int bretu=1;
    int bkt=0;
    int nm[13];
    int tmj=x%n;
    if(tmj==0)tmj=n;
    tmj= (tmj-1) * n;
    memset(nm,0,sizeof nm);
    for(int i= (ceil(x/(n+0.0))-1)*n+1;i <= (ceil(x/(n+0.0))-1)*n+n;i++)
   //     for(int j =(ceil(x/(n+0.0))-1)*n+1;j <=(ceil(x/(n+0.0))-1)*n+n;j++)
        for(int j = tmj+1;j<=tmj+n;j++) 
            nm[sdk[i][j]]++;
    bool bone=0;
    for(int i=1;i<=n*n;i++)
        if(nm[i]==0){
            if(bone==0){
                bone=1;
                printf("Square %d has no %ds",x,i);
                bkt=1;
            }
            else printf(" and no %ds",i);
           bretu=0;
        } 
    for(int i=1;i <= n*n;i++)
        if(nm[i]>1){
            if(bone == 0){
                bone = 1;
                if(bkt==0){
                    printf("Square %d has",x);
                    bkt=1;}
                printf(" %d %ds",nm[i],i);
            }
            else printf(" and %d %ds",nm[i],i);
            bretu=0;
        } 
    if(bkt)printf("\n");

    return bretu;
       
}
bool do_row(int x,int n)
{
    int bretu=1;
    int bkt=0;
    int nm[13];
    memset(nm,0,sizeof nm);
    for(int j =1;j <=n*n;j++)
            nm[sdk[x][j]]++;
    bool bone=0;
    for(int i=1;i<=n*n;i++)
        if(nm[i]==0){
            if(bone==0){
                bone=1;
                printf("Row %d has no %ds",x,i);
                bkt=1;
            }
            else printf(" and no %ds",i);
           bretu=0;
        } 
    for(int i=1;i <= n*n;i++)
        if(nm[i]>1){
            if(bone == 0){
                bone = 1;
                if(bkt==0){
                    printf("Row %d has",x);
                    bkt=1;}
                printf(" %d %ds",nm[i],i);
            }
            else printf(" and %d %ds",nm[i],i);
            bretu=0;
        }
    
    if(bkt)printf("\n");
    return bretu;
   
    
}
bool do_col(int x,int n)
{
    int bretu=1;
    int bkt=0;
    int nm[13];
    memset(nm,0,sizeof nm);
        for(int j =1;j <=n*n;j++)
            nm[sdk[j][x]]++;
    bool bone=0;
    for(int i=1;i<=n*n;i++)
        if(nm[i]==0){
            if(bone==0){
                bone=1;
                printf("Column %d has no %ds",x,i);
                bkt=1;
            }
            else printf(" and no %ds",i);
           bretu=0;
        } 
    for(int i=1;i <=n*n;i++)
        if(nm[i]>1){
            if(bone == 0){
                bone = 1;
                if(bkt==0){
                    printf("Column %d has",x);
                    bkt=1;}
                printf(" %d %ds",nm[i],i);
            }
            else printf(" and %d %ds",nm[i],i);
            bretu=0;
        }
    if(bkt)printf("\n");
    return bretu;
    
}
int main() {
    scanf("%d",&cs);
    int Cs=1;
    for(;Cs <= cs;Cs++)
    {
        printf("Puzzle  %d\n",Cs);
       int n;
        scanf("%d",&n);
        memset(sdk,0,sizeof sdk);
       for(int i=1;i <= n*n;i++)
          for(int j=1;j <= n*n;j++)
             scanf("%d",&sdk[i][j]);
            int bval=1;
            for(int k=1;k<=n*n;k++)
                if(!do_squ(k,n))bval=0;
            for(int k=1;k<=n*n;k++)
                if(!do_row(k,n))bval=0;
            for(int k=1;k<=n*n;k++)
                if(!do_col(k,n))bval=0;
           if(bval)printf("The solution is valid.\n");
           else printf("The solution is invalid.\n");
           }
    
    return 0;
}

