/*
 * Team : FreePascal
 * Created Time:  2011年10月29日 星期六 00时17分01秒
 * File Name: poj3785.cpp
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
    return 0;
}

    {
        cin>>n>>s;
        cout<<n<<' ';
        if(next_permutation(s.begin(),s.end()))
            cout<<s<<endl;
        else cout<<"BIGGEST"<<endl;
    }
    return 0;
}

