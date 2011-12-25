#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
int m,n;
while(cin>>n>>m)
{
char map[105][105];
for(int i = 0;i < 105;i++)
	for(int j = 0;j < 105;j ++)
	map[i][j] = '.';
int px = 0,py = 0;
char ch;
for(int i = 0;i < n;i ++)
{
py  = 0;
	for(int j = 0;j < m ;j ++)
	{
		//cout<<i<<' '<<j<<endl;	
		cin>>ch;
		//cout<<"ch "<<ch<<endl;
		if('.'!=ch) map[i][py++] = ch;
}
}
//cout<<"pt"<<endl;
for(int i = 0;i < n;i ++)
	{
	for(int j = 0;j < m;j ++)
	printf("%c",map[i][j]);
	printf("\n");
}
printf("\n");
} 
return 0;
}
