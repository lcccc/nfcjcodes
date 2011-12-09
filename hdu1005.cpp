#include<iostream>
#include<stdio.h>
using namespace std;
main(){
int a,b,n;
while(1){
//cin>>a>>b>>n;
scanf("%d%d%d",&a,&b,&n);
if(a==0&&b==0&&n==0)break;
int f[1000];
f[1]=1;
f[2]=1;
for(int i=3;i<=1000;i++){
f[i]=(a*f[i-1]+b*f[i-2])%7;
//cout<<f[i]<<' ';
}
int k=10000000;
for(int i=3;i<=1000;i++){
if(f[i]==f[1] && f[i+1] == f[2] ){
k=i-1;
break;
}
}
//printf("%d\n",k);
printf("%d\n",f[n%k]);

}
}
