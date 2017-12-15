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
#include <cstdio>
using namespace std;
const int MAXN = 100000+10;
#define lc(x) (2*(x)+1)
#define rc(x) (2*(x)+2)
#define inf 1<<30
typedef pair<int,int> pii;
typedef long long ll;
int fen[MAXN];
int add(int i , int delta)
{
       while(i<=MAXN)
       {
                fen[i]+=delta;
                i+=i&-i;
       }
}
int sum(int i)
{
        int ans=0;
        while(i>0)
        {
                ans+=fen[i];
                i-=i&-i;
        }
        return ans;
}

int main()
{

}
