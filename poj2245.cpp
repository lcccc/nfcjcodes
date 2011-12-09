/*
 * Author: FreePascal
 * Created Time:  2011/10/13 11:15:30
 * File Name: poj2245.cpp
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
int k,f[15],ans[15];
void output(){
    for(int i = 0;i < 6; i++)
    {
        printf("%d",ans[i]);
        if(i != 5) printf(" ");
    }
    printf("\n");
}
void dfs(int i,int j)
{
    //out(i);
    //out(j);
    if( i >= 6) {
        output();
        return;
    }
    else
    {
        for(int i1 = j; i1 < k; i1++)
        {
            ans[i] = f[i1];
            dfs(i+1,i1+1);
        }
    }
}
int main() {
    while(cin>>k && k)
    {
        for(int i = 0;i < k;i ++)cin>>f[i];
        dfs(0,0);
        printf("\n");
    }
    return 0;
}

