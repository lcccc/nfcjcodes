#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[1000];
    gets(s);
    char tm = s[strlen(s) - 1];
    for(int i = strlen(s) -1;i > 0;i --)
        s[i]  = s[i-1];
    s[0] = tm;
    puts(s);
}
