#include<stdio.h>
int f(int x,int n){
static int ans=1;

ans*=x;
return ans;
}
int main(){
int x,n;
scanf("%d%d",&x,&n);
for(int i=1;i<=n;i++)
    printf("%d ^ %d : %d\n",x,i,f(x,i));
return 0;
}
