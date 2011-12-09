/*
 * Team : FreePascal
 * Created Time:  2011年08月13日 星期六 13时17分22秒
 * File Name: 813d.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())

typedef long long lint;
const int maxn = 50;
const int maxm = 1 << 21;
int CS,n,len,num[maxn];
lint ans;
char s[maxn],st[maxn],ss[maxn];

lint calc(int x,int k){
    lint sum = 1,ans = 1;
    for (int i = 1; i <= x; i++) ans *= i;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= num[i] - 1; j++) sum *= j;
        if (i != k && num[i] != 0) sum *= num[i];
    }
    return ans / sum;
}
void work(){
    ans = 0;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < n; j++){
            if (ss[j] >= s[i]) {
                num[j]--;
                break;
            }
            if (num[j] > 0) {
                lint tmp = calc(len - i -1,j);
                ans += tmp;
            }
        }
    }
}

int main() {
    scanf("%d",&CS);
    while (CS--){
        scanf("%s",s);
        len = strlen(s);
        strcpy(st,s);
        sort(st,st + len);
        memset(num,0,sizeof(num));
        n = 0;
        num[0] = 1; ss[0] = st[0];
        for (int i = 1; i < len; i++){
            if (st[i] == st[i - 1]) num[n]++;
            else {
                num[++n]++;
                ss[n] = st[i];
            }
        }
        n++;
        work();
        cout<<ans<<endl;
    }
    return 0;
}

