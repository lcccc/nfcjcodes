/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 18时46分57秒
 * File Name: 8103.cpp
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
bool ispm(int x)
{
    if( x < 2) return false;
    for(int i = 2;i <= (int) sqrt( x);i++)
        if( x % i == 0) return false;
    return true;
}
bool f(int x)
{
    return ispm(x*x+x+41);
}
int main() {
    int x,y;
    while(cin>>x>>y)
    {
        if(x == 0 && y == 0) break;
        int b = 1;
        for(int i = x+1;i<y;i++)
            if(f(i) == false ) 
            {
                b = 0;
                break;
            }
        if(b) printf("OK\n");
        else printf("Sorry\n");
    }
    return 0;
}

