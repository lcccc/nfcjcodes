/*
 * Team : FreePascal
 * Created Time:  2011年08月11日 星期四 16时00分26秒
 * File Name: 811a.cpp
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

const int maxn = 100000 + 100;
int n,m,abs1,abs2;
char s1[maxn],s2[maxn];
int main() {
    while (scanf("%d%d",&n,&m) != EOF){
        if (n == 0 && m == 0) break;
        scanf("%s",s1);
        scanf("%s",s2);
        if (n < m){
            puts("Hamlet");
            continue;
        }
        if (n > m){
            puts("Laertes");
            continue;
        }
        abs1 = 0; abs2 = 0;
        for (int i = 0; i < n; i++)
            if (s1[i] == 'H') abs1++;
            else abs1--;
        for (int i = 0; i < n; i++)
            if (s2[i] == 'H') abs2++;
            else abs2--;
        abs1 = abs(abs1); abs2 = abs(abs2);
        if (abs1 < abs2) {
            puts("Hamlet");
            continue;
        }
        if (abs1 > abs2){
            puts("Laertes");
            continue;
        }
        puts("Equal");
    }
    return 0;
}

