/*
ID: dhm_blo2
PROG: prefix 
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
//#define cin fin
//#define cout fout
using namespace std;
typedef long long ll;
ifstream fin("prefix.in");
ofstream fout("prefix.out");
const int maxn=2e5+1;
int dp[maxn];
map<string,bool> mp;
string s;
bool equal(string s1,string s2)
{
	if(s1.size()!=s2.size())
		return 0;
	for(int i=0;i<s1.size();i++)
		if(s1[i]!=s2[i])
			return 0;
	return 1;
}
int main()
{
	string tmp;
	cin>>tmp;
	while(!equal(tmp,".")){
		mp[tmp]=1;
		cin>>tmp;
	}
	cin>>s;
	if(mp[s.substr(0,1)])
		dp[0]=1;
	for(int i=1;i<s.size();i++){
		for(int j=0;j<=i;j++){
			if(mp[s.substr(i-j,j)]){
				cout<<i<<" "<<j<<" "<<s.substr(i-j,j)<<endl;
				dp[i]=max(dp[i],dp[i-j]+j);
			}
		}
		dp[i]=max(dp[i],dp[i-1]);

	}
	for(int i=0;i<s.size();i++)
		cout<<dp[i]<<" "<<s.substr(0,i+1)<<endl;
	cout<<dp[s.size()-1]<<endl;
	return 0;
}
