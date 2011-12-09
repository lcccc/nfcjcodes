/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/27 12:56:28
 * File Name: prime3.cpp
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
bool ispm(int x)
    {
        for(int i = 2;i <= int(sqrt(x)) ; i ++)
            if( x % i == 0) return false;
        return true;
    }
int main() {
    return 0;
}

