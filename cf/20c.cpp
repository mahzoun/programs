#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
const long long maxn=1e5+1, inf=1e17+1;
vector<pair<int, int>> v[maxn];
long long dis[maxn];
int n, m, par[maxn];
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
	       	a--; b--;
		v[a].push_back(make_pair(b, w));
		v[b].push_back(make_pair(a, w));
	}
	for(int i = 0; i < maxn; i++)
		dis[i] = inf;
	dis[0] = 0;
	set<pair<int,int>> s;
	s.insert(make_pair(0, 0));
	while(!s.empty()){
		pair<int, int> p = *s.begin();
		int u = p.second;
		s.erase(s.begin());
		for(int i = 0; i < v[u].size(); i++){
			if(dis[v[u][i].first] > dis[u] + v[u][i].second){
				dis[v[u][i].first] = dis[u] + v[u][i].second;
				s.insert(make_pair(dis[v[u][i].first], v[u][i].first));
				par[v[u][i].first] = u;
			}
		}
	}
	if(dis[n - 1] == inf){
		cout << -1 << endl;
		return 0;
	}
	int dad = n - 1;
	while(dad != 0){
		ans.push_back(dad+1);
		dad = par[dad];
		
	}
	ans.push_back(1);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[ans.size() - 1 - i] << " ";
	cout<<endl;
	return 0;
}
