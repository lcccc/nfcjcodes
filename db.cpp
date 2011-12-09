<<<<<<< HEAD
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

=======
#include<iostream>
using namespace std;
main(){
cout<<"1:1 10"<<endl;
cout<<"1:2 31"<<endl;
cout<<"1:3 11"<<endl;
cout<<"1:4 21"<<endl;
cout<<"1:5 19"<<endl;
cout<<"1:6 18"<<endl;
cout<<"1:7 25"<<endl;
cout<<"1:8 20"<<endl;
cout<<"1:9 25"<<endl;
cout<<"1:10 27"<<endl;
cout<<"1:11 31"<<endl;
cout<<"1:12 35"<<endl;
cout<<"1:13 11"<<endl;
cout<<"1:14 40"<<endl;
cout<<"1:15 21"<<endl;
cout<<"1:16 33"<<endl;
cout<<"1:17 15"<<endl;
cout<<"1:18 25"<<endl;
cout<<"1:19 11"<<endl;
cout<<"1:20 25"<<endl;
cout<<"1:21 33"<<endl;
cout<<"1:22 29"<<endl;
cout<<"1:23 11"<<endl;
cout<<"1:24 34"<<endl;
cout<<"1:25 36"<<endl;
cout<<"1:26 50"<<endl;
cout<<"1:27 21"<<endl;
cout<<"1:28 49"<<endl;
cout<<"1:29 33"<<endl;
cout<<"1:30 37"<<endl;
cout<<"1:31 24"<<endl;
cout<<"2:1 13"<<endl;
cout<<"2:2 31"<<endl;
cout<<"2:3 31"<<endl;
}
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
