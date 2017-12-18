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
typedef   long long ll;
typedef long double ld;
typedef pair<int  ,int  > pii;
typedef pair<ld , int> pid;
const int   MAXN = 100000+10;
pii  p[MAXN];
vector<int>v;
vector<pid>po;
ld pi=3.1415;
bool ss (pii a , pii b)
{
        if(a.S<b.S)
        return 1;
        if(a.S>b.S)
        return 0;
        return a.F<b.F;
}
int main()
{
   ios_base::sync_with_stdio(false);
                int n ; 
                cin>>n;
                for(int i=1;i<=n;i++)
                    cin>>p[i].F >>p[i].S;
                sort(p+1 , p+n+1 , ss);
             
               for(int i=2;i<=n;i++)
               {
                       ld d =(p[i].F-p[1].F)*(p[i].F-p[1].F) +(p[i].S-p[1].S)*(p[i].S-p[1].S) , x=p[i].F;
                       d=sqrt(d);
                            ld dot=x/d;
                            po.push_back(pid(acos(dot) * 180 / pi , i) );
               }
               sort(po.begin() , po.end());
              v.push_back(1);
              v.push_back(po[0].S);
              v.push_back(po[1].S);
            
              for(int i=2;i<po.size();i++)
             {
                        int u=po[i].S , check=1 ;
                        while(check)
                        {
                                int t=v[v.size()-1],t2=v[v.size()-2];
                                ld x1=p[u].F-p[t].F , y1=p[u].S-p[t].S ;          
                                ld x2=p[t2].F-p[t].F , y2=p[t2].S-p[t].S ;          
                                 ld det=x1*y2-x2*y1;
                                 ld dang=det/(sqrt(x1*x1+y1*y1) * sqrt(x2*x2+y2*y2));
                                 if(dang<0)
                                 v.pop_back();
                                 else
                                 check=0;
                        }
                        v.push_back(u);
              }
              cout<<v.size();
              return 0;
                    for(int i=0;i<v.size();i++)
                    cout<<p[v[i]].F<<' ' << p[v[i]].S<<endl;
         
}
 
