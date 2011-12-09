#include<stdio.h>
#include<math.h>


#define min(x,y) (x)>(y)?(y):(x)
const int maxn = 692;

int N,r,c;
int val[maxn][maxn];

//2D RMQ

int dp[maxn][maxn][10][10];
void RMQ_2D_PRE()
{
	for(int row = 0; row < r; row++) {
		for(int col = 0; col<c; col++) {			
			dp[row][col][0][0] = val[row][col];
		}
	}
	
	int m1 = log(double(r)) / log(2.0);	
    int m2 = log(double(c)) / log(2.0);	
	for(int i=0; i<=m1; i++) {	
		for(int j=0; j<=m2; j++) {	
			if(i == 0 && j==0)	continue;		
			for(int row = 0; row+(1<<i)-1 <= r; row++) {
				for(int col = 0; col+(1<<j)-1 <= c; col++){
					if(i == 0) {		
						dp[row][col][i][j] = min(dp[row][col][i][j-1] , dp[row][col+(1<<(j-1))][i][j-1]);
					} else {
						dp[row][col][i][j] = min(dp[row][col][i-1][j] , dp[row+(1<<(i-1))][col][i-1][j]); 
					}
				}
			}
			
		}
	}
	
}



int RMQ_2D(int x1,int x2,int y1,int y2)
{
	int kx = log(double(x2 - x1 +1)) / log(2.0);
	int ky = log(double(y2 - y1 +1)) / log(2.0);
	int m1 = dp[x1][y1][kx][ky];
	int m2 = dp[x2-(1<<kx)+1][y1][kx][ky];
	int m3 = dp[x1][y2-(1<<ky)+1][kx][ky];
	int m4 = dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
	return min( min(m1,m2), min(m3,m4) );
}


int main()
{
	int T;
	int M;
	int x1,y1,x2,y2;
	//scanf("%d",&T);
	while(1)	{
		scanf("%d%d%d",&r,&c,&M);
        if(r == 0 && c == 0 && M == 0) break;
		for(int i=0; i<r; i++) { 			
			for(int j=0; j<c; j++) {
				scanf("%d",&val[i][j]);
			}
		}		
		RMQ_2D_PRE();		
		while(M--)	{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d\n",RMQ_2D(x1,x2,y1,y2));		
		}		
	}
	
	return 0;	
}

