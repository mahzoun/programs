/*
ID: dhm_blo2
PROG: lamps 
LANG: C++11
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#define cin fin
#define cout fout
using namespace std;
typedef long long ll;
set<string> s;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
map<string,bool> mp;
const int maxn = 100+10;
bool on[maxn],off[maxn],lamps[maxn];
int n,c;
int ans=0;
bool check()
{
	for(int i=0;i<n;i++)
		if( (on[i] && lamps[i]==0) || (off[i] && lamps[i]) )
			return 0;
	return 1;

}
void print()
{
	for(int i=0;i<n;i++)
		cout<<lamps[i];
	cout<<endl;
}
int main()
{
	cin>>n>>c;
	if(c%4!=0)
		c%=4;
	if(c>0 && c%4==0)
		c=4;
	int index=0;
	int a;
	cin>>a;
	while(a!=-1){
		on[a-1]=1;
		cin>>a;
	}
	cin>>a;
	while(a!=-1){
		off[a-1]=1;
		cin>>a;
	}
	for(int i=0;i<maxn;i++)
		lamps[i]=1;
	for(int i=0;i<(1<<4);i++){
		int cnt=0;
		int tmp=i;
		cnt+=(tmp%2);
		for(int j=0;j<n;j++)
			lamps[j]^=(tmp%2);
		tmp/=2;
		cnt+=(tmp%2);
		for(int j=0;j<n;j+=2)
			lamps[j]^=(tmp%2);
		tmp/=2;
		cnt+=(tmp%2);
		for(int j=1;j<n;j+=2)
			lamps[j]^=(tmp%2);
		tmp/=2;
		cnt+=(tmp%2);
		for(int j=0;j<n;j+=3)
			lamps[j]^=(tmp%2);
		/*for(int j=0;j<n;j++)
			cout<<lamps[j];
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<on[j];
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<off[j];
		cout<<endl;*/
		//cout<<c<<" "<<cnt<<endl;
		if(check() && cnt<=c ){
			string cur;
			for(int j=0;j<n;j++)
				cur+=lamps[j]+'0';
			if(mp[cur]==0){
				mp[cur]=1;
				ans++;
				s.insert(cur);
			}
			
		}
		for(int j=0;j<n;j++)
			lamps[j]=1;
	}
	set<string>::iterator it;
	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<endl;
	if(ans==0)
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
