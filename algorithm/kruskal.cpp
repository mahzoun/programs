#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<set>
#define MAX 1000001
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int par[100001],cnt,n,m;
vector<pii>G;
set< pair< int , pii > >s;

int find_par(int v)
{
        if(par[v]==v)
        return v;
        return par[v]=find_par(par[v]);
}

int kruskal()
{
    while(s.size() && cnt<n-1)
    {
         int w=s.begin()->first , u=s.begin()->second.first , v=s.begin()->second.second ;
         s.erase(s.begin());
         find_par(u);
         find_par(v);

         if(par[v]==par[u])
           continue;

         par[par[v]]=par[u];
         G.push_back(pii(u,v));
         cnt++;
    }
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<=n;i++)
        par[i]=i;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        s.insert(make_pair(w,pii(v,u)));
    }
    kruskal();
   
    
}

