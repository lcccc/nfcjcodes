/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/8 20:45:23
 * File Name: bcj3.cpp
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
struct union_set{
    const static int MAX = 1000+5;
    int f[MAX];
    union_set(){
        for(int i=0;i < MAX;i++)f[i] = i;
    }
    int set_find(int x)
    {
        while(x != f[x]) x = f[x];
        return x;
    }
    int set_union(int a,int b)
    {
        if( set_find(a) == set_find(b)) return 0;
        f[set_find(a)] = set_find(b);
        return 1;
    }
};
int main() {
    int n,m;
    while(1){
        cin>>n;
        if( n == 0) break;
        cin>>m;
        union_set set;
        for(int i = 0;i < m;i++)
        {
            int a,b;
            cin>>a>>b;
            set.set_union(a,b);
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if( set.f[i] == i ) ans++;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}

