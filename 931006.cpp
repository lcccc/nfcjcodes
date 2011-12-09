/*
 * Author: FreePascal
 * Created Time:  2011/9/3 12:20:46
 * File Name: 931006.cpp
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

const int maxn = 1000000 + 100;
int n,k,cnt,root;
char st[2];
struct node{
    int data,lch,rch,rp,v,id;
}tree[maxn];
void r_rotate(int &x){
    int y;
    y = tree[x].lch; tree[x].lch = tree[y].rch; tree[y].rch = x;
    tree[y].v = tree[x].v; tree[x].v = tree[tree[x].lch].v + tree[tree[x].rch].v + 1;
    x = y;
}
void l_rotate(int &x){
    int y;
    y = tree[x].rch; tree[x].rch = tree[y].lch; tree[y].lch = x;
    tree[y].v = tree[x].v; tree[x].v = tree[tree[x].lch].v + tree[tree[x].rch].v + 1;
    x = y;
}
void insert(int &node,int x){
    //if (tree[node].data == x) return;
    if (tree[node].data == 0 || node == 0){
        node = ++cnt;
        tree[node].data = x;
        tree[node].v = 1;
        //tree[node].id = id;
        tree[node].rp = rand();
        return;
    }
    tree[node].v++;
    if (x < tree[node].data) insert(tree[node].lch,x);
    else insert(tree[node].rch,x);
    if (tree[node].lch != 0 && tree[tree[node].lch].rp > tree[node].rp) r_rotate(node);
    else if (tree[node].rch != 0 && tree[tree[node].rch].rp > tree[node].rp) l_rotate(node);
    //tree[node].v += tree[tree[node].lch].v + tree[tree[node].rch].v;
}
int find(int node,int x){
    //out(x);
    //out(tree[tree[node].rch].v);
    if (x == tree[tree[node].rch].v + 1) return tree[node].data;
    if (x <= tree[tree[node].rch].v) return find(tree[node].rch,x);
    else return find(tree[node].lch,x - tree[tree[node].rch].v - 1);
}

int main() {
    while (scanf("%d%d",&n,&k) != EOF){
        memset(tree,0,sizeof(tree));
        cnt = 0; root = 0;
        for (int i = 0; i < n; i++){
            scanf("%s",st);
            if (st[0] == 'I'){
                int x;
                scanf("%d",&x);
                insert(root,x);
            }
            else{
                int ans = find(root,k);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

