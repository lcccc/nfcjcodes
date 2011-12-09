/*
 * Author: lccccc 
 * Created Time:  2011/11/1 17:17:19
 * File Name: bbs.cpp
 */
#include <stdio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#define Lint long long 
#define MOD 1000000
Lint lcd(Lint a,Lint b)
{
    if( b== 0) return a;
    else return lcd(b,a%b);
}
Lint extgcd(int a,int b,int &x,int &y){
    if(!b) { x= 1;y = 0;return a;}
    int d = extgcd(b,a%b,x,y);
    int t = x;x = y;y = t-a/b*y;
    return d;
}
int mod(int p,int q)
{
    int s,t;
    extgcd(p,q,s,t);
    return s % t;
}
bool isPrime(Lint x)
{
    for(int i = 2;i <= sqrt(x) ;i ++)
        if(! x % i) return false;
    return true;
}
Lint getPrime()
{
    Lint prm = rand() % MOD;
    while(1){
        if( isPrime(prm) && prm % 4 == 3) return prm;
        prm = rand() % MOD;
    }
}
Lint getX0(Lint n)
{
    Lint x0 = rand() % MOD;
    while(lcd(n,x0) != 1) x0 = rand() % MOD;
    return x0;
}
Lint sqroot(Lint a,Lint p,Lint q)
{
    Lint ans[4] ;
    Lint n = p*q;

    ans[0] =( (Lint)(q* mod(q,p) * pow((double)a,double((p+1)/4)) ) % p +
             (Lint) (p* mod(p,q) * pow((double)a,double((q+1)/4)) ) % q) % n;
    ans[1] =((Lint)(q* mod(q,p) * pow((double)a,double((p+1)/4) )) % p -
             (Lint) (p* mod(p,q) * pow((double)a,double((q+1)/4)) ) % q) % n;;
    ans[2] =( (Lint)(-q* mod(q,p) * pow((double)a,double((p+1)/4)) ) % p +
             (Lint) (p* mod(p,q) * pow((double)a,double((q+1)/4)) ) % q) % n;;
    ans[3] =( (Lint)(-q* mod(q,p) * pow((double)a,double((p+1)/4)) ) % p -
             (Lint) (p* mod(p,q) * pow((double)a,double((q+1)/4)) ) % q) % n;;
    return ans[rand() % 4];
}
Lint bbs(int m){
    Lint p,q,n;
    Lint x[1000];
    p = getPrime();
    q = getPrime();
    while( p == q) q = getPrime();
    n = p * q;
    printf("n is %lld\n",n);
    x[0] = getX0(n);
    for(int i = 1;i <= m;i ++)
        x[i] = sqroot(x[i-1],p,q);
    Lint ans = 0;
    for(int i = 1;i <= m;i ++)
       ans = ans*10 + fabs(x[i] % 10); 
    return ans;
}
int main() {
    srand( time(0));
    int m;
    while(1){
        printf("\n\nplease input m ( len of int ),if m = 0,then break. \n");
        scanf("%d",&m);
        if( m == 0) break;
        printf("%lld\n",bbs(m));
    }
        return 0;
    }

