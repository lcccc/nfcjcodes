/*
ID: lc757692
TASK: cowtour
LANG: C++
*/
#include <iostream>
#include <math.h>
#include <memory.h>
#include <stdio.h>
using namespace std;
#define _max_node_ 150
int n_node, x[_max_node_], y[_max_node_] ;
double map[_max_node_][_max_node_] ;
char conn[_max_node_][_max_node_+1] ;
 
inline double dis( int i, int j ){
	return sqrt( ((double)(x[i]-x[j]))*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) );
}
 
int grps[_max_node_][_max_node_], grp_size[_max_node_], n_grp=0, grp_id[_max_node_] ;
void get_group(int node ) {
	int stk[_max_node_], *top=stk, vis[_max_node_] ;
	memset( vis, 0, sizeof(int)*n_node );
	grp_size[n_grp]=0, grps[n_grp][grp_size[n_grp]++]=node, grp_id[node]=n_grp;
	*(top++)=node, vis[node]=1 ;
	do{
		register int cn=*(--top);
		for( int i=0; i<n_node; i++ )
			if( conn[cn][i]=='1' && !vis[i] )
				*(top++)=i , vis[i]=1, grps[n_grp][ grp_size[n_grp]++ ]=i, grp_id[i]=n_grp ;
	}while(top!=stk);
	n_grp++ ;
}
 
double longest[_max_node_], grp_dim[_max_node_] ;
void get_grp_dim( int grp_id ) {
	register int m_size=grp_size[grp_id] ;
	for( int k=0; k<m_size; k++ ){
		register int kid=grps[grp_id][k];
		for( int i=0; i<m_size; i++ ) {
			register int iid=grps[grp_id][i];
			if( map[iid][kid]<0 )
				continue ;
			for( int j=0; j<m_size; j++) {
				register int jid=grps[grp_id][j];
				if( map[kid][jid]<0 )
					continue ;
				if( map[iid][jid]<0 || map[iid][kid] + map[kid][jid] < map[iid][jid] )
					map[iid][jid] = map[iid][kid] + map[kid][jid];
			}
		}
	}
	double dim=-1;
	for( int i=0; i<m_size; i++ ) {
		double cur_max=0 ;
		for( int j=0; j<m_size; j++ )
			if( i!=j )
				cur_max = max( cur_max, map[grps[grp_id][i]][grps[grp_id][j]] ) ;
		longest[grps[grp_id][i]] = cur_max ;
		dim = max( dim, cur_max ) ;
	}
	for( int i=0; i<m_size; i++ ) 
		grp_dim[grps[grp_id][i]] = dim ;
}
 
int main() {
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	cin >> n_node ;
	for( int i=0; i<n_node; i++ )
		cin >> x[i] >> y[i] ;
	for( int i=0; i<n_node; i++ )
		cin >> conn[i] ;
	for( int i=0; i<n_node; i++ )
		for( int j=i; j<n_node; j++ )
			map[i][j] = map[j][i] = conn[i][j]=='1' ?  dis(i,j): -1;
 
	memset( grp_id, 0xff, sizeof(grp_id) );
	for( int i=0; i<n_node; i++ )
		if( grp_id[i]==-1 )
			get_group(i);
	for( int i=0; i<n_grp; i++ )
		get_grp_dim( i );
 
	double min_dim=-1;
	for( int i=0; i<n_node; i++ )
		for( int j=i+1; j<n_node; j++ ){
			if( grp_id[i]==grp_id[j] ) 
				continue ;
			double cur_dim = max( dis(i,j)+longest[i]+longest[j] , max( grp_dim[i], grp_dim[j] ) );
			min_dim = min_dim==-1 || cur_dim<min_dim ? cur_dim : min_dim ;
		}
	printf("%.6lf\n", min_dim);		
 
	return 0;
}
