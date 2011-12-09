/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 20时42分39秒
 * File Name: 85-2.cpp
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
    int t,n,m,ans,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans = 0;
        for(int i=0;i<n*m;i++)
            cin>>k,ans+=k;
        cout<<ans<<endl;
    }
    return 0;
}

