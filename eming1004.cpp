/*
 * Author: FreePascal
 * Created Time:  2011/11/27 15:06:49
 * File Name: eming1004.cpp
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
    int k,p,q;
    cin>>k;
    while(cin>>p>>q)
    {
        for(int i = 1;i < q;i ++)
            if( p * i % q == 1) 
            {
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}

