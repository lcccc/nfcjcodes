/*
 * Author: Nfcj
 * Created Time:  2011年07月18日 星期一 13时15分44秒
 * File Name: pro1.cpp
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
int f(int i)
{
    return i&(i^(i-1));
}
int main() {
int     n;
while(cin>>n){

    cout<<f(n)<<endl;
}
    return 0;
}

