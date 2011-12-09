#include<iostream>
#include<algorithm>
using namespace std;
long long a[300],b[70000];
int tag[80000];

int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF){
                  if(n == 0) break;
                  m = n*(n+1)/2;
                  memset(tag,0,sizeof tag);
                  for(int i = 0 ;i < m;i++)
                  {
                          scanf("%lld",&(b[i]));
                          tag[b[i]] = 1;
                          }
                  int g1 = 0;
                  for(int i = 0;i <m;i++)
                        if( b[i] % 2 == 0) g1 = __gcd(g1,b[i]);
                  //cout<<"gcd "<<g1<<endl;
                  int tot = 1;
                  for(int i = 2;i <= g1;i++)
                      if( g1 % i == 0)
                        {
                            tot = 1;
                            a[0] = i;
                            //cout<<"a0 = "<<i<<endl;
                            for(int j = 0;j < m;j++)
                            if( b[j]%2 == 0 ) a[tot++] = b[j] / i;
                                int bok = 1;
                                for(int i1 = 0;i1 <= n;i1++)
                                {
                                     for(int j1 = i1+1;j1<= n;j1++)
                                        if(tag[a[i1]*a[j1]] == 0) 
                                         { 
                                             //cout<<i1<<' '<<j1<<endl;
                                             bok = 0;
                                             break;
                                         }
                                     if(bok == 0) break;
                                }
                                         if(bok)
                             {
                                   printf("%d\n",a[0]);
                                    sort(a+1,a+n);
                                    for(int i = 1;i <= n;i++)
                                    {
                                        if(i!=1) printf(" ");
                                        printf("%d",a[i]);
                                    }
                                    break;
                                    }
                                    }
    }
return 0;
}
