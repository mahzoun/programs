//In The Name Of God
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int>ans;
vector<int>LIS;
vector<int>ind; 
int n,a[100001],par[100001];
int main()
{

    
    cin>>n;
    for(int i=1;i<=n;i++)
     {
        cin>>a[i];
     }
    par[1]=-1;   
    LIS.push_back(a[1]);
    ind.push_back(1); 
    for(int i=2;i<=n;i++)
    {
        int j=LIS.size()-1;
        if(a[i]>LIS[j])
         {
            LIS.push_back(a[i]);
            ind.push_back(i);
            par[i]=ind[j];
         }
         else
         {
            int s=lower_bound(LIS.begin(),LIS.end(),a[i])-LIS.begin();           
             LIS[s]=a[i];
               ind[s]=i;
               if(s!=0)
                par[i]=ind[s-1];
                else
                    par[i]=-1;
             
         }
    }
   
    cout<<LIS.size()<<endl;
     int k=ind[ind.size()-1];
     while(k!=-1)
     {
        cout<<a[k]<<" ";
        k=par[k];
     }
       
}
