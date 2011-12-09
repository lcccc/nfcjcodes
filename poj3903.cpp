/*
 * Team : FreePascal
 * Created Time:  2011年10月28日 星期五 23时41分52秒
 * File Name: poj3903.cpp
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

unsigned int j,n,p,i,k1,k2,k3,len,a,D[100002];

int main(void)
{
     while(scanf("%u",&p) == 1)
     {
          len=0;         

          for(i=1;i<=p;i++)
          {
               scanf("%u",&a);
 
               if(a>D[len]){
                  len++;
                  D[len]=a;
               }
               else{
                  k1=0; k2=len;

                  while(k2-k1>1){
                     k3=(k2+k1)/2;
                     if(D[k3]>=a) k2=k3;
                     else         k1=k3;
                  }

                  D[k2]=a;
               }
          }
          printf("%u\n",len);
     }
 
     return 0;
}
