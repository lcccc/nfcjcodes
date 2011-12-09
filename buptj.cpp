/*
 * Author: Nfcj
 * Created Time:  2011年07月16日 星期六 10时20分14秒
 * File Name: buptj.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define SZ(v) ((int)(v).size())

int main() {
    int n,t,bf,bo;
    while(cin>>n){
        bf=0;
        bo=1;
        for(int i=1;i<=n;i++)
        {
            cin>>t;
            if(t==i){
                bf=1;
                if(!bo)cout<<' ';
                bo=0;
                cout<<t;
            }
        }
        if(bf==0)cout<<"No Mistake";
        cout<<endl;
    }
    return 0;
}

