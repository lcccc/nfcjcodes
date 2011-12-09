#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int numlist[106];
int main()
{
    int i;
    double sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&numlist[i]);
        sort(numlist,numlist+n);
        sum=0;
        for(i=1;i<n-1;i++)
            sum+=numlist[i];
        sum/=n-2;
        printf("%.2lf\n",sum);
    }
    return 0;
}


