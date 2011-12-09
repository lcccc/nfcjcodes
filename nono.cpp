#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a,b;
    char op;
    printf("请输入你要计算的式子，比如 12 + 13 = \n");
    scanf("%d %c %d =",&a,&op,&b);
    switch(op){
        case '+': printf("%d + %d = %d\n",a,b,a + b);break;
        case '-': printf("%d - %d = %d\n",a,b,a - b);break;
        case '*': printf("%d * %d = %d\n",a,b,a * b);break;
        case '/': printf("%d / %d = %d\n",a,b,a / b);break;
        case '%': printf("%d %% %d = %d\n",a,b,a % b);break;
        default:
                  printf("请正确输入等式！\n");
    }
    return 0;
}
