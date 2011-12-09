#include <stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
typedef int Status;
typedef char elemtype;

typedef struct LNode{
	elemtype data;
	struct LNode* next;
}LNode,linklist;


void initlist(linklist *&L)
{
     L=(linklist *)malloc(sizeof(linklist));
     L->next=NULL;
}

void createlistR(linklist *&L,elemtype a[],int n)
{
     linklist *s,*r;
     int i;
     L=(linklist *)malloc(sizeof(linklist));
     r=L;
     for(i=0;i<n;i++)
     {
                     s=(linklist *)malloc(sizeof(linklist));
                     s->data=a[i];
                     r->next=s;
                     r=s;
                     }
     r->next=NULL;
}

int listempty(linklist *l)
{
     return(l->next==NULL);
     }

int listlength(linklist *L)
{
    linklist *p=L;
    int n=0;
    while(p->next!=NULL)
    {
                        n++;
                        p=p->next;
                        }
    return(n);
}

void displist(linklist *L)
{
     linklist *p=L->next;
     while(p!=NULL)
     {
                   printf("%c ",p->data);
                   p=p->next;
                   }
     printf("\n");
     }


int getelem(linklist *l,int i,elemtype &e)
{
    int j=0;
    linklist *p=l;
    while(j<i&&p!=NULL)
    {
                       j++;
                       p=p->next;
                       }
    if(p==NULL)
       return 0;
    else
    {
        e=p->data;
        return (e);
        }
}

int locateelem(linklist *L,elemtype e)
{
    linklist *p=L->next;
    int i=1;
    while (p!=NULL&&p->data!=e)
    {
          p=p->next;
          i++;
          }
    if(p==NULL)
       return(0);
    else
       return(i);
}

int listinsert(linklist *&L,int i,elemtype e)
{
    int j=0;
    linklist *p=L,*s;
    while (j<i-1&&p!=NULL)
    {
          j++;
          p=p->next;
          }
    if(p==NULL)
       return 0;
    else
    {
        s=(linklist *)malloc(sizeof(linklist));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return 1;
        }
}

int listdelete(linklist *&L,int i)
{
    int j=0;
    linklist *p=L,*q;
    while(j<i-1&&p!=NULL)
    {
                         j++;
                         p=p->next;
                         }
    if(p==NULL)
       return 0;
    else
    {
         q=p->next;
         if(q==NULL)
            return 0;

         p->next=q->next;
         free(q);
         return 1;
         }
}

int main()
{
    elemtype A[]={'a','b','c','d'};
    elemtype n=4,t,*z;
    linklist* h;
    initlist(h);
    createlistR(h,A,n);
    printf("输出h:");
    displist(h);
    printf("\n");
    printf("h length:%d\n",listlength(h));
    printf("if h empty?(0 for empty,1 for not):%d\n",listempty(h));
   // printf("the thirth:%d\n",getelem(h,3,t));
    getelem(h,3,t);
    printf("the thirth:%c\n",t);
    printf("'a' is located at %d",locateelem(h,'a'));
    listinsert(h,4,'f');
    printf("再次输出h:");
    displist(h);
    listdelete(h,3);
    printf("\n三次输出:");
    displist(h);
    free(h);
}
