/*
 * Author: FreePascal
 * Created Time:  2011/9/27 21:39:11
 * File Name: 
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
vector<string> dic;
string s;
char cs[20];
int  num1[100],num2[100];
int n;
bool can(string ss)
{
    int k = 0;
    for(int i = 0;i < 99;i ++)
        num2[i] = num1[i];
    for(int  i = 0;i < ss.size();i ++)
        num2[ss[i]] --;
    for(char a = 'A'; a <= 'Z';a++)
        if(num2[a] < 0 ) k+= num2[a];
    //out(k);
    //out(num2['_']);
    k = -k;
    if( k <= num2['_'] ) return true;
    return false;
}
int main() {
    while(scanf("%d",&n) && n )
    {
        if(n == 0 ) break;
        dic.clear();
        memset(num1,0,sizeof num1);
        memset(num1,0,sizeof num2);
        for(int i = 0;i < n;i ++)
        {
         scanf("%s",cs);
         s = cs;
         dic.push_back(s);
        }
        scanf("%s",cs); 
        s = cs;
        for(int i = 0;i < s.size();i ++)
         num1[s[i]] ++;
        //out(num1['_']);
        int ans = 0;
        for(int i = 0;i < dic.size();i ++)
         if( can(dic[i]) ) ans++;
        //cout<<ans<<endl;
        printf("%d\n",ans);
    }
    return 0;
}

