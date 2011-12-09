/*
 * Author: FreePascal
 * Created Time:  2011/9/10 14:10:48
 * File Name: 9101007.cpp
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

typedef long long lint;
const int maxn = 100000 + 100;
const lint limit = 1LL << 63 - 1;
int n,m;
lint b[maxn];
struct node{
    lint data,num;
    bool lazy;
}a[maxn * 5];

void update(lint node,lint l,lint r){
    a[node * 2].num += a[node].num;
    a[node * 2 + 1].num += a[node].num;
    a[node].num = 0;
}
void insert(int node,int l,int r,int pos,lint x){
    if (l == r){
        a[node].data = x; a[node].num = 0; a[node].lazy = false;
        //printf("%d %d %d %d\n",node,l,r,x);
        return;
    }
    if (pos <= (l + r) / 2) insert(node * 2,l,(l + r) / 2,pos,x);
    else insert(node * 2 + 1,(l + r) / 2 + 1,r,pos,x);
    //a[node].data = a[node * 2].data + a[node * 2 + 1].data;
    a[node].num = 0;
}
void change(int node,int l,int r,int left,int right){
    if (left <= l && r <= right){
        a[node].num++;
        return;
    }
    update(node,l,r);
    if (left <= (l + r) / 2) change(node * 2,l,(l + r) / 2,left,right);
    if (right >= (l + r) / 2 + 1) change(node * 2 + 1,(l + r) / 2 + 1,r,left,right);
    /*
    if (right <= (l + r) / 2) change(node * 2,l,(l + r) / 2,left,(l + r) / 2);
    else if (left >= (l + r) / 2 + 1) change(node * 2 + 1,(l + r) / 2 + 1,r,(l + r) / 2 + 1,right);
    else{
        if (left <= (l + r) / 2) change(node * 2,l,(l + r) / 2,left,(l + r) / 2);
        if (right >= (l + r) / 2 + 1) change(node * 2 + 1,(l + r) / 2 + 1,r,(l + r) / 2 + 1,right);
    }
    */
    //a[node].data = a[node * 2].data + a[node * 2 + 1].data;
}
lint find(int node,int l,int r,int left,int right){
    lint sum = 0;
    if (l == r){
        //printf("%I64d %I64d\n",a[node].data,a[node].num);
        for (int i = 0; i < a[node].num; i++) a[node].data = (lint)sqrt(a[node].data);
        a[node].num = 0; a[node].lazy = true;
        return a[node].data;
    }
//*
    if (left <= l && r <= right){
        //if (a[node].num == 0) return a[node].data;
        //printf("%I64d %d\n",a[node].data,a[node].lazy);
        //out(a[node].lazy);
        if (a[node].lazy) return a[node].data;
        update(node,l,r);
        sum += find(node * 2,l,(l + r) / 2,left,right);
        sum += find(node * 2 + 1,(l + r) / 2 + 1,r,left,right);
        a[node].data = a[node * 2].data + a[node * 2 + 1].data;
        a[node].lazy = a[node * 2].lazy & a[node * 2 + 1].lazy;
        return sum;
    }
//*/
    update(node,l,r);
    if (left <= (l + r) / 2) sum += find(node * 2,l,(l + r) / 2,left,right);
    if (right >= (l + r) / 2 + 1) sum += find(node * 2 + 1,(l + r) / 2 + 1,r,left,right);
    a[node].data = a[node * 2].data + a[node * 2 + 1].data;
    a[node].lazy = a[node * 2].lazy & a[node * 2 + 1].lazy;
    return sum;
}
void clear(int node,int l,int r){
    a[node].lazy = false;
    if (l == r) return;
    clear(node * 2,l,(l + r) / 2);
    clear(node * 2 + 1,(l + r) / 2 + 1,r);
}

int main() {
    int cs = 0;
    while (scanf("%d",&n) != EOF){
        memset(a,0,sizeof(a));
        for (int i = 1; i <= n; i++){
            lint x;
            scanf("%I64d",&x);
            insert(1,1,n,i,x);
        }
        printf("Case #%d:\n",++cs);
        scanf("%d",&m);
        for (int i = 0; i < m; i++){
            int t; lint x,y;
            scanf("%d%I64d%I64d",&t,&x,&y);
            if (t == 0){
                change(1,1,n,x,y);
                clear(1,1,n);
            }
            else{
                lint ans = find(1,1,n,x,y);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}

