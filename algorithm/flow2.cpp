//In The Name Of God
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<set>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define MAX 10001
#define inf 2*(( 1<<30 )-1)+1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
vector<int>v[401],v2[401];
int f[401][401],c[401][401],n,m,mark[401];

int flow(int a)
{
        mark[a]=1;
        if(a==n)
           return 1;

        for(int i=0;i<v[a].size();i++)
                if(mark[v[a][i]]==0 && c[a][v[a][i]]>f[a][v[a][i]] && flow(v[a][i]))
                {
                        f[a][v[a][i]]++;
                        return 1;
                }

       for(int i=0;i<v2[a].size();i++)
        if(mark[v2[a][i]]==0&&f[v2[a][i]][a]>0&&flow(v2[a][i]))
        {
                f[v2[a][i]][a]--;
                return 1;
        }
      return 0;
}
int main()
{
     ios_base::sync_with_stdio(false);

       cin>>n>>m;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
      		   c[i][j]=1;
             for(int i=1;i<=m;i++)
             {
                int a,b;
                cin>>a>>b;
                v[a].push_back(b);
                v2[b].push_back(a);
            }
    while(flow(1))
        memset (mark , 0 , sizeof mark);

     int ans=0;
     for(int i=0;i<v[1].size();i++)
      ans+=f[1][v[1][i]];

    cout<<ans;
}

