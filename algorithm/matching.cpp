//In the Name of God
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100 * 2 + 10;
int n , m , ted = 0 , match[maxn];
vector <int> G[maxn];
bool mark[maxn];

bool dfs(int v){
  if(mark[v])
    return false;
  mark[v] = true;
  for(int i = 0 ; i < G[v].size() ; i++){
    int u = G[v][i];
    if(match[u] == -1 || dfs(match[u])){
      match[u] = v;
      match[v] = u;
      return true;
    }
  }
  return false;
}

int main(){
  memset(match , -1 , sizeof match);
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++){
    int v , u;
    cin >> v >> u;
    v--; u--;
    G[v].push_back(u + n);
    G[u + n].push_back(v);
  }
   for(int i=0;i<n;i++)
    for(int j=0;j<v[i].size();j++)
     if(match[v[i][j]]==-1)
      {
        match[i]=v[i][j];
        match[v[i][j]]=i;
      }
      
  for(int i = 0 ; i < n ; i++){
    dfs(i);
    memset(mark , false , sizeof mark);
  }
  for(int i = 0 ; i < n ; i++)
    if(match[i] != -1)
      ted++;
  cout << ted << endl;
  for(int i = 0 ; i < n ; i++)
    if(match[i] != -1)
      cout << i + 1 << ' ' << match[i] - n + 1 << endl;
  return 0;
}
