/*
ID: dhm_blo2
PROG: runround
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
typedef long long ll;
ifstream fin("runround.in");
ofstream fout("runround.out");
bool standard(ll n){
	ll tmp=n;
	bool seen[10];
	for(int i=0;i<10;i++)
		seen[i]=0;
	while(tmp>0){
		if(seen[tmp%10])
			return 0;
		if(tmp%10==0)
			return 0;
		seen[tmp%10]=1;
		tmp/=10;
	}
	return 1;
}
bool runround(ll n){
	ll tmp=n;
	bool seen[10];
	for(int i=0;i<10;i++)
		seen[i]=0;
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=0;
	int lg=0;
	while(tm>0){
		lg++;
		tmp/=10;
	}
	tmp=n;
	int index=lg-1;
	while(index>-1){
		a[index]=tmp%10;
		tmp/=10;
		index--;
	}
	int cur=a[0];
	cur%=lg;
	for(int i=0;i<lg;i++){
		//cout<<cur<<endl;
		if(seen[a[cur]])
			return 0;
		seen[a[cur]]=1;
		cur=(a[cur]+cur)%lg;
	}
	return 1;

}
int main(){
	ll n;
	cin>>n;
	while(1){
		n++;
		if(!standard(n))
			continue;
		//cout<<n<<" ";

		if(runround(n)){
			cout<<n<<endl;
			return 0;
		}
	}
	return 0;
}
