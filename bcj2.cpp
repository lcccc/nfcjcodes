/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/8 19:48:00
 * File Name: bcj1.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
struct uset
{
    int f[100005],nm[100005];
    
    uset(){
        for(int i = 0;i < 100005;i++) f[i] = i,nm[i] = 1;
    }
    int find(int x){
        while(f[x] != x) x = f[x];
        return x;
    }
    int unset(int a,int b)
    {
        if( find(a) == find(b) )return 0;
        nm[find(b)]+=nm[find(a)];
        f[find(a)] = find(b);
        return 1;
    }
};
int main() {
    int cs;
   while(scanf("%d",&cs)!= EOF){
    while(cs--){
    int a,b,n,tot=1;
    uset set;
    map<string,int> mp;
        //cin>>n;
        scanf("%d",&n);
        if( n == 0) cout<<0<<endl;
        else {
        for(int i = 1;i <= n;i++)
        {
            char cca[25],ccb[25];
            scanf("%s%s",cca,ccb);
            string sa(cca);
            string sb(ccb);
            if(mp[sa]) a = mp[sa];
            else {
                mp[sa] = tot++;
                a = mp[sa];
            }
            if(mp[sb]) b = mp[sb];
            else {
                mp[sb] = tot++;
                b = mp[sb];
            }
          set.unset(a,b);
          printf("%d\n",set.nm[set.find(b)]);
        }  
        }
    }
   }
    return 0;
}


