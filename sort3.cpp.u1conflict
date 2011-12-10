/*
ID:lc757692
TASK:sort3
LANG:C++

 * Author: Nfcj
 * Created Time:  2011年07月16日 星期六 18时02分02秒
 * File Name: sort3.cpp
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
int n,arr[1000];
int main() {
   ifstream cin("sort3.in");
   ofstream cout("sort3.out");
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
int n1,n2,n3;
n1=0;
n2=0;
n3=0;
    for(int i=0;i<n;i++)
        {
        if(arr[i]==1)n1++;
        if(arr[i]==2)n2++;
        if(arr[i]==3)n3++;
    }
//search 1
int num=0;
for(int i=0;i<n1;i++){
    if(arr[i]==2){
        int j;
        for(j=n1;j<n;j++)
            if(arr[j]==1)break;
        swap(arr[i],arr[j]);
        num++;
    }
    if(arr[i]==3){
        int j;
        for(j=n-1;j>=n1;j--)
            if(arr[j]==1)break;
        swap(arr[i],arr[j]);
        num++;
    }
}
//search2
for(int i=n1;i<n1+n2;i++){
    if(arr[i]==3){
            int j;
            for(j=n-1;j>=n1;j--)
                if(arr[j]==2)break;
            swap(arr[i],arr[j]);
            num++;
    }
}
cout<<num<<endl;
return 0;
}

    

