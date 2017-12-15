/*
ID: dhm_blo2
PROG: subset
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
ll ans=0,sum;
int n;
ll dp[40][40*40];
ifstream fin("subset.in");
ofstream fout("subset.out");
int main(){
	fin>>n;
	sum=n*(n+1)/4;
	if(n%4==2 || n%4==1){
		fout<<0<<endl;
		return 0;
	}
	for(int i=0;i<40;i++)
		dp[i][0]=1;
	for(int i=1;i<40;i++)
		for(int j=1;j<40*40;j++){
			//cerr<<i<<" "<<j<<endl;
			dp[i][j]+=dp[i-1][j];
			if(j-i>=0)
				dp[i][j]+=dp[i-1][j-i];
		}
	fout<<dp[n][sum]/2<<endl;
	return 0;

}
















