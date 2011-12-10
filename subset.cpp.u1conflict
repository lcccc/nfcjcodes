/*
ID:lc757692
TASK:subset
LANG:C++

 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 10时35分57秒
 * File Name: subset.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
int  n,sum,f[40][850];
int init(){
  //  ifstream cin("subset.in");
    cin>>n;
    sum= n*(n+1)/2;
    memset(f,0,sizeof f);
    f[0][0]=1;
    return 0;
}
int dp(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
        {
            if(i==j){
                f[i][j]=f[i-1][j]+1;
                continue;
            }
            if(j<i)
            {
                f[i][j]=f[i-1][j];
                continue;
            }
            f[i][j]=f[i-1][j]+f[i-1][j-i];
        }
    return 0;
}
int ouit(){
   // ofstream cout("subset.out");
    if(sum %2 )
        cout<< 0 <<endl;
    else
    {
        dp();
    cout<< f[n][sum/2]/2 <<endl;
    }
    return 0;
}
int main() {
    init();
    ouit();
    return 0;
}

