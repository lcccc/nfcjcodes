/*
 * Author: Nfcj
 * Created Time:  2011年07月27日 星期三 12时43分00秒
 * File Name: 727i.cpp
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
int nm[1000001];
inline int f( int x ){
    int ans = 0;
   // for(int i = 1;i < (int)sqrt(x);i++)
    for(int i=1;i<= (int)sqrt(x);i++)
        if( x % i ==0 ) ans+=2;
    if( (int)sqrt(x) * (int)sqrt(x) ==  x )  ans--;
    return ans;
}
            
int main() {
    for(int i = 2;i <= 100; i++)
        printf("%d %d\n",i,f(i));
    return 0;
}

