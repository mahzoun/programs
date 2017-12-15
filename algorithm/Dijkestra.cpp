/* In the Name of God */
#include <bits/stdc++.h> 

using namespace std;

const int maxn = 1e5+10;

typedef long long ll ;
typedef pair<int , int > pii ;

vector<int>v[maxn],w[maxn];
int best [maxn];
set<pii>s;

void dij(int a)
{
	memset(best , 127 , sizeof best);
	s.insert(pii(best[a]=0 , a) );

	while(s.size())
	{
		int u = s.begin()->second ;
		s.erase(s.begin());

		for(int i = 0 ; i < v[u].size() ; i  ++ )
			if(best[v[u][i]]  > best[u] + w[u][i] )
			{
				int x = v[u][i];
				s.erase( pii(best[x] ,  x) );
				best[x] = best[u]+w[u][i];
				s.insert( pii(best[x] ,  x) );
			}
	}
}

int main()
{
	int n , m ;
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i ++ )
	{
		int a ,  b , c;
		cin>>a>>b>>c;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);	
	}
	
	int x , y ;
	
	cin>>x>>y;

	dij(x);

	cout<<best[y]<<endl;
}	