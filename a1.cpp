/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 12时50分23秒
 * File Name: 
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

const int maxn = 2000000;
const int maxm = 1000 + 100;
int CS,ans,sum,a[maxm];
char st[maxn],s[100];;
int main() {
    scanf("%d",&CS);
    while (CS--){
        gets(st);
        ans = 0; sum = 0; int cnt = 0;
        while (sscanf("%s",st,s[cnt])){
            a[cnt] = strlen(s);
            cnt++;
        }
        ans = 0; sum = 1;
        for (int i = 1; i < cnt; i++)
            if (a[i] == a[i - 1]) sum++;
            else {
                ans = max(ans,sum);
                sum = 0;
            }
        printf("%d\n",ans);
    }
    return 0;
}

