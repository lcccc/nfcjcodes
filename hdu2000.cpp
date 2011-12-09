/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时00分55秒
 * File Name: hdu2000.cpp
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
    char ca,cb,cc;
    while(cin>>ca>>cb>>cc)
    {
        if(ca>cb) swap(ca,cb);
        if(ca>cc) swap(ca,cc);
        if(cb>cc) swap(cb,cc);
        cout<<ca<<' '<<cb<<' '<<cc<<endl;
       // cin>>ca;
    }
    return 0;
}

