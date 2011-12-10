/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 16:00:50
 * File Name: tyvj1596.cpp
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

int main() {
    int n,cs[20],a,b,ans =0;
    //cin>>n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        //cin>>cs[i];
        scanf("%d",&(cs[i]));
    //cin>>a>>b;
    scanf("%d",&a,&b);
    for(int i = a;i <= b;i++)
    {
        int tag = 1;
        for(int j = 0;j < n;j++)
            if( i % cs[j] == 0 || i % 8) {tag =0;break;}
        if(tag) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

