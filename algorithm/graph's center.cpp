/* In the Name of God */
#include <iostream>
#include <set>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include<cstdio>
#define lch(r) (2*(r)+1)
#define rch(r) (2*(r)+2) 
#define inf (1<<30)
#define F first
#define S second
#define mod 1000000007
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN = 100000+10;
vector<int>v[MAXN] ;
int md[MAXN] , ans[MAXN] , high[MAXN] , par[MAXN] ;
bool mark[MAXN], mark2[MAXN];
int dfs(int a)
{
    mark[a]=1;
    for(int i=0;i<v[a].size();i++)
    if(!mark[v[a][i]])
    {
            par[v[a][i]]=a;
            dfs(v[a][i]);
            md[a]=max(md[a] ,md[v[a][i]]+1);
            
    }    
    
}
int dfs2(int a)
{
    
    mark2[a]=1;

    if(a!=1)
    {
       int u=par[a];
           for(int i=0;i<v[u].size();i++)
           if(v[u][i]!=par[u]&&v[u][i]!=a )
              high[a]=max(high[a] ,md[v[u][i]]+2);
           high[a]=max(high[a] , high[u]+1);
    }
    ans[a]=max(high[a] , md[a]);
    for(int i=0;i<v[a].size();i++)
    if(!mark2[v[a][i]])
       dfs2(v[a][i]);
    
}
int main()
{
        int n,m;
        cin>>n;
        m=n-1;
        for(int i=1;i<=m;i++)
        {
              int a,b;
              cin>>a>>b;
              v[a].push_back(b);
              v[b].push_back(a);
            
        }
        dfs(1);       
        dfs2(1);
        for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
        cin>>n;
}
