/*
ID:lc757692
TASK:ariprog
LANG:C++
*/
/*
 * Author: Nfcj
 * Created Time:  2011年07月15日 星期五 11时35分44秒
 * File Name: ariprog.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())

int s[125001],n,m;
int init(){
    ifstream cin("ariprog.in");
    cin>>n>>m;
    memset(s,0,sizeof(s));
    for(int i = 0;i<=m;i++)
        for(int j = 0 ; j <=m;j++)
            s[i*i+j*j]=1;
    return 0;    
}
int isOk(int a,int b)
{
    int B=1;
    for(int i=0;i<n;i++){
        if((s[a+i*b]==0)){
            B=0;
            break;
        }
    }
    return B;
}
int _main(){
    ofstream cout("ariprog.out");
    int bans=0;
    for(int b=1;b<=m*m;b++)
        for(int a=0;a<=m*m;a++)
        {
            if((a+(n-1)*b)>2*m*m)break;
            if(isOk(a,b)){
                bans=1;
                cout<<a<<' '<<b<<endl;
            }
        }
    if(bans!=1)cout<<"NONE"<<endl;
}
int main() {
    init();
    _main();
    return 0;
}

