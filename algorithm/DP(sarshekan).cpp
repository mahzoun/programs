#include <bits/stdc++.h>
#define mod 1000000007
#define F first
#define S second

using namespace std ;

typedef long double ld ;
typedef pair<ld , ld > pii ;

int n  , q ;
vector <pii > lines , lans ;
vector <int> ans ;

ld intersect(ld a , ld b , ld ap , ld bp)
{
	if(a == ap )
		return - mod  ;
	ld x = (b-bp)/(ap-a) ;
	return x ;
}

void add_line(int i )
{
			int ea = ans.size() -1 ;

		while( ans.size() )
		{
			pii u = lines[ans[ea]] ;
			ld X  = intersect( u.F , u.S , lines[i].F , lines[i].S );
			
			if(X == -mod )
				break ;

			if( lans[ea].F < X && X <= lans[ea].S )
			{
				ld first = lans[ea].F;
				lans[ea].S= X;
				ans.push_back(i);
				lans.push_back(pii(X , mod));
				break;
			}
			else if( X <= lans[ea].F )
			{
				ans.pop_back();
				lans.pop_back();
			}
			else
				break;
		}
		if(ans.size() == 0 )
		{
			ans.push_back(i);
			lans.push_back(pii(-mod , mod));
		}
	return ;	
}
void solve()
{
	sort(lines.begin() , lines.end());

	for(int i = 0 ; i < n ;  i ++ )
		lines[i].F*=-1;

	for(int i = 0 ; i < n ;  i ++ )
		add_line(i);

	return ;
}

int get_ans(ld x)
{
	int l = 0 , r = ans.size()-1 , m ;
	int srch = 0 ;

	while(l<=r)
	{
		m=(l+r)/2;
		if(lans[m].F <=x && x<= lans[m].S)
			return m ;
		if(x < lans[m].F )
			r=m-1;
		else 
			 l=m+1;
	}
}

int main()
{
	
	cin>>n>>q;

	for(int i = 1 ; i <= n ; i ++ )
	{
		int a , b ;
		cin>>a>>b;
		lines.push_back(pii(-a,b));
	}

	solve();

	for(int i = 1 ; i <= q ; i ++ )
	{
		int qx ; 
		cin>>qx;
		int a=get_ans(qx);
		
		cout<<lines[a].F * qx + lines[a].S<<endl;
		
	}

}