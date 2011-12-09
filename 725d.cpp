/*
 * Author: Nfcj
 * Created Time:  2011年07月25日 星期一 13时46分20秒
 * File Name: 725d.cpp
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
int MAXLEN = 1000000+5;
int inc1[1000005],inc2[1000005],dec1[1000005],dec2[1000005];
int cs,n,nd[1000005];
int dp(){
    inc1[0]=1;
    for(int i=1;i<n;i++)
        if( nd[i]> nd[i-1]) inc1[i]=inc1[i-1]+1;
        else inc1[i]=1;
    inc2[n-1]=1;
    for(int i=n-2;i>=0;i--)
        if( nd[i]> nd[i+1]) inc2[i]=inc2[i+1]+1;
        else inc2[i]=1;
    dec1[0]=1;
    for(int i=1;i<n;i++)
        if(nd[i]<nd[i-1]) dec1[i]=dec1[i-1]+1;
        else dec1[i]=1;
    dec2[n-1]=1;
    for(int i=n-2;i>=0;i--)
        if( nd[i]< nd[i+1]) dec2[i]=dec2[i+1]+1;
        else dec2[i]=1;
}
int main() {
    scanf("%d",&cs);
   for(int CS = 0;CS < cs;CS++)
   {
      scanf("%d",&n); 
      for(int i=0;i < n;i++)
      scanf("%d",&nd[i]);
      //memset(inc1,0,sizeof inc1);
      //memset(inc2,0,sizeof inc2);
      //memset(dec1,0,sizeof dec1);
      //memset(dec2,0,sizeof dec2);
    dp(); 
    int k,maxlen=0;
    for(int i=0;i<n;i++){
        k = inc1[i]>inc2[i]?inc2[i]:inc1[i];
        if( k-1 > maxlen) maxlen = k-1;
    }
    printf("%d ",maxlen);
    maxlen=0;
    for(int i=0;i<n;i++)
    {
        k = dec1[i]>dec2[i]?dec2[i]:dec1[i]; 
        if( k-1 > maxlen) maxlen = k-1;
    }
    printf("%d\n",maxlen);
   }
    return 0;
}

