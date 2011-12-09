/*
ID:lc757692
LANG:C++
PROB:camelot
*/
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
using namespace std;
const int move[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int map [35][35][35][35];
int x,y,nk;
struct {int x;int y;} king;
struct {int x;int y;} knight[35*35];
struct {int x,y;} lie[35*35*2]; 
int ans;
int stdpoi[35][35];
 
void Cib(){
	cin>>y>>x;
	char temp;
	cin>>temp; king.x=temp-'A';
	cin>>king.y; king.y--;
 
	nk=0; memset(knight,0,sizeof(knight));
	while (cin>>temp>>knight[nk].y){
		knight[nk].x=temp-'A'; knight[nk].y--;
		nk++;		
	}
}
 
int max(int a,int b){
	return a>b?a:b;
}
 
int min(int a,int b){
	return max(0,a>b?b:a);
}
 
bool judge(int i,int j){
	if (i>=x || j>=y || i<0 || j<0) return false ;
	else return true;
}
 
void Map_cib(){
 
	memset(map,-1,sizeof(map));
	for (int i=0;i<x;i++) 
		for (int j=0;j<y;j++){
		map[i][j][i][j]=0;
 
		for (int syz=0;syz<35*35*2;syz++) {lie[syz].x=0; lie[syz].y=0;}
		int l=0,r=0; lie[l].x=i; lie[l].y=j;
 
		while (l<=r){
			for (int k=0;k<8;k++) {
				if (map[i][j][lie[l].x+move[k][0]][lie[l].y+move[k][1]]==-1 && judge(lie[l].x+move[k][0],lie[l].y+move[k][1]) ){
					map[i][j][lie[l].x+move[k][0]][lie[l].y+move[k][1]]=map[i][j][lie[l].x][lie[l].y]+1;
					r++;
					lie[r].x=lie[l].x+move[k][0];
					lie[r].y=lie[l].y+move[k][1];
				}
			}
			++l;
		}
	}
}
 
 
 
void Enum(){
	ans=INT_MAX;
	for (int i=0;i<x;i++)
		for (int j=0;j<y;j++)
			for (int ii=0;ii<x;ii++)
				for (int jj=0;jj<y;jj++) if (map[i][j][ii][jj]==-1) map[i][j][ii][jj]=10000;
	memset(stdpoi,0,sizeof(stdpoi));
	for (int i=0;i<x;i++) for (int j=0;j<y;j++) {
		int ts=0;
		for (int n=0;n<nk;n++) ts+=map[knight[n].x][knight[n].y][i][j];
		stdpoi[i][j]=ts;
		ts+=max(abs(king.x-i),abs(king.y-j));
		if (ans>ts) ans=ts;
	}
 
	for (int i=max(king.x-5,0);i<=min(king.x+5,x-1);i++) 
		for (int j=max(king.y-5,0);j<=min(king.y+5,y-1);j++)
			for (int n=0;n<nk;n++) 
				for (int ei=0;ei<x;ei++) 
					for (int ej=0;ej<y;ej++) {
						int ts=stdpoi[ei][ej]-map[knight[n].x][knight[n].y][ei][ej]+max(abs(king.x-i),abs(king.y-j))+map[ei][ej][i][j]+map[knight[n].x][knight[n].y][i][j];
						if (ts<ans) ans=ts;
					}
	cout <<ans<<endl;
}
int main(){
 
	freopen ("camelot.in","r",stdin);
	freopen ("camelot.out","w",stdout);
	Cib();
	Map_cib();
	Enum();
}
