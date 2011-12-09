/*
 * Author: FreePascal
 * Created Time:  2011/11/4 21:20:38
 * File Name: poj3646.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int n,m;
vector<int> hd,hn;
int main() {
    while(cin>>n>>m && n && m)
    {
        hd.clear();
        hn.clear();
        for(int i = 0;i < n;i++){
            int t;
            cin>>t;
            hd.push_back(t);
        }
        for(int i = 0;i < m;i++){
            int t;
            cin>>t;
            hn.push_back(t);
        }
        if( m < n)
            puts("Loowater is doomed!");
        else
        {
            sort(hd.begin(),hd.end());
            sort(hn.begin(),hn.end());
            int k1,k2 = 0;
            int b = 0;
            long long ans = 0;
            for(k1 = 0;k1 < n;k1 ++)
                {
                    while(k2 < m && hn[k2] < hd[k1]) k2++;
                    if( k2 >= m) {
                        puts("Loowater is doomed!");
                        b = 1;
                        break;
                    }
                    else { ans+= hn[k2];k2++;}
                }
            if(!b) cout<<ans<<endl;
        }
    }
    return 0;
}

