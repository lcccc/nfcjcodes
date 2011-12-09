/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/3 15:22:20
 * File Name: 
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


void print(int k)
{
    printf(" %d %d",  k/4+1, k%4+1);
}

int main() {
    freopen("83j.in", "w", stdout);
    for (int i=0; i<16; i++)
        for (int j=i+1; j<16; j++)
            for (int k=j+1; k<16; k++)
                for (int l=k+1; l<16; l++)
                {
                    print(i); print(j); print(k); print(l);
                    printf("\n");
                }
    return 0;
}

