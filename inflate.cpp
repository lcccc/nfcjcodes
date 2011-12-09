/*
	ID:lc757692
	LANG:C++
	TASK:inflate
	*/
#include <fstream>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main(int argc,char** argv){
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");
	long f[10003]={0};
	long m,n;
	fin >>m>>n;
	for(long i=1;i<=n;i++){
		long u=0,v=0;
		fin >>v>>u;
		for(long j=u;j<=m;j++)
			f[j]=max(f[j],f[j-u]+v);
	}
	fout <<f[m]<<endl;
	fin.close();fout.close();
	return 0;
}
