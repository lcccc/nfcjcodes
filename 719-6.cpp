/*
 * Author: Nfcj
 * Created Time:  2011年07月19日 星期二 12时21分38秒
 * File Name: 719-6.cpp
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
/*
void _sf(){
    fill(ispm,ispm+iMax,1);
    for(i=2;i<=iMax-2;i++)
    {
        int tm=i;
        tm+=i;
        while(tm<iMax){
            ispm[tm]=0;
            tm+=i;
        }
    }
}
*/
inline bool Ispm(long long  x){
    for(long long  i=2;i<=(long long)sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}
int main() {
    //for(long long i=2;i<=1000000000;i++)
    //    if(Ispm(i))cout<<i<<endl;
    int b;
    long long n;
    while(cin>>n){
        b=0;
    for(long long i=2;i<=(long long)sqrt(n);i++)
    {
        
        if(Ispm(i)&& i*(n/i)==n&&i!=(n/i)&&Ispm(n/i))
        {
                cout<<i<<' '<<n/i<<' '<<n<<endl;
                b=1;
                break;     
        }
    }
    if(b==0)cout<<"is not a D_num"<<endl;
    }
    return 0;
}

