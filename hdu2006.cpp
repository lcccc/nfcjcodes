/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时41分57秒
 * File Name: hdu2006.cpp
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
    int ans,n,k;
    while(cin>>n)
    {
        ans = 1;
        for(int i = 0;i < n;i++)
            {
                cin>>k;
                if(k%2)ans*=k;
            }
        cout<<ans<<endl;
    }
    return 0;
}

