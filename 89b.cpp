/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 14时32分05秒
 * File Name: 89b.cpp
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
int f[1000000+5],t,n,l,d;
int main() {
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&l,&d);
        f[0] = 1;
        f[1] = 2;
        for(int i = 2;i <= n;i++)
        {
            f[i] = (( f[i-1]*f[i-1] + f[i-1])/2+1) % d;
            cout<<f[i]<<endl;
        }
        string s;
        cin>>s;
        long long ans = 1;
        for(int i = l-1;i>=0;i--)
            if( s[i] == '1' )ans = ans*f[i] % d;
        cout<<ans<<endl;
    }
    return 0;
}

