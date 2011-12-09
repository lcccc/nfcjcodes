#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "string"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
using namespace std;

char s[1024], t[1024];

string reversecase(const string &q)
{
       string s = q;
       for (int i=0; i<s.size(); i++)
           if (s[i]>='A' && s[i]<='Z') s[i]+='a'-'A';
           else if (s[i]>='a' && s[i]<='z') s[i]+='A'-'a';
       return s;       
}


string removenumbers(const string &s)
{
 string ret;
 for (int i=0; i<s.size(); i++)
     if (s[i]<'0' || s[i]>'9') ret+=s[i];
 return ret;
}

int main()
{
    int N;
    int ncase = 0;
    scanf("%d", &N);
    while (N--)
    {
          scanf("%s%s",s,t);
          printf("Case %d: ", ++ncase);
          string q1=s, q2=t;
          if (q1==q2){printf("Login Successful.\n"); continue;}
          string q3 = reversecase(q2);
          string q4 = removenumbers(q1);
          if (q3==q4 && q2!=q3){
                         printf("Wrong password. Please, check your caps lock and num lock keys.\n"); continue;          
          }
          if (q1==q3) { 
                        printf("Wrong password. Please, check your caps lock key.\n"); continue;
          }

          if (q2==q4) { printf("Wrong password. Please, check your num lock key.\n"); continue;}

          printf("Wrong password.\n");
    }   
}

