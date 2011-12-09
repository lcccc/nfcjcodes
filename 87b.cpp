/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 14时40分51秒
 * File Name: 87b.cpp
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
int t,len,len8;
int main() {
    scanf("%d",&t);
    while(t--)
    {
        int bans = 0;
        int x,md;
        scanf("%d",&x);
        for(len = 1; len <= 200;len++)
        {
            for( len8 = 0;len8 <= len;len8++)
            {
                md = 0;
                for(int i=1;i<=len8;i++)
                {
                    md = md*10 + 8;
                    md %= x;
                }
                for(int i=len8+1;i<=len;i++)
                {
                    md = md*10 + 6;
                    md %= x;
                }
            if( md == 0)
            {
                bans = 1;
                for(int i=1;i<=len8;i++)printf("8");
                for(int i=len8+1;i<=len;i++)printf("6");
                printf("\n");
                break;
            }
            }
        if(bans) break;
        }
        if(!bans) printf("-1\n");
    }
    return 0;
}

