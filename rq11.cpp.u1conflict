/*
 * Author: FreePascal
 * Created Time:  2011/10/11 12:50:02
 * File Name: rq11.cpp
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
int m,n,num[10];
void f(int i)
{
    while(i > 0)
    {
        num[i % 10] ++;
        i /= 10;
    }
    return;
}
int main() {
    memset(num,0,sizeof num);
    cin>>m>>n;
    for(int i = m;i <= n;i ++)
        f(i);
    for(int i = 0;i < 10;i ++)
    {
       cout<<num[i];
        if(i != 9) cout<<' ';
        else cout<<endl; 
    }
    return 0;
}

