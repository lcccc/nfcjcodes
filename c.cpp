#include<iostream>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<vector>
using namespace std;

int map[9][9];
int n;


void fresh(){
<<<<<<< HEAD
    /*
=======
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
     for(int x = 1;x <= 7;x ++)
             {
                 for(int y = 1;y <= 7; y++)
                 if(map[x][y] == -1)
                              swap(map[x][y],map[x][y+1]);
                              }
<<<<<<< HEAD
                              */
    for(int x = 1; x <= 7;x ++)
    {
        for(int y = 1;y <= 7 ;y ++)
            if(map[x][y] == -1)
            {
                int y2;
                for(y2 = y+1;y2 <= 7;y2++)
                    if(map[x][y2] != -1)
                        break;
                
}
=======
                              }
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
bool fall(int i,int x){
     int j=1;
     while(map[x][j] != -1) j++;
     if(j>7) return false;
     map[x][j] = i;
     return true;
     }
int sizex(int x,int y){
    int tx = x,ty = y,ans=0;
    if( map[x][y]==-1 )return 0;
    while(map[tx][y] !=-1 && tx<=7) tx++;
    ans += tx - x;
    tx = x;
    while(map[tx][y] !=-1 && tx>=1) tx--;
    ans += x - tx;
<<<<<<< HEAD
    ans--;
=======
    ans++;
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
    return ans;
}

int sizey(int x,int y){
    int tx = x,ty = y,ans =0;
    if(map[x][y] == -1 ) return 0;
    while( map[tx][ty] != -1 && ty<=7) ty++;
    ans += ty -y;
    ty = y;
    while( map[tx][ty] != -1 && ty>=1) ty--;
    ans += y - ty;
<<<<<<< HEAD
    ans--;
=======
    ans++;
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
    return ans;
}
void update(){
     vector<pair<int,int> > qc;
     int b = 1;
     while(b){
              qc.clear();
     for(int x=1;x <= 7;x++)
             for(int y=1;y<=7;y++)
             if( sizex(x,y)== map[x][y] || sizey(x,y) == map[x][y])
                 qc.push_back( pair<int,int>(x,y));
     if(qc.size() == 0) b = 0;
     for(int i=0;i<qc.size();i++)
             map[qc[i].first][qc[i].second] = -1;
     fresh();
     }
<<<<<<< HEAD
     }
=======
     }    
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
void print(){
     for(int y = 7;y >= 1;y--)
             {
                 for(int x=1; x<= 7;x++)
                         if(map[x][y] == -1) printf("#");
                         else printf("%d",map[x][y]);
                 printf("\n");
                 }
<<<<<<< HEAD
     printf("\n");
}
main(){
      while(1)
      {
          scanf("%d",&n);
          if(n == 0)break;
=======
                 }
main(){
      while(cin>>n)
      {
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
                   int bover = 0;
                   memset(map,-1,sizeof map);
                   for(int k = 0;k < n;k++)
                   {
                           int i,x;
<<<<<<< HEAD
                        //   cin>>i>>x;
                           scanf("%d%d",&i,&x);
                           if(bover == 0){
                           if(!fall(i,x))
                           {
                                          printf("Game Over!\n\n");
                                          bover = 1;
                                     //     continue;
                                          }
                           update();
                           print();
                      //     printf("\n");
=======
                           cin>>i>>x;
                           if(bover ==0){
                           if(!fall(i,x)) 
                           {
                                          printf("Game Over!\n");
                                          bover = 1;
                                          continue;
                                          }
                           update();
                           print();
                           printf("\n");
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
                           }
                           }
                   if(bover == 0)
                            print(); 
                            }
                            }        
