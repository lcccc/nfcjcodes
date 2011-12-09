/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 21时25分33秒
 * File Name: 85-8.cpp
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
int tot,n,pm[50000];
bool ispm(int x)
{
    for(int i = 2;i <= (int)sqrt(x);i++)
        if( x % i ==0) return false;
    return true;
}
void init(){
tot = 0;
  for(int i=2;i<=30000;i++) 
      if(ispm(i)) pm[tot++] = i;
}  
int maxfac(int x)
{
    if( x == 1) return 1;
    int maxf = 0;
    for(int i = 0 ;i < tot;i++)
    {
        if( pm[i] > x) break;
        if(x % pm[i] == 0) maxf = pm[i];
    }
    return maxf;
}
int main() {
    init();
    cin>>n;
    int fac=0,k,a;
    for(int i = 0; i < n;i++)
    {
        cin>>a;
        if( maxfac(a) > fac ){ fac = maxfac(a);k = a;}
    }
    cout<<k<<endl;
        
    return 0;
}

