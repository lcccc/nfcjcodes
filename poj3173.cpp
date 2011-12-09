/**************************************************
#		Author Nfcj000
#		Email: nfcjatwhu@gmail.com
#
#		Last modified: 2011-05-12 22:25
#
#		Filename:
#		Description:
**************************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int tran[30][30],n,s;
void creat_tran(int n,int s){
	for(int j=1;j<=n;j++)
		for(int i=1;i<=j;i++){
			tran[i][j]=s++;
			s%=10;
			if(s==0)s=1;
		}
}
int init(){
	cin>>n>>s;
	memset(tran,0,sizeof(tran));
}
int ouit(){
	for(int i=1;i<=n;i++){
	    for(int j=0;j<(i-1)*2;j++)cout<<' ';
		for(int j=i;j<=n;j++)
		cout<<tran[i][j]<<' ';
		cout<<endl;
	}
}
int main(int argc,char *argv[])
{	init();
	creat_tran(n,s);
	ouit();
	return 0;
}

