/*
ID:     lc757692
PROG:	preface
LANG:	C++
*/
#include <iostream>
#include <cstdio>
using namespace std;
int res[7];
int a[10][7],b[10][7],c[10][7],d[10][7];//个位，十位，百位，千位。 	
int main(){
	/*
	1~9
	10~90
	100~900
	1000~3000*/
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	a[1][0] = a[6][0] = 1;a[2][0] =a[7][0] = 2;a[3][0] =a[8][0] = 3; a[4][0] =a[9][0] = 1;
	for(int i = 4; i <= 8; i++) a[i][1] = 1; a[9][2]=1;
	b[1][2] = b[6][2] = 1;b[2][2] =b[7][2] = 2;b[3][2] =b[8][2] = 3; b[4][2] =b[9][2] = 1;
	for(int i = 4; i <= 8; i++) b[i][3] = 1; b[9][4]=1;
	c[1][4] = c[6][4] = 1;c[2][4] =c[7][4] = 2;c[3][4] =c[8][4] = 3; c[4][4] =c[9][4] = 1;
	for(int i = 4; i <= 8; i++) c[i][5] = 1; c[9][6]=1;
	d[1][6]=1;d[2][6]=2;d[3][6]=3;
	int N;
	cin>>N;
	for(int t = 1; t <= N; t++){
		int n = t;
		if(n/1000!=0){ 
			int tmp = n/1000;
			for(int i = 0; i <=6; i++)
			res[i]+=d[tmp][i];
		}
		n=n%1000;
		if(n/100!=0){
			int tmp = n/100;
			for(int i = 0; i <= 6; i++)
				res[i] += c[tmp][i];	
		}
		n = n%100;
		if(n/10!=0){
			int tmp = n/10;
			for(int i = 0; i <= 6; i++)
				res[i] += b[tmp][i];	
		}
		n = n%10;
		if(n!=0){
			int tmp = n/1;
			for(int i = 0; i <= 6; i++)
				res[i] += a[tmp][i];	
		}
	}
	for(int i = 0; i <= 6; i++)
		switch(i){
			case 0: if(res[i]!=0) cout<<"I"<<" "<<res[i]<<endl;break;
			case 1: if(res[i]!=0) cout<<"V"<<" "<<res[i]<<endl;break;
			case 2: if(res[i]!=0) cout<<"X"<<" "<<res[i]<<endl;break;
			case 3: if(res[i]!=0) cout<<"L"<<" "<<res[i]<<endl;break;
			case 4: if(res[i]!=0) cout<<"C"<<" "<<res[i]<<endl;break;
			case 5: if(res[i]!=0) cout<<"D"<<" "<<res[i]<<endl;break;
			case 6: if(res[i]!=0) cout<<"M"<<" "<<res[i]<<endl;break;	
		}
}
