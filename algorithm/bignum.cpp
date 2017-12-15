#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

struct bint{
	long long a[300];
	int n;
	bint(int b=0)
	{
		memset(a,0,sizeof a);
		a[0]=b;
		n=0;
		mem();
	}
	void mem()
	{
		int c=0;
		while(c<=290){
			a[c+1]+=a[c]/10;
			a[c]%=10;
			c++;
		}
		n=295;
		while(a[n]==0){
			n--;
		}
		n++;
	}
	void COUT()
	{
		for(int i=n-1;i>=0;i--){
			cout<<a[i];
		}
	}
	
};

bint operator * (bint a,bint b){
	bint x(0);
	x.n=a.n+b.n;
	for(int i=0;i<a.n;i++){
		for(int j=0;j<b.n;j++){
			x.a[i+j]+=a.a[i]*b.a[j];
		}
		x.mem();
	}
	while(x.a[x.n]==0){
		x.n--;
	}
	x.n++;
	return x;
}

bint operator - (bint a,bint b){
	bint x(0);
	x.n=max(a.n,b.n);
	for(int i=0;i<max(a.n,b.n);i++){
		x.a[i]=a.a[i]-b.a[i];
		if(x.a[i]<0){
			x.a[i]+=10;
			a.a[i+1]-=1;
		}
	}
	x.n=290;
	while(x.a[x.n]==0){
		x.n--;
	}
	x.n++;
	return x;
}

bool cheak(bint a,bint b){
	for(int i=290;i>=0;i--)if(a.a[i]!=b.a[i]){
		if(a.a[i]>b.a[i]){
			return 1;
		}
		return 0;
	}
	return 1;
}

int main(){
	int x,y;
	cin>>x>>y;
	if(x==y){
		cout<<0<<endl;
		return 0;
	}
	bint a(x),b(y),aa(x),bb(y);
	for(int i=1;i<x;i++){
		b=b*bb;
	}
	for(int i=1;i<y;i++){
		a=a*aa;
	}
	bool c=cheak(a,b);
	if(c){
		a=a-b;
	}else{
		a=b-a;
	}
	if(c==0){
		cout<<"-";
	}
	a.COUT();
}

