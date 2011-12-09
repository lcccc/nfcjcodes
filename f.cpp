/*
 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 16时00分29秒
 * File Name: f.cpp
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
int n,ans;
vector<int> lin;
int main() {
    cin>>n;
    ans = 0;
    int tm;
    for(int i=0;i<n;i++){
        cin>>tm; 
        lin.push_back(tm);
    }
    for(int i=0;i<lin.size();i++)
    {
        if(fabs(lin[i]-lin[i+1])!=1)continue;
        int i1,i2,i3;
        i1=lin[i];
        i2=lin[i+1];
        i3=lin[i+2];
        if(fabs(i1-i2)==1&&fabs(i2-i3)==1){
            vector<int>::iterator vp;
            vp=lin.begin();
            for(int i=0;i<=i+1;i++)vp++;
            lin.erase(vp);
            i--;
            continue;
        }
        else
        {
            vector<int>::iterator vp;
            vp=lin.begin();
            for(int i=0;i<i;i++)vp++;
            
            lin.erase(vp);
            i--;
            continue;
        }
    }
       
    cout<<lin.size()<<endl;
    for(int i=0;i<lin.size();i++)
        cout<<lin[i]<<endl;

     
    
        
        
    return 0;
}

