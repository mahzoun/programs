#include <bits/stdc++.h>

using namespace std ;

const int maxn = 1e5+10;

typedef long double ld ;

ld x[maxn] , y[maxn];

int main()
{
	int n ;
	cin>>n;
	for(int i = 0 ; i <n ; i ++ )
		cin>>x[i] >> y[i];
	ld Area = 0 ;
	for(int i = 0 ; i < n ; i ++ )
		Area += ((x[i] * y[(i+1)%n]) - (y[i] * x[(i+1)%n]));
	cout<<Area<<endl;
	
}