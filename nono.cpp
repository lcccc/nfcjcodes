#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a,b;
    char op;
    printf("��������Ҫ�����ʽ�ӣ����� 12 + 13 = \n");
    scanf("%d %c %d =",&a,&op,&b);
    switch(op){
        case '+': printf("%d + %d = %d\n",a,b,a + b);break;
        case '-': printf("%d - %d = %d\n",a,b,a - b);break;
        case '*': printf("%d * %d = %d\n",a,b,a * b);break;
        case '/': printf("%d / %d = %d\n",a,b,a / b);break;
        case '%': printf("%d %% %d = %d\n",a,b,a % b);break;
        default:
                  printf("����ȷ�����ʽ��\n");
    }
    return 0;
}
