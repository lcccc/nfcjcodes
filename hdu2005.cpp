/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时33分07秒
 * File Name: hdu2005.cpp
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
int isrn(int x)
{
    return  x%400 == 0 || (x%100&&x%4==0);
} 
int days[13] = {31,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
    int y,m,d;
    while(scanf("%d/%d/%d",&y,&m,&d)!= EOF)
{
    isrn(y)?days[2] = 29:days[2] = 28;
    //cout<<days[2]<<endl;
    int ans = 0;
    for(int i = 1;i < m;i++) ans+=days[i];
    ans+=d;
    printf("%d\n",ans);
}
    return 0;
}

