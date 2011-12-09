#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int mult(int p,int q){
if(q==0)return 1;
if(q==1)return p;
long long  tm=mult(p,q/2)%1000;
if(q%2)return (long long)tm*tm*p%1000;
else return (long long)tm*tm%1000;
}
main(){
while(1){
int a,b;
cin>>a>>b;
if(a==0&&b==0)break;
cout<<mult(a,b)%1000<<endl;

}
}
