/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 19时14分59秒
 * File Name: 872.cpp
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
    int n,k;
    long long ans = 0;
    cin>> n;
    for(int i=0;i<n;i++)
        {
            cin>>k;
            ans+= (long long)(k-1)*(long long)(i+1)+1;
        }
    cout<<ans<<endl;
    return 0;
}

