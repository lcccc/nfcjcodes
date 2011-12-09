/*
 * Author: Nfcj
 * Created Time:  2011年07月25日 星期一 16时59分57秒
 * File Name: 725g.cpp
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
int gcd(int m,int n)
{
    int rem;
    while(n > 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
int main() {
   int n;
   long long ans=0;
   cin>>n;
    for(int i=1;i<n;i++)
       for(int j=i+1;j<n;j++)
          //if( n % gcd(i,j) == 0){
          //    ans++;
          //    cout<<i<<' '<<j<<endl;
         // }
       {
           if( i == 1) { ans++;continue;
           }
           else {
               if( n > i*j - i - j){ ans++;cout<<i<<' '<<j<<endl;}
           }
       }
    
   cout<<ans<<endl; 
    return 0;
}

