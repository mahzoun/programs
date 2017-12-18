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
typedef long long ll;
typedef pair<ll ,ll > pii;
typedef long double ld;
const int MAXN = 100000+10;
vector<int>v[MAXN]  , CV;
int depth[MAXN],mark[MAXN],gpar[MAXN];
bool ans[MAXN];
int dfs(int a,int par)
{
        mark[a]=1;
        for(int i=0;i<v[a].size();i++)
         if(mark[v[a][i]]==1&&v[a][i]!=par)
         gpar[a]=min( gpar[a],depth[v[a][i]]);
       for(int i=0;i<v[a].size();i++)
        if(mark[v[a][i]]==0)
        {
                depth[v[a][i]]=depth[a]+1;
                dfs(v[a][i], a);
                gpar[a]=min(gpar[v[a][i]] , gpar[a] );
        }  
        if(gpar[a]<=depth[a])
         ans[a]=1;
          
}
int main()
{
   ios_base::sync_with_stdio(false);
                 int n,m;
                  cin>>n>>m;
                for(int i=1;i<=m;i++)
                {
                          int a, b;
                          cin>>a>>b;                       
                        v[a].push_back(b);
                        v[b].push_back(a);
                }
        memset(gpar , 127 , sizeof gpar);
         dfs(1,0);
                 for(int i=1;i<=n;i++)
                  if(ans[i]==0&&v[i].size()>1)
                    CV.push_back(i);
        cout<<CV.size()<<endl;
        for(int i=0;i<CV.size();i++)
         cout<<CV[i]<<" ";                   
}
