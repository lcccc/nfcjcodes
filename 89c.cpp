/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 15时27分16秒
 * File Name: 89c.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "functional"
using namespace std;
#define SZ(v) ((int)(v).size())
char prog[1048576*4];
char is[1048576*4];
int bracket[1048576*4];
int lenp;
int leni;

bool non_bf(const char &z) { return !strchr("><+-.,[]", z);}
int stack[1048576*4];

void findbracket()
{
    int top = 0;
    int i = 0;
    for (char *p=prog; *p; p++, i++)
        if (*p=='[')
            stack[++top]=i;
        else if (*p==']')
        {
            bracket[i] = stack[top]+1;
            bracket[stack[top]] = i+1;
            top--;   
        }
}
int array[30010];
void run()
{
    int inp = 0;
    char *pc = prog;
    char *end = prog+lenp;
    int *addr = array;
    memset(array, 0, sizeof(array));
    while (pc < end)
    {
        switch (*pc)
        {
            case '>': addr++;pc++;break;
            case '<': addr--;pc++;break;
            case '+': (*addr)++; pc++; break;
            case '-': (*addr)--; pc++; break;                      
            case '.': putchar(*addr); pc++;break;
            case ',': *addr = is[inp++]; pc++;break;
            case '[': if (!*addr) pc = prog+bracket[pc-prog] ;  else pc++;break;
            case ']': if (*addr)  pc = prog+bracket[pc-prog] ;  else pc++; break;
        }
    } 
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%[^$]$ ", prog);
        scanf("%[^$]$", is);
        lenp = remove_if(prog, prog+strlen(prog), non_bf)-prog;
        leni = strlen(is)-1;
        prog[lenp]=0;
        is[leni]=0;
        findbracket();
        static char dummy[100];
        gets(dummy);
        static int ncase = 0;
        printf("Case %d: ", ++ncase);
        run();
        printf("\n");
    }
    return 0;
}

