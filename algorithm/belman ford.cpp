#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<set>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int MAXN=100000000;

vector<int>W;
vector<pii>e;
int best[1001];

int main()
{
  int n,m;
   cin>>n>>m;
   
  int v1,v2;
   cin>>v1>>v2;
    
   for(int i=0;i<=n;i++)
       best[i]=MAXN;
   
    best[v1]=0;
   
   for(int i=0;i<m;i++)
   {
       int u,v,w;
       cin>>u>>v>>w;
        e.push_back(pii(u,v));
        W.push_back(w);  
   }
  
   for(int i=1;i<n;i++)
    for(int j=0;j<e.size();j++)
       {
            int u=e[j].second , v=e[j].first , w=W[j] ;
            best[u]=min(best[u],best[v]+w);
                
       }     
   for(int j=0;j<e.size();j++)
       {
            int u=e[j].second,v=e[j].first,w=W[j];
            if(best[u]>best[v]+w)
            {
                cout<<"Negetive cycle"<<endl;
                return 0;
            }    
       }
     cout<<best[v2];    
}
     
