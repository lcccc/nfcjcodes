/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 18时54分56秒
 * File Name: 8104.cpp
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
bool ispm(int x )
{
    if(x < 2) return false;
    for(int i = 2;i <= (int)sqrt(x);i++)
        if( x % i == 0) return false;
    return true;
}
int pm[10000],tot = 0;
int main() {
    for(int i = 2;i <= 10000;i++)
        if(ispm(i)) pm[tot++] = i;
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if( n == 0 ) break;
        int ans = 0;
        for(int i = 0 ; i < tot ;i++)
            for(int j = i+1;j< tot;j++)
                if( pm[i] + pm[j] == n)
                    ans++;
        printf("%d\n",ans);
    }
    return 0;
}

