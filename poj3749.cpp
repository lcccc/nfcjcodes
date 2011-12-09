#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
main(){
       string mm="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z M ";
       string yw="V W X Y Z A B C D E F G H I J K L M N O P Q R S T U ";
       string s;
       while(getline(cin,s)){
                             getline(cin,s);
                             if(s=="ENDOFINPUT")break;
                             for(int i=0;i<s.size();i++)
                                     if(s[i]>='A'&&s[i]<='Z')
                                     cout<<yw[mm.find(s[i])];
                                     else cout<<s[i];
                             cout<<endl;
                             getline(cin,s);
                             }
       return 0;
       }
