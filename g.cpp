/*
 * Author: Nfcj
 * Created Time:  2011年07月24日 星期日 12时04分56秒
 * File Name: g.cpp
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
    int n,ncc,ans;
    vector<int> f;
   while(cin>>n>>ncc){
    ans=ncc;
    f.clear();
    for(int i=0;i<n;i++)
    {
        int tm;
        cin>>tm;
        f.push_back(tm); 
    }
    sort(f.begin(),f.end());
    int tag[501];
    memset(tag,-1,sizeof tag);
    for(int i=0;i<f.size();i++)
        if(f[i]>ncc){ncc+=2;tag[i]=1;}
    for(int i=0;i<f.size();i++)
        if(tag[i]==-1){ ncc++;    
        }
    cout<<ncc<<endl;
   } 
    return 0;
}

