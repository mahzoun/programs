//In The Name Of God
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<set>
#include<cstdio>
#include<map>
#include<cstdio>
#define f first
#define s second
#define MAX 100001
#define inf 2*(( 1<<30 )-1)+1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
int a[50001],dp[50001][20];
int rmq (int x, int y)
{
  int t=log(y-x);
        return min(dp[x][t],dp[y-(1<<t)][t]);
}
int main()
{
  ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    memset(dp , 127 , sizeof dp);
    for(int i=1;i<=n;i++)
     cin>>a[i];
   for(int i=1;i<=n;i++) 
     dp[i][0]=a[i];
    
   for(int j=1;j<10;j++)
   for(int i=1;i<=n;i++)
    
     dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
       
     for(int i=1;i<=m;i++)
     {
        int b,c;
        cin>>b>>c;
        cout<<rmq(b,c+1)<<endl;      
     }    
}  

