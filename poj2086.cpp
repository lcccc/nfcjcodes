/*
 * Author: FreePascal
 * Created Time:  2011/10/13 15:05:25
 * File Name: poj2086.cpp
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
int T[305];
void init(){
    for(int i = 0;i <= 305;i ++)
        T[i] = (1+i)*i / 2;
}
long long f(int x)
{
    long long sum = 0;
    for(int k = 1;k <= x;k ++)
        sum += (long long)k*T[k+1];
    return sum;
}
int cs,Cs =1,n;
int main() {
    init();
    cin>>cs;
    while(cs--)
    {
        cin>>n;
        //cout<<f(n)<<endl;
        //printf("%d %d %lld\n",Cs++,n,f(n));
        cout<<Cs++<<' '<<n<<' '<<f(n)<<endl;
    }
    return 0;
}

