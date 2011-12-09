/*
ID:lc757692
TASK:pprime
LANG:C++
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
bool ispm(int x){
    if(x<2)return false;
    for(int i=2;i<=(int)sqrt(x);i++)
        if(x % i ==0)
            return false;
    return true;
}
int main() {
    int a,b;
    ifstream cin("pprime.in");
    ofstream cout("pprime.out");
    cin>>a>>b;
    for(int a1=0;a1<10;a1++)
            if(a1>=a&&a1<=b&&ispm(a1))cout<<a1<<endl;
    if(a<=11&&b>=11)
            cout<<11<<endl;
        for(int a1=1;a1<10;a1+=2)
            for(int a2=0;a2<10;a2++)
            {
                int tm=a1*100+a2*10+a1;
                if(tm>=a&&tm<=b&&ispm(tm))
                    cout<<tm<<endl;
            }
    
        for(int a1=1;a1<10;a1+=2)
            for(int a2=0;a2<10;a2++)
                for(int a3=0;a3<10;a3++)
                {
                    int tm=a1*10000+a2*1000+a3*100+a2*10+a1;
                    if(tm>=a&&tm<=b&&ispm(tm))
                        cout<<tm<<endl;
                }
         for(int a1=1;a1<10;a1+=2)
            for(int a2=0;a2<10;a2++)
                for(int a3=0;a3<10;a3++)
                    for(int a4=0;a4<10;a4++)
                {
                    int tm=a1*1000000+a2*100000+a3*10000+a4*1000+a3*100+a2*10+a1;
                    if(tm>=a&&tm<=b&&ispm(tm))
                        cout<<tm<<endl;
                }
    return 0;
}


