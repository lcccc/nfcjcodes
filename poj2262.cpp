#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[1000001];
int ispm(int x){
    for(int i=2;i<=(int)sqrt(x);i++)
            if(x%i==0)return 0;
    return 1;
}

void _init(){
     for(int i=0;i<=1000001;i++)prime[i]=1;
     for(int i=2;i<=1000000;i++){
             if(prime[i])
             for(int j=i*2;j<=1000000;j+=i)
             prime[j]=0;
             }
}
int main(){
    int n;
    _init();
   // printf("%d",prime[5]);
    while(1){
             scanf("%d",&n);
             if(n==0)break;
             int a,b;
             for(a=3;a<=(n+1)/2;a+=2)
             if(prime[a]&&prime[n-a]&&a%2&&(n-a)%2){
             printf("%d = %d + %d\n",n,a,n-a);
             break;
             }
}
}
