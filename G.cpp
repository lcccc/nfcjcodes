/*
 * Author:  mybestwishes
 * Created Time:  2011年07月31日 星期日 13时25分16秒
 * File Name: G.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
using namespace std;
#define N 3000
const int maxint = -1u>>1;

vector <string> rst ;
int main() {
    int T ;
//    freopen("out.txt" , "w" , stdout);
    cin>>T;
    getchar() ;
    for(int k = 0 ; k < T ; k++){
        char str[N] ;
        string s,s2 ; 
        while(true){
         //   gets(str) ;
           // cin>>str;
            getline(cin,s2);
            if( s2 == "###" ) break;
            s +=s2;
        }
        int len = s.length() ;
        string t ;
        //t.clear() ;
        int tag = 0 ; 
        for(int i = 0 ; i < len ; i++){
            if(s[0] > 'Z')
                s[0] -= 32 ;
            if(s[i] == '.' || s[i] == '!' || s[i] == '?')
                tag = 1 ;
            if(s[i] != ' ' && s[i] != ',' && s[i] != '.' && s[i] != '!' && s[i] != '?' && s[i] != '\t' && s[i] != '\n'){
                if(tag == 1){
                    if(s[i] > 'Z')
                        s[i] -= 32 ; 
                    tag = 0 ;
                }
            }
            if(s[i] != '-'){
                t = t + s[i] ;
            }
        }
        s.clear() ;
        s ==  s + t ;
        len = s.length() ;
//        t.clear() ;
        rst.clear();
        string tmp ;
        //tmp.clear() ;
//        int bz = 0 ;
        
        for(int i = 0 ; i < len ; i++){
            if(s[i] !=  ' ' && s[i] != ',' && s[i] != '.' && s[i] != '!' && s[i] != '?' && s[i] != '\t' && s[i] != '\n'){
                tmp = tmp + s[i] ;
//                t = t + s[i] ; 
//                bz = 0 ;
            }
            else{
                if(tmp.length() != 0){
                    rst.push_back(tmp) ;
                    tmp.clear();
                }
                
                if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t'){
                    tmp.clear() ; 
                    tmp = tmp + s[i] ;
                    rst.push_back(tmp) ;
                    tmp.clear() ;
                }
                
                /*
                if(s[i] == ' '){
                    if(bz == 0 && s[i+1] !=  ' ' && s[i+1] != ',' && s[i+1] != '.' && s[i+1] != '!' && s[i+1] != '?'){
                        t = t + s[i] ;
                    }
                    continue ;
                }
                else{
                    if(s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '?'){
                        bz = 1  ;
                        t = t + s[i] ;
                        t = t + ' ' ;
                    }
                    else{
                        bz = 0 ;
                        t = t + s[i] ;
                    }
                }
                */
                
            }
        }
//        t = t + s[len-1] ;
//        cout<<t<<endl;
        
        len = rst.size() ;
        int cnt = 0 ;
        for(int i = 0 ; i < len ; i++){
            if(rst[i] == "," || rst[i] == "." || rst[i] == "?" || rst[i] == "!"){
                if(cnt+1 <= 80){
                    cout<<rst[i];
                    cnt++ ;
                }
                else{
                    cout<<endl;
                    cout<<rst[i];
                    cnt = rst[i].length() ;
                }
            }
            else{
                int le = rst[i].length() ;
                if(le+cnt+1 <= 80){
                    if(cnt > 0)
                        cout<<" ";
                    cout<<rst[i] ;
                    cnt = cnt+le+1 ;
                }
                else{
                    cout<<endl;
                    cout<<rst[i] ;
                    cnt = le ;
                }
            }
        }
        cout<<endl;
        if(k != T-1)
            printf("\n");
    }
    return 0;
}

