/*
 * Author: FreePascal
 * Created Time:  2011/11/14 20:16:10
 * File Name: F.cpp
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
void task1(int m,int n){
    string ans = "";
    while(m != n){
        if( m < n) ans += 'L',n -= m;
        else ans += 'R',m -= n;
    } 
    cout<<ans<<endl;
}
void task2(string seq){
    int L[2][2] = {{1,1},{0,1}};
    int R[2][2] = {{1,0},{1,1}};
    long long ans[2][2] = {{1,0},{0,1}};
    for(int i = 0;i < seq.size();i ++)
       if(seq[i] == 'L'){
          for(int i = 0;i < 2;i ++)
             for(int j = 0;j < 2;j ++)
             {
                long long sum = 0;
                for(int k = 0;k < 2;k ++)
                   sum += ans[i][k] * L[k][j];
                ans[i][j] = sum;
             } 
       }
       else{
           for(int i = 0;i < 2;i ++)
               for(int j = 0;j < 2;j ++)
               {
                   long long  sum = 0;
                   for(int k = 0;k < 2;k ++)
                       sum += ans[i][k] * R[k][j];
                   ans[i][j] = sum;
               }
       }
    cout<<ans[1][0]+ans[1][1]<<' '<<ans[0][0]+ans[0][1]<<endl;
}
int main() {
    int T,k,m,n;
    string seq;
    cin>>T;
    while(T--){
        cin>>k;
        if(k == 1)
        {
            cin>>m>>n;
            task1(m,n);
        }
        else
        {
            cin>>seq;
            task2(seq);
        }
    }
    return 0;
}

