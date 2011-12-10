#include<stdio.h>
#include<string.h>
const int MAX = 1010;

char result[MAX][22];
char s[MAX][22];

class TrieNode
{
public:
int value;
TrieNode *num[26];
TrieNode(void)
{
   value=-1;
   int i;
   for(i=0;i<26;i++)
    num[i] = NULL;
}
};

class Trie
{
public:
TrieNode *root;
Trie(void)
{
   root = new TrieNode;
}
void insert(char *str)
{
   TrieNode *p = root;
   int i,len = strlen(str);
   for(i=0;i<len;i++)
   {
    if(p->num[str[i]-'a'] == NULL)
    {
     p->num[str[i]-'a'] = new TrieNode;
     p = p->num[str[i]-'a'];
    }
    else
    {
     p = p->num[str[i]-'a'];
    }
    p->value++;
   }
}
char* check(char* str)
{
   TrieNode *p = root;
   int i;
   char result[60];
   for(i=0;str[i];i++)
   {
    if(p->value == 0)
    {
     result[i] = '\0';
     return result;
    }
    p = p->num[str[i]-'a'];
    result[i] = str[i];
   }
   result[i] = '\0';
   return result;
}
bool find(char* str)
{
    TrieNode *p = root;
    int i;
    for(int i = 0;str[i];i++)
    {
        if( p->num[str[i]-'a'] == NULL) return false;
        else p = p->num[str[i]-'a'];
    }
    return true;
}
};

int main(void)
{
}

