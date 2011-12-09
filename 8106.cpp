/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 19时50分12秒
 * File Name: 8106.cpp
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
int LowBit(int x){
    return x&(-x);
}
int main() {
    int n;
    while(cin>>n && n != 0)
        cout<<LowBit(n)<<endl;
    return 0;
}

