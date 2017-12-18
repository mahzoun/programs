#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
vector<int>G[MAX];
vector<int>G1[MAX];
vector<int>topol;
vector<int>ans[MAX];
int mark[MAX]={0},mark2[MAX]={0},k=1;

int t_sort(int v)
{
    mark[v]=1;
    for(int i=0;i<G[v].size();i++)
     {
        int u=G[v][i];
        if(mark[u]==0)
        t_sort(u);
     }
     topol.push_back(v);
}
int dfs(int v)
{
    
    mark2[v]=1;
    ans[k].push_back(v);
    for(int i=0;i<G1[v].size();i++)
     {
        int u=G1[v][i];
        if(mark2[u]==0)
            dfs(u);
     }      
}
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G1[b].push_back(a);
   }
        for(int i=1;i<=n;i++)
         if(mark[i]==0)
     	   t_sort(i);
   reverse(topol.begin(),topol.begin()+n);
        for(int i=0;i<topol.size();i++)
            if(mark2[topol[i]]==0)
            {
                dfs(topol[i]);
                k++;
                
            }  
}
