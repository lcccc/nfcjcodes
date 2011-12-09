/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 12时51分00秒
 * File Name: 89a.cpp
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

int main() {
    vector<int> f;
    int n,k;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0) break;
        f.clear();
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&k);
            f.push_back(k);
        }
        int bans = 0;
        for(int i = 1;i < 1000000;i++)
        {
           int k;
          for(k = 0;k < n;k++)
             if( i % f[k]) break;
         if( k == n) {
            bans = 1;
           printf("The CEO must bring %d pounds.\n",i);
            break;
         }
        if( bans ) break;
        }
       if(!bans) printf("Too much money to pay!\n");
    } 
    return 0;
}

