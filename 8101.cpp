/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 10时14分48秒
 * File Name: 8101.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())
int pm[10000];
int tot=0;
bool ispm(int x)
{
    if(x < 2) return false;
    for(int i = 2;i<=(int)sqrt(x);i++)
        if( x % i == 0) return false;
    return true;
}
void init()
{
    for(int i = 2;i<=10000;i++)
        if(ispm(i)) pm[tot++] = i;
}
int main() {
    int m;
    init();
    //ofstream cout("t2.txt");
    freopen("t2.txt","w",stdout);
    cout<<tot<<endl;
    for(m = 6;m <= 10000; m+=2)
    {
    int i,b=0;
    for(int len = 0;len <=tot;len++){
        for(i = 0 ;i+len < tot;i++)
        {
         //   if( pm[i] + pm[i+len] > m) break;
            if( pm[i] + pm[i+len] == m){ 
                printf("%d %d\n",pm[i],pm[i+len]);
             //   printf("%d %d\n",i,i+len);
                b=1;
                break;
    }
        }
    if(b) break;
    }
    }    
    return 0;
}

