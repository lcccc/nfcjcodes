/*
ID:lc757692
TASK:money
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月19日 星期二 10时33分02秒
 * File Name: money.cpp
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
int v,n;
long long ans=0;
vector<int> mz;
int bfs(int i,int sum)
{
    if(i==v){
        if(sum==0)ans++;
        return 0;
    }
    for(int k=0;k<=sum/mz[i];k++)
        bfs(i+1,sum-k*mz[i]);
}

int main() {
    ifstream cin("money.in");
    ofstream cout("money.out");
    cin>>v>>n;
    int tm;
    for(int i=0;i<v;i++){
        cin>>tm;
        mz.push_back(tm);
    }
    sort(mz.begin(),mz.end());
    reverse(mz.begin(),mz.end());
    bfs(0,n);
    cout<<ans<<endl;
    return 0;
}
//  DFS   TLE
