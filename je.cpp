#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int arr[4][4];
    int max = 0;
    int sum[4];
    for(int i = 0;i < 4;i ++)
        for(int j = 0;j < 4;j++)
            scanf("%d",&arr[i][j]);
    for(int i = 0;i < 4;i ++)
    {
        sum[i] = 0;
        for(int j = 0;j < 4;j ++)
            sum[i] += arr[j][i];
        if( sum[i] > max) max = sum[i];
    }
    printf("%d\n",max);
}
    
