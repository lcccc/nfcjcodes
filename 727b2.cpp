#include<iostream>
#include<stdio.h>
using namespace std;
int a[100001],c[100001];
int n,m;
int lowbit(int k)
{
    return k&(k^(k-1));
    }
void plusx(int x,int num)
{
    while(x<=n)
    {
          c[x]+=num;
          x+=lowbit(x);     
          } 
    }    
int Sum(int x)
{
    int sum=0;
    while(x>0)
    {
          sum+=c[x];
          x-=lowbit(x);    
          }
    return sum;      
    }
int find(int x)
{
    int left=1,right=n,mid;
    while(left<right)
    {
          mid=(left+right)>>1;
          if(Sum(mid)>=x)right=mid; 
          else left=mid+1;         
          }
    return right;    
    }        
int main()
{
    int i,j,k,x,y;
    char b[100];
    while(scanf("%d",&n)!=EOF)
    {
          for(i=0;i<=n;i++)c[i]=0;
          for(i=1;i<=n;i++)
          {
              scanf("%d",&a[i]);
              plusx(i,a[i]);
              }
          scanf("%d",&m);
          while(m--)
          {
                scanf("%s",b);
                if(b[0]=='q')
                {
                   scanf("%d",&x);
                   printf("%d\n",find(x));          
                   }    
                else 
                {
                   scanf("%d%d",&x,&y);
                   plusx(x,-a[x]);
                   a[x]=y;
                   plusx(x,a[x]); 
                   }   
                }                          
          }
    return 0;
    } 
