/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 15时01分40秒
 * File Name: 1006.cpp
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

const int maxn = 200 + 10;
int CS,a[maxn],b[maxn],c[maxn],ans[maxn];
char s1[maxn],s2[maxn];
void move(int b[]){
    for (int i = b[0]; i > 0; i--) b[i + 1] = b[i];
    b[1] = 0;
    b[0]++;
}
void substract(int b[],int a[]){
    int d[maxn];
    memset(c,0,sizeof(c));
    for (int i = 1; i <= b[0]; i++) d[i] = b[i];
    d[0] = b[0];
    for (int i = 1; i <= b[0]; i++){
        if (d[i] < a[i]){
            d[i] = d[i] + 10;
            d[i + 1]--;
        }
        c[i] = d[i] - a[i];
    }
    c[0] = d[0];
    while (c[c[0]] == 0 && c[0] > 1) c[0]--;
}
void get_min(int a[],int b[]){
    if (a[0] < b[0]) return;
    if (a[0] == b[0])
        for (int i = a[0]; i > 0; i--)
            if (a[i] < b[i]) return;
            else if (a[i] > b[i]) break;
    for (int i = 1; i <= b[0]; i++) a[i] = b[i];
    a[0] = b[0];
}

int main() {
    scanf("%d",&CS);
    int cs = 0;
    while (CS--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        printf("Case #%d: ",++cs);
        scanf("%s",s1);
        scanf("%s",s2);
        if (strstr(s1,s2)) {
            printf("0\n");
            continue;
        }
        a[0] = strlen(s1);
        for (int i = 0; i < a[0]; i++) a[i + 1] = s1[a[0] - i - 1] - 48;
        b[0] = strlen(s2);
        for (int i = 0; i < b[0]; i++) b[i + 1] = s2[b[0] - i - 1] - 48;
        ans[0] = 300;
        substract(b,a);
        get_min(ans,c);
        for (int i = 0; i <= a[0]; i++){
            move(b);
            substract(b,a);
            get_min(ans,c);
        }
        for (int i = ans[0]; i > 0; i--) printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}

