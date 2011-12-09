/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 12时34分38秒
 * File Name: 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "sstream"
using namespace std;
#define SZ(v) ((int)(v).size())
int a[2048000];
int main() {
    int T;
    scanf("%d\n", &T);
    while (T--)
    {
        static char s[2048000];
        gets(s);
        stringstream str(s);
        string c;
        int tot = 0;
        while (str>>c)
            a[tot++] = c.size();
        int ans = !!tot;
        
        int   k = 1;
        for (int i=1; i<tot; i++)
            if (a[i] == a[i-1]) k++, ans=max(ans, k);
            else k=1,ans = max(ans,k);
        printf("%d\n", ans);
    }
    return 0
}

