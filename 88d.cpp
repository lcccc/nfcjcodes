/*
 * Team : FreePascal
 * Created Time:  2011年08月08日 星期一 13时27分28秒
 * File Name: 88d.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "map"
#include "iterator"
using namespace std;
#define SZ(v) ((int)(v).size())
#define $FOREACH(a, b) for (__typeof(b.begin()) a = b.begin(), a##ed = b.end(); a!=a##ed; a++)
char s[100100];
int N, K;

unsigned long long atgc[256];



map <unsigned long long, int> mp;

void insert()
{
    unsigned long long z = (atgc['A'] << 30) | (atgc['T'] << 20)  |  (atgc['G'] << 10) | atgc['C'] ;
    mp[z]++;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%s", &K, s);
        N = strlen(s);
        mp.clear();
        memset(atgc, 0, sizeof(atgc));
        for (int i=0; i<N; i++)
        {
            atgc[(int)s[i]]++;
            if (i < K-1) continue;
            if (i >= K)  atgc[(int)s[i-K]]--;
            insert();
        }
        int ans = 0;
        $FOREACH(m, mp)
            ans = max(m->second, ans);   
        printf("%d\n", ans);
    
    }
    return 0;
}

