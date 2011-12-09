/*
 * Author: Nfcj
 * Created Time:  2011年07月25日 星期一 12时35分42秒
 * File Name: 725b.cpp
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
    string s1,s2;
    int ncow,nbull;
    cin>>s1>>s2;
    ncow = 0;
    nbull = 0;
    for(int i =0 ; i < 4;i++)if(s1[i] == s2[i]) nbull++;
    for(int i=0 ; i< 4;i++)
        for(int j=0; j<4; j++)
            if(s1[i] == s2[j] && i!= j) ncow++;
    cout<<nbull<<' '<<ncow<<endl;    
    return 0;
}

