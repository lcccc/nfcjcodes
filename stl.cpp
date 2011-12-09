/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/3 12:20:53
 * File Name: stl.cpp
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
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int main() {
    int arr[] = { 1,2,3,2,1,4,6};
    vector<int> f(arr,arr+7);
    sort(f.rbegin(),f.rend());
    vector<int>::iterator p;
    for(p = f.begin(); p != f.end(); p++)
        cout<<*p<<endl;
    return 0;
}

