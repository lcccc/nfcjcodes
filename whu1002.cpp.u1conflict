#include<algorithm>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
//ofstream fout("output.txt");
int numword(string s){

    int num=0;
    int b_word=0;
    int pos=0;
    while(pos<=s.size()){
        if(b_word)
            {
                if(s[pos]<'A'||s[pos]>'z')
                {
                    b_word=0;
                    num++;
      //              fout<<"pos "<<s[pos]<<' '<<pos<<" b_word "<<b_word<<" num "<<num<<endl;;
                }
            }
        else {
            if((s[pos]<='Z'&&s[pos]>='A')||(s[pos]<='z'&&s[pos]>='a'))
            {
                b_word=1;
            }
        }
      //  fout<<s[pos]<<endl;
        pos++;

    }
    return num;
    //return count(s.begin(),s.end(),' ');
    }
main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    string s;
    while(getline(cin,s)){
      //  cout<<s.substr(0,s.find(' '))<<' '<<numword(s)<<endl;
    cout<<"cout<<\""<<s.substr(0,s.find(' '))<<' '<<numword(s)<<"\"<<endl;"<<endl;
    }
}
