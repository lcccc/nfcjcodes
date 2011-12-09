/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 21时07分43秒
 * File Name: 85-4.cpp
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
int t,n,m;
int main() {
    cin>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>m;
        int n5,n2,n1;
        for(n5 = 0;n5 <= m/5; n5++)
            for(n2 = 0; n2 <= (m-n5*5)/2;n2++)
            {
                n1 = n-n5-n2;
                if( n5*5 + n2*2 + n1 == m)
            ans++;
            }
        cout<<ans<<endl;
    }
                
    return 0;
}

