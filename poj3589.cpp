/*
 * Author: FreePascal
 * Created Time:  2011/11/2 15:09:18
 * File Name: poj3589.cpp
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
string s1,s2;
int main() {
    cin>>s1;
    while(cin>>s1>>s2)
    {
        int k = 0;
        for(int i = 0;i < 4;i ++)
            if(s1[i] == s2[i])k++;
        cout<<k<<'A';
    k = 0;
    for(int i = 0;i < 4;i ++)
        for(int j = 0;j < 4;j++)
            if(i!=j && s1[i] == s2[j])
            {
                k++;
                break;
            }
    cout<<k<<'B'<<endl;
    }
    return 0;
}

