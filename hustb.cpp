#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int f[101][101];
//0 white
//1 black
void white(int x,int y,int l){
for(int i=x;i<x+l;i++)
    for(int j=y;j<y+l;j++)
    f[i][j]=0;
}
void black(int x,int y,int l){
for(int i=x;i<x+l;i++)
    for(int j=y;j<y+l;j++)
    f[i][j]=1;
}
int test(int x,int y,int l)
{

    int ans=0;
    for(int i=x;i<x+l;i++)
    for(int j=y;j<y+l;j++)
    if(f[i][j])ans++;
    return ans;
}
main(){
    int t;
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
        f[i][j]=0;
    cin>>t;
    string s;
    int x,y,l;
    for(int i=0;i<t;i++){
    cin>>s>>x>>y>>l;
    if(s=="BLACK")black(x,y,l);
    if(s=="WHITE")white(x,y,l);
    if(s=="TEST")cout<<test(x,y,l)<<endl;
    }
}
