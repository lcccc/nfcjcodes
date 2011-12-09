/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 22时15分27秒
 * File Name: 85-9.cpp
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
bool cmp(int a,int b)
{
    return fabs(a) > fabs(b);
}
int main() {
    vector<int> f;
    int n,k;
    while(cin>>n)
    {
        if(n == 0) break;
        f.clear();
        for(int i = 0;i < n;i++)
            cin>>k,f.push_back(k);
        sort(f.begin(),f.end(),cmp);
        for(int i = 0;i < n;i++)
            cout<<f[i]<<' ';
        cout<<endl;
    }
    return 0;
}

