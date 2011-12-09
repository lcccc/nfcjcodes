/*
 * Author: FreePascal
 * Created Time:  2011/10/11 0:11:49
 * File Name: rqnoj.cpp
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

int main() {
    set<int> f;
    int n,k;
    cin>>n;
    for(int i = 0;i <n;i ++)
    {
        cin>>k;
        f.insert(k);
    }
    set<int>::iterator p;
    cout<<f.size()<<endl;
    for(p = f.begin();p != f.end();p ++)
    {
        if(p!=f.begin()) cout<<' ';
        cout<<*p;
    }
    return 0;
}

