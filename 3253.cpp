/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/17 17:09:26
 * File Name: 3253.cpp
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
#include <functional>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
priority_queue<LL,vector<LL>,greater<LL> >f;
int main() {
    int n,k,t;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
       scanf("%d",&k);
       f.push(k);
    }
    long long ans = 0;
    for(int i=1;i<n;i++)
    {
       LL a1,a2;
      a1 = f.top();
      f.pop();
      //cout<<a1<<endl;
      a2 = f.top();
      //cout<<a2<<endl;
      f.pop();
      f.push(a1+a2);
      ans+= a1+a2;
    }
    //printf("%d\n",ans);
    cout<<ans<<endl;
 
    return 0;
}

