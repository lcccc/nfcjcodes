#include <iostream>            //poj 3264 线段树,求区间的最值问题
using namespace std;
struct segment
{
    int max,min;
}table[200000];
int arr[50005],MAX,MIN;
void built_tree(int s,int t,int n)
{
    if(s==t)
        table[n].max=table[n].min=arr[s];
    else
    {
        int mid=(s+t)/2;
        built_tree(s,mid,2*n);
        built_tree(mid+1,t,2*n+1);
        table[n].max=max(table[2*n].max,table[2*n+1].max);
        table[n].min=min(table[2*n].min,table[2*n+1].min);
    }
}
void range(int s,int t,int n,int head,int end)
{
    if(s==head&&t==end)
    {
        MAX=max(MAX,table[n].max);
        MIN=min(MIN,table[n].min);
    }
    else
    {
        int mid=(head+end)/2;        //注意不要写成 int mid=(s+t)/2;
        if(s<=mid)        
            range(s,min(mid,t),2*n,head,mid);
        if(t>mid)
            range(max(s,mid+1),t,2*n+1,mid+1,end);
//这里不用也不能再添加        MAX=max(table[2*n].max,table[2*n+1].max);    MIN=min(table[2*n].min,table[2*n+1].min);
//因为执行range(s,min(mid,t),2*n,head,mid);之后,MAX已经是MAX=max(MAX,table[2*n].max);
//同理再执行range(max(s,mid+1),t,2*n+1,mid+1,end); MAX已经是table[2*n].max,table[2*n+1].max 两者的最大值了
    }
}
int main()
{
    int n,q,s,t;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)    //下标从1开始
        scanf("%d",arr+i);
    built_tree(1,n,1);
    while(q--)
    {
        scanf("%d%d",&s,&t);
        MAX=0;MIN=1000001;
        range(s,t,1,1,n);
        printf("%d\n",MAX-MIN);
    }
    return 0;
}

