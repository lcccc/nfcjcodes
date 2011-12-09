/*
 * Author: Nfcj
 * Created Time:  2011年07月20日 星期三 13时05分10秒
 * File Name: 720b.cpp
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
    int a,b;
    while(cin>>a>>b){
        if(a==0&&b==0)break;
        int ans=0;
        while(b>a){   
        if( (b/2)*2==b && b/2 >= a)
               b-= b/2;
           else b--;
        ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

