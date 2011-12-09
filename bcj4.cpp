/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/9 9:47:46
 * File Name: bcj4.cpp
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
struct bcj{
    int sum;
    int f[10000+5];
    int nm[10000+5];
    int tr[10000+5];
    bcj(){
        for(int i = 1;i <= 10000;i++)
        {
            nm[i] = 1;
            f[i] = i;
            tr[i] = 0;
        }
        //sum = 1;
            
    }
    int find(int x)
    {
        while(x !=f[x]) x = f[x];
        return x;
    }
    bool unset(int a,int b)
    {
        int fa = find(a);
        int fb = find(b);
        if( fa == fb ) return false;
        f[fa] = fb;
        nm[fb] += nm[fa];
        tr[fb] += tr[fa];
        //if( nm[fb] > sum) sum = nm[fb];
        return true;
    }
};
int main() {
    
    int cs,n,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++){
        printf("Case %d:\n",cs);
        int n,q;
        scanf("%d%d",&n,&q);
       int a,b,ans = 0;
       char c;
       bcj set;
     for(int i = 1;i <= q;i++)
     {
         getchar();
        scanf("%c",&c); 
        if( c == 'T')
        {
        scanf("%d%d",&a,&b);
        set.unset(a,b);
        }
        if(c == 'Q') 
        {
            scanf("%d",&a);
            printf("%d %d %d\n",set.find(a),set.nm[set.find(a)],set.tr[a]);
        }
     }
    }

    return 0;
}

