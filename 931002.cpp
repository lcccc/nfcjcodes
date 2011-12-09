/*
 * Author: FreePascal
 * Created Time:  2011/9/3 14:13:44
 * File Name: 931002.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

#define h 10
typedef long long lint;
const int maxn = 10000;
const int maxlen = 200;
int CS,cnt,limit,prime[1300];
bool f[maxn + 10];
int len[310];
int sum[310][maxlen],n[200],ln;
char st[200];
//lint sum[310][maxlen];

void makeprimelist(){
    memset(f,true,sizeof(f));
    f[1] = false;
    for (int i = 2; i < (int)sqrt(maxn * 1.0); i++)
        if (f[i]){
            int j = i + i;
            while (j <= maxn){
                f[j] = false;
                j = j + i;
            }
        }
    cnt = 0;
    for (int i = 2; i <= maxn; i++)
        if (f[i]) prime[cnt++] = i;
}
void mul(int k,int b){
    memset(sum[k],0,sizeof(sum[k]));
    len[k] = len[k - 1];
    for (int i = 1; i <= len[k]; i++){
        sum[k][i] = sum[k][i] + sum[k - 1][i] * b;
        sum[k][i + 1] = sum[k][i] / h;
        sum[k][i] = sum[k][i] % h;
    }
    while (sum[k][len[k] + 1] > 0) len[k]++;
}
void makesum(){
    len[0] = 1; sum[0][1] = 2;
    for (int i = 1; i < 300; i++){
        mul(i,prime[i]);
        if (len[i] > 100){
            limit = i;
            break;
        }
    }
}
bool check(int k,int n[200]){
    if (len[k] > ln) return false;
    if (len[k] < ln) return true;
    for (int i = ln; i >= 1; i--){
        if (sum[k][i] > n[i]) return false;
        if (sum[k][i] < n[i]) return true;
    }
    return true;
}

int main() {
    //freopen("9310021.in","r",stdin);
    //freopen("931002.out","w",stdout);
    makeprimelist();
    makesum();
    scanf("%d",&CS);
    while (CS--){
        scanf("%s",st);
        ln = strlen(st);
/*
        int i = 0;
        while (i < ln){
            for (int j = 0; j < 4; j++){
                int k = i + j;
                n[k + 1] = st[ln - k - 1] - 48;
            }
            i += 4;
        }
*/
        for (int i = 0; i < ln; i++) n[i + 1] = st[ln - i - 1] - 48;
        int l = 0, r = limit;
        int ans;
        while (l <= r){
            int mid = (l + r) / 2;
            if (check(mid,n)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        for (int i = len[ans]; i >= 1; i--) printf("%d",sum[ans][i]);
/*
        printf("%d",sum[ans][len[ans]]);
        for (int i = len[ans] - 1; i >= 1; i--){
            if (sum[ans][i] > 10000) printf("%d",sum[ans][i]);
            else if (sum[ans][i] > 1000) printf("0%d",sum[ans][i]);
            else if (sum[ans][i] > 100) printf("00%d",sum[ans][i]);
            else if (sum[ans][i] > 10) printf("000%d",sum[ans][i]);
            else printf("0000%d",sum[ans][i]);
        }
*/
        printf("\n");
    }
    //fclose(stdout);
    return 0;
}

