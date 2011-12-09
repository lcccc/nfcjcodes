/*
 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 22时17分45秒
 * File Name: mult6.cpp
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
int cs,n,nd[100000];
int main() {
    cin>>cs;
    while(cs--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>nd[i];
        int b=0;
        for(int i1=0;i1<n-2;i1++)
            for(int i2=i1+1;i2<n-1;i2++)
                for(int i3=i2+1;i3<n;i3++)
            if( nd[i1]-nd[i2]==nd[i2]-nd[i3]){
                b=1;
                break;
            }
        if(b)cout<<"Y";
        else cout<<"N";
        cout<<endl;
    }
    return 0;
}

