/*
 * Author: Nfcj
 * Created Time:  2011年07月26日 星期二 12时34分18秒
 * File Name: 7262.cpp
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
//bool tag[4300000000];
inline int f(int a,int b,int  M)
{
    if(a<b) swap(a,b);
    int ans = M/a;
    ans -= (M/a/b)/2;
    return ans;
}
int main() {
    int a,b,M;
    while(scanf("%d%d%d",&a,&b,&M) == 3)
    {
       // cout<< f(a,b,M)<<endl;
    printf("%d\n",f(a,b,M));
    }
    return 0;
}

