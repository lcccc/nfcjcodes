#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
void f(string ps,string ms){
 if(ps.length()>0){    
     if(ps.length()==1)
                        cout<<ps;
     else{
     char root=ps[0];   
     int pos=ms.find(root);
     //cout<<pos<<endl;
     f(ps.substr(0,pos),ms.substr(1,pos));
     f(ps.substr(pos+1),ms.substr(pos+1));
     cout<<root;
     }
     }
     }
     
main(){
       //ifstream cin("poj2255.in");
      // ofstream cout("poj2255.out");
       int a;
       string ps,ms,fs;
       while(cin>>ps>>ms){
                          f(ps,ms);
                          cout<<endl;
                          }
      
       }
