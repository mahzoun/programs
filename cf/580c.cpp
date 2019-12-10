#include <iostream>
#include <queue>
using namespace std;
const long long maxn = 1e5 + 1;
int n, m, ans[maxn];
bool cat[maxn], seen[maxn];
vector<int> V[maxn];
queue<int> q;
int ANS;
void bfs(int u, int m)
{
	q.push(u);	
	seen[u] = 1;
	ans[u] = m - cat[u];
	while(!q.empty()){
		int v = q.front();
		q.pop();
		seen[v] = 1;
		//if(ans[v] < 0)
		//	cat[v] = 1;
		for(int i = 0; i < V[v].size(); i++){
			if(!seen[V[v][i]]){
				q.push(V[v][i]);
			//	cout<< v << " " <<ans[v]<<" " << cat[V[v][i]] << endl;
				if(cat[V[v][i]])
					ans[V[v][i]] = ans[v] - cat[V[v][i]];
				else if(ans[v] < 0)
					ans[V[v][i]] = -1;
				else
					ans[V[v][i]] = m;
			}
		}	
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> cat[i];
	}
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	bfs(0, m);
	for(int i = 1; i < n; i++){
		//cout << i << " " << V[i].size() << " " << ans[i] << endl;
		if(V[i].size() == 1 and ans[i] > -1)
			ANS++;
	}
	cout << ANS << endl;
	return 0;
}
