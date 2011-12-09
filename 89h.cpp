/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 12时58分24秒
 * File Name: 89h.cpp
 */

#include <cstdio>
#include <cstdlib>
#include<iostream>
#include<vector>
using namespace std;
#define SZ(v) ((int)(v).size())

typedef long long lint;
const int maxn = 35 + 10;
int n;
lint a[maxn];
struct node{
    lint x;
    int cnt;
    node (lint _x,int _cnt):
        x(_x),cnt(_cnt) {}
    node() {};
};
vector<node> sum;

lint absolute(lint x){
    if (x < 0) return -x;
    else return x;
}
bool cmp(node const &a,node const &b){
    return absolute(a.x) < absolute(b.x) || (absolute(a.x) == absolute(b.x) && a.cnt < b.cnt);
}
int main() {
    while (scanf("%d",&n) != EOF){
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin>>a[i];
        sum.clear();
        {
            vector<node> tmp(0);
            tmp.swap(sum);
        }
        for (int i = 1; i <= n; i++){
            int m = (int)sum.size();
            for (int j = 0; j < m; j++){
                lint x; int cnt;
                x = a[i] + sum[j].x;
                cnt = sum[j].cnt + 1;
                sum.push_back(node(x,cnt));
            }
            sum.push_back(node(a[i],1));
        }
        node ans;
        ans = sum[0];
        for (int i = 1; i < sum.size(); i++)
            if (cmp(sum[i],ans)) ans = sum[i];
        cout<<absolute(ans.x)<<" "<<ans.cnt<<endl;
    }
    return 0;
}
