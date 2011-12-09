/*
 * Team : FreePascal
 * Created Time:  2011年10月29日 星期六 00时17分11秒
 * File Name: poj3750.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
#define SZ(v) ((int)(v).size())
int main() {
    list<string> f;
    int n,w,s;
    cin>>n;
    while(n--)
    {
        string ts;
        cin>>ts;
        f.push_back(ts);
    }
    //cin>>w>>s;
    scanf("%d,%d",&w,&s);
    list<string>::iterator p ;
    p = f.begin();
    for(int i = 1;i < w;i ++)
        p++;
    while(f.size() > 0)
    {
        for(int i = 1;i < s;i ++)
        {
            p++;
            //cout<<(*p)<<endl;
            if(p == f.end()) p = f.begin();
        }
        cout<< *p <<endl;
        list<string>::iterator lp = p;
        p++;
        if( p == f.end()) p = f.begin();
        //cout<<(*lp)<<endl;
        //cout<<(*p)<<endl;
        f.erase(lp);
        //cout<<f.size()<<endl;
        //cout<<"debug"<<endl;
    } 
    return 0;
}

