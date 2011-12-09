#include <iostream>            //poj 3264 �߶���,���������ֵ����
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
        int mid=(head+end)/2;        //ע�ⲻҪд�� int mid=(s+t)/2;
        if(s<=mid)        
            range(s,min(mid,t),2*n,head,mid);
        if(t>mid)
            range(max(s,mid+1),t,2*n+1,mid+1,end);
//���ﲻ��Ҳ���������        MAX=max(table[2*n].max,table[2*n+1].max);    MIN=min(table[2*n].min,table[2*n+1].min);
//��Ϊִ��range(s,min(mid,t),2*n,head,mid);֮��,MAX�Ѿ���MAX=max(MAX,table[2*n].max);
//ͬ����ִ��range(max(s,mid+1),t,2*n+1,mid+1,end); MAX�Ѿ���table[2*n].max,table[2*n+1].max ���ߵ����ֵ��
    }
}
int main()
{
    int n,q,s,t;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)    //�±��1��ʼ
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

