/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/3 13:23:17
 * File Name: 83a.cpp
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
const double g = 9.81;
const double eps = 1e-8;
//double h,l,w;
int h,l,w;
int main() {
    while(cin>>l>>h>>w){
        //h = h - l/2;
        double hh = h - (double)l / 2;
        if (h <= 0) {
            printf("butter\n");
            continue;
        }
        double t = sqrt(hh * 2 / g);
        double ang = 6 * t * w - (int)((6 * t * w) / 360) * 360;
        //double t = sqrt((h + h)/g);
        //double ang = 6*t*w- (int)((6*t*w)/360)*360;
        //double t = (2 * h / g);
        //double tmp = sqrt(36 * t * w * w);
        //double ang = tmp - (int)(tmp / 360) * 360;
        out(ang);
        if( ang > 90 && ang < 270 ) printf("bread\n");
        else printf("butter\n");
    }
    return 0;
}

