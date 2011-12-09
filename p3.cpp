/*
 * Author: Nfcj
 * Created Time:  2011年07月15日 星期五 16时37分41秒
 * File Name: p3.cpp
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
int R(int n)
{
    int ans=0,i,j;
    if(n==0)return 1;
    for(int i=0;i<=(int)sqrt(n);i++)
       // for(int j=0;j<=(int)sqrt(n);j++)
        {   
            j=sqrt( n - i*i);
            
            if(i*i+j*j==n)
            {
          //      cout<<i<<' '<<j<<endl;
                ans+=4;
                if(i==0||j==0)ans-=2;
            }
            //if(i*i+j*j>n)break;
        }
    return ans;
}
int main() {
    int n;
    while(cin>>n){
        cout<<R(n)<<endl;
    }
    return 0;
}

