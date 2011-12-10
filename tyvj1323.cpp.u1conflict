/*
 * Team : FreePascal
 * Created Time:  2011年08月28日 星期日 16时06分02秒
 * File Name: tyvj1323.cpp
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
const int maxn = 200000;
struct set{
    int f[maxn];
    bool d[maxn];
    set(){
        for(int i = 0;i < maxn;i++)
            f[i] = i,d[i] = 1;
    }
    int find(int x){
        while(f[x]!=x) x = f[x] ;
        return x;
    }
    bool un(int a,int b)
    {
        int fa = find(a) , fb = find(b);
        if (d[a] ||
            d[b] || 
            d[fa]
            )
        {
            d[fb] = 1;
        }
        f[fa] = fb;
        return true;
    }
    bool isd(int x)
    {
        return d[find(x)];
}
};
set u_set;
string s1,s2;
int n,m,p;
string tran(string s)
{
    string ans;
    for(int i = 0 ; i < s.size() ;i++)
        ans+= s1[s2.find(s[i])];
    return ans;
}
int main() {
    cin>>s1>>s2;
    cin>>n>>m;
    for(int i = 0;i < m;i++)
    {
       int k;
      string s;
      cin>>k>>s;
      if(tran(s).find("poison") != string::npos ) {
          u_set.d[k] = 1;
          //cout<<"poi "<<k<<endl;
      }
      else u_set.d[k] = 0;
    } 
    //cout<<u_set.d[3]<<endl;
    cin>>p;
    for(int i = 0;i < p ;i ++)
    {
        int a,b;
        cin>>a>>b;
        u_set.un(a,b);
    }
    int ans = 0;
    for(int i = 1;i <=n; i++)
        if(!u_set.isd(i)){
            ans++;
        }
    cout<<ans<<endl;
    return 0;
}

