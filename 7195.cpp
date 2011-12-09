/*
 * Author: Nfcj
 * Created Time:  2011年07月19日 星期二 16时13分29秒
 * File Name: 7195.cpp
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
    int n;
    while(cin>>n){
        if(n==-1)break;
        int bans=0,k=1;
        for(int i =1;i<20;i++)
        {
            k*=2;
            if(n==k){
                bans=1;
                cout<<"I bet on oregon Maple~"<<endl;
            }
        }
        if(bans!=1)cout<<"I bet on Grape Skin~"<<endl;
    }
    return 0;
}

