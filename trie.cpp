/*
 * Author: lccccc 
 * Created Time:  2011/11/2 16:22:26
 * File Name: trie.cpp
 */
  // 动态建树，删除操作只是标记一下，并没有真正从内存中删去
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
struct node{
   char key;
   node* chil[26];
   int ter;
  node(){
    key = 'x';
    for(int i = 0;i < 26;i ++)
       chil[i] = NULL;
   ter = 0;
  }
}; 
void insert(node* root,char* st)
{
    for(int i = 0;i < strlen(st);i ++)
    {
        if(root->chil[ st[i] - 'a'] == NULL){
            node* tm = new node();
            tm->key = st[i];
            root->chil[st[i] - 'a'] = tm;
            root = tm;
        }
        else {
            root = root->chil[ st[i] - 'a'];
        }
    }
    root -> ter = 1;
}
void del(node* root,char* st)
{
    for(int i =  0;i < strlen(st);i ++)
    {
        if( root->chil[ st[i] - 'a'] == NULL)
            return;
        root = root->chil[ st[i] - 'a'];
    }
    if(root->ter == 1) root->ter = 0;
}
bool sear(node* root,char* st)
{
    for(int i = 0;i < strlen(st);i ++)
    {
        if( root->chil[ st[i] - 'a'] == NULL)
            return 0;
        root = root->chil[ st[i] - 'a'];
    }
    if(root->ter) return 1;
    return 0;
}
int main() {
    node* root;
    root = new node();
    cout<<root->key<<endl;
    insert(root,"lcccccc");
    insert(root,"lcxxxxx");
    del(root,"lcccccc");
    cout<<sear(root,"lcccccc")<<endl;
    cout<<sear(root,"lcc")<<endl;
    return 0;
}

