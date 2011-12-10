/*
	ID:lc757692
	LANG:C++
	TASK:shopping
	*/
#include <fstream>
#include <cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define ma 199405222
using namespace std;
struct re{
	long l[10];
	long da;
};
ifstream fin("shopping.in");
ofstream fout("shopping.out");
int main(int argc,char** argv){
	long f[8][8][8][8][8];
	long goal[8]={0};
	long x[2000]={0};
	re a[200];
	memset(a,0,sizeof(a));
	long m,n,p=0;
	fin >>m;
	for(long i=1;i<=m;i++){
		long temp;
		fin >>temp;
		for(long j=1;j<=temp;j++){
			long l1,l2;
			fin >>l1>>l2;
			if(x[l1]==0)x[l1]=++p;
			a[i].l[x[l1]]=l2;
		}
		fin >>a[i].da;
	}
	fin >>n;
	for(long i=1;i<=n;i++){
		long l1,l2;
		fin >>l1>>l2;
		if(x[l1]==0)x[l1]=++p;
		a[i+m].l[x[l1]]=1;
		goal[x[l1]]=l2;
		fin >>a[i+m].da;
	}
	for(long l1=0;l1<=goal[1]+1;l1++)
			for(long l2=0;l2<=goal[2]+1;l2++)
				for(long l3=0;l3<=goal[3]+1;l3++)
					for(long l4=0;l4<=goal[4]+1;l4++)
						for(long l5=0;l5<=goal[5]+1;l5++)
							f[l1][l2][l3][l4][l5]=ma;
	f[0][0][0][0][0]=0;
	for(long l1=0;l1<=goal[1];l1++)
			for(long l2=0;l2<=goal[2];l2++)
				for(long l3=0;l3<=goal[3];l3++)
					for(long l4=0;l4<=goal[4];l4++)
						for(long l5=0;l5<=goal[5];l5++){
							long mama=ma;
							for(long i=1;i<=n+m;i++)
								if(a[i].l[1]<=l1&&a[i].l[2]<=l2&&a[i].l[3]<=l3&&a[i].l[4]<=l4&&a[i].l[5]<=l5)
									mama=min(mama,f[l1-a[i].l[1]][l2-a[i].l[2]][l3-a[i].l[3]][l4-a[i].l[4]][l5-a[i].l[5]]+a[i].da);
							if(mama!=ma)
							f[l1][l2][l3][l4][l5]=mama;
							}
	fout <<f[goal[1]][goal[2]][goal[3]][goal[4]][goal[5]]<<endl;
	return 0;
}
