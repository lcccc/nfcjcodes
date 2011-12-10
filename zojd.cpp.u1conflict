/*
 * Author: Nfcj
 * Created Time:  2011年07月24日 星期日 16时40分03秒
 * File Name: zojd.cpp
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
int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    else return gcd(b,a-b);
}
int main() {
    int cs=1, x,y;
    while(cin>>x>>y)
    {
       cout<<"Case #"<<cs++<<":"<<endl;
      for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(i==1&&j==1){cout<<"P";continue;}
                if(i==1||j==1)cout<<"H";
                else cout<<"P";
            }
            cout<<endl;
        }
    }
    return 0;
}

