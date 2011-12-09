/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 20时07分06秒
 * File Name: 85-1.cpp
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
    int n,a,b,c;
    cin>>n;
    for(int cs = 1; cs <= n;cs++)
    {
        cin>>a>>b>>c;
        printf("Scenario #%d:\n",cs);
        if( a > b) swap(a,b);
        if( b > c) swap(b,c);
        if(a*a + b*b == c*c)
            printf("yes\n");
        else printf("no\n");
        printf("\n");
    }
    return 0;
}

