/*
 * Team : FreePascal
 * Created Time:  2011年08月11日 星期四 16时20分21秒
 * File Name: db.cpp
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "bitset"
using namespace std;
#define SZ(v) ((int)(v).size())
int tag[100];
int ans,n;
int que1[100],que2[100];
int cnt[256];
#define Bitset bitset
#define size 10
Bitset<10>A;
vector <int> B;

Bitset<10> operator *(Bitset<10> &a, vector<int> b)
{
    Bitset<10> z;
    for (vector<int>::iterator it =b.begin(), e=b.end(); it!=e; it++)
           z = z | (a << *it);
    return z;
}

void dfs(int p,int sta,int stb, bitset<10> &A, vector<int>&B)
{
    if (p==n)
    {
         if ( (int)(A*B).count()==n*n )  ans++;
         return;   
    }
    for (int i=sta+1; i<=n*n; i++)
    {
        A.set(i);
        B.push_back(0);
        for (int j=stb+1; j<=n*n; j++)
        {
             *B.rbegin() = j;
             if ( (int)(A*B).count() != p*p )continue;
             dfs(p+1, i, j, A, B);      
        }
        B.resize(B.size()-1);
        A.reset(i);
    }
}

int main() {
    while(scanf("%d", &n)!=EOF)
    {
      ans = 0;    
      A.reset();
      B.clear();
      B.push_back(1);
      dfs(2,0,1,A,B);
      cout<<ans<<endl;
    } 
    return 0;
}

