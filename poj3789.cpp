/*
 * Team : FreePascal
 * Created Time:  2011年10月28日 星期五 23时54分38秒
 * File Name: poj3789.cpp
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
string change(int x)
{
    string ans;
    int k = 32;
    while( k > 0)
    {
        if(x / k ) ans+="1";
        else ans+="0";
        //ans += char('0' + x / k);
        x %= k;
        k /= 2;
    }
    //if(ans.size() < 6) ans+='0';
    return ans;
}
int main() {
    int cs,T=1;
    scanf("%d",&cs);
    while(cs--)
    {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        string hs,ms,ss;
        hs = change(h);
        ms = change(m);
        ss = change(s);
        //cout<<hs<<' '<<ms<<' '<<ss<<endl;
        cout<<T++<<' ';
        for(int i = 0;i < 6;i++)
           cout<<hs[i]<<ms[i]<<ss[i];
       cout<<' ';
      cout<<hs<<ms<<ss<<endl; 
    }
    return 0;
}

