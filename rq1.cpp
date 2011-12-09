/*
 * Author: FreePascal
 * Created Time:  2011/10/11 0:21:57
 * File Name: rq1.cpp
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
int f(int x)
{
    return  ((x ^ (2*x) ^ (3*x)) == 0) ;
}
void fout(int x)
{
    if( x == 0 || x == 1) { cout<<x; return;}
    else
    {
        cout<<x%2;
        fout(x/2);
    }
}
int ans[500002];
void init(){
    ans[1] = 2;
    ans[2] = 3;
    ans[3] = 5;
    for(int i = 4;i <= 500000;i ++)
        ans[i] = (ans[i-1]+ans[i-2]) % 1000000009;
}
int main() {
    init();
int t,n;
scanf("%d",&t);
while(t--)
{
    scanf("%d",&n);
    printf("%d\n",ans[n]);
}
return 0;
}

