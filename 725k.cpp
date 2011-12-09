/*
 * Author: Nfcj
 * Created Time:  2011年07月25日 星期一 13时25分47秒
 * File Name: 725k.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

int main() {
    double n,m;
    cin>>n>>m;
    printf("%.10lf\n",n-n*pow((n-1)/n,m));
    return 0;
}

