#include <iostream>
using namespace std;
const int maxn = 1e7+1;
int n, m, a, b, k;
long long arr[maxn];
long long ans = 0;
int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> k;
    arr[a-1] += k;
    arr[b] -= k;
  }
  for(int i = 1; i < n; i++)
    arr[i] += arr[i-1];
  for(int i = 0; i < n; i++)
    ans = arr[i] > ans ? arr[i] : ans;
  cout << ans << endl;
  return 0;
}
