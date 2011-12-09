#include<stdio.h>
using namespace std;
int n;
int main()
{
    int sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=1;n--;
        while(n--)
            sum=2*sum+2;
        printf("%d\n",sum);
    }
    return 0;
}
