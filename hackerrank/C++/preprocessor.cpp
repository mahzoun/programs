#include <iostream>
#include <vector>
#define io(v) cin >> v
#define foreach(x, i) for(int i = 0; i < v.size(); i++)
#define toStr(str) #str
#define FUNCTION(str, op) void str(int &a, int &b){ (a) =  (a) op (b) ? (a) : (b);}
#define INF (1e8 + 2)

using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
    cout << v[i] << "\t" << mn << "\t" << mx <<endl;
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
