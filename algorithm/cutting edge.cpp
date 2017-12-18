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
vector<int>v[MAXN]  ;
vector<pii >e, CE;
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
                        e.push_back(pii( a  , b));
                }
        memset(gpar , 127 , sizeof gpar);
         dfs(1,0);
                for(int i=0;i<e.size();i++)
               {
                 if(depth[e[i].first]>depth[e[i].second])
                  swap(e[i].first , e[i].second);
                  int a=e[i].first  , b=e[i].second;
                        if(gpar[b]>depth[a])
                         CE.push_back(pii(a  , b) );
              }
              cout<<CE.size()<<endl;
              for(int i=0;i<CE.size();i++)
               cout<<CE[i].first  <<" "<< CE[i].second<<endl;                
}
