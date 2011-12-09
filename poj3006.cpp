#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[1000001];


void _init(){
     prime[0]=prime[1]=0;
     for(int i=2;i<=1000000;i++)prime[i]=1;
     for(int i=2;i<=1000000;i++){
             if(prime[i])
             for(int j=i*2;j<=1000000;j+=i)
             prime[j]=0;
             }
}
int main(){
    int a,d,n;
    _init();
   // printf("%d",prime[5]);
  while(1){
             scanf("%d%d%d",&a,&d,&n);
             int k=0,i;
             if(n==0&&a==0&&d==0)break;
             for(i=a;;i+=d){
                     if(prime[i])k++;
                     if(k==n)break;
             }
             printf("%d\n",i);
}
}

