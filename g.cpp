/*
<<<<<<< HEAD
 * Author: Nfcj
 * Created Time:  2011年07月24日 星期日 12时04分56秒
=======
 * Author: FreePascal
 * Created Time:  2011/9/18 13:17:39
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
 * File Name: g.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
<<<<<<< HEAD
using namespace std;
#define SZ(v) ((int)(v).size())

int main() {
    int n,ncc,ans;
    vector<int> f;
   while(cin>>n>>ncc){
    ans=ncc;
    f.clear();
    for(int i=0;i<n;i++)
    {
        int tm;
        cin>>tm;
        f.push_back(tm); 
    }
    sort(f.begin(),f.end());
    int tag[501];
    memset(tag,-1,sizeof tag);
    for(int i=0;i<f.size();i++)
        if(f[i]>ncc){ncc+=2;tag[i]=1;}
    for(int i=0;i<f.size();i++)
        if(tag[i]==-1){ ncc++;    
        }
    cout<<ncc<<endl;
   } 
    return 0;
}

=======
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

int main() {
    return 0;
}

{
	f = 0, s = 1;
	sum[1] = 1;
	for (int i=2; i<=100000; i++)	
	{
         	expect[i] = f + s * 0.5;
		    s = expect[i] ;
            f = 1 - expect[i];
            //cout<<s<<' '<<f<<' '<<endl;
            //getchar();
		    sum[i] = sum[i-1]+expect[i];
	}
	int N;
	while (scanf("%d", &N), N)
	{
             cout << sum[N] << endl;
	}
 
}

>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
