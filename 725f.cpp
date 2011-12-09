/*
 * Author: Nfcj
 * Created Time:  2011年07月25日 星期一 16时19分53秒
 * File Name: 725f.cpp
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
    int cs;
    scanf("%d",&cs);
    while(cs--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if( ceil( n/2.0 )*ceil( m/2.0) < k) printf("Impossible");
        else {
            int ct=0;
            for(int i = 1;i <= n;i++)
            {
                for(int j=1;j <= m;j++)
                    if(ct < k && i % 2==1 && j%2==1)
                    {
                        printf("#");
                        ct++;
                    }
                    else printf(".");
               printf("\n");
            }
        } 
        if( cs !=0) printf("\n");
    }
    return 0;
}

