#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N=100+10;

vector <int> G[MAX_N];
int c[MAX_N][MAX_N];
int f[MAX_N][MAX_N];
int h[MAX_N];
int ex[MAX_N];
int lis[MAX_N];
int n,m,s,t;
int cz=0;
int sum=0;
int I;

void P(int u,int v){
	int fl=min(ex[u],c[u][v]-f[u][v]);
	ex[u]-=fl;
	ex[v]+=fl;
	f[u][v]+=fl;
	f[v][u]-=fl;
	if(v==s || v==t){
		sum-=fl;
	}
}

void R(int u){
	int H=1000000000;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(f[u][v]<c[u][v]){
			if(h[v]>=h[u]){
				H=min(H,h[v]);
			}
		}
	}
	if(H!=1000000000){
		h[u]=H+1;
	}
}

void CH(int ind){
	for(int i=ind ;i>0;i--){
		swap(lis[i],lis[i-1]);
	}
}

void F(int u){
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(( (h[v]<h[u]) && (c[u][v]>f[u][v]) ) && ex[u]){
			P(u,v);
		}
	}
	if(ex[u]){
		R(u);
		CH(I);
		I=0;
	}else{
		I++;
	}
}


int main(){
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		c[x][y]=w;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=0;i<G[s].size();i++){
		ex[G[s][i]]=c[s][G[s][i]];
		sum+=c[s][G[s][i]];
	}
	for(int i=1;i<=n;i++)if(i!=s && i!=t){
		lis[cz]=i;
		cz++;
	}
	while(sum){
		I=0;
		for(;I<cz;){
			F(lis[I]);
		}
	}
	cout<<ex[t]<<endl;
}

