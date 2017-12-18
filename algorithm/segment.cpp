#include <iostream>
#include <algorithm>
using namespace std;

#define lch(x) ( 2*(x)+1 )
#define rch(x) ( 2*(x)+2 )

const int MAX_N = 10000 + 10;

int n;

int tree[4*MAX_N];

void add(int r, int le, int ri, int i, int delta)
{
if ( le==ri )
{
tree[r] += delta;
return;
}
int mid = (le+ri) /2;
// left_sub_tree --> [le, mid]
// right_sub_tree --> [mid+1, ri]
if ( i <= mid )
add(lch(r), le, mid, i, delta);
else
add(rch(r), mid+1, ri, i, delta);
tree[r] = tree[lch(r)] + tree[rch(r)];
}

int sum(int r, int le, int ri, int i, int j)
{
if ( j<le || i>ri ) return 0;
if ( i<=le && ri<=j ) return tree[r];
int mid = (le+ri) / 2;
return sum(lch(r), le, mid, i, j) + sum(rch(r), mid+1, ri, i, j);
}

int main()
{
cin >> n;
for (int i=0; i<n; ++i)
{
int x;
cin >> x;
add(0, 0, n-1, i, x);
}
return 0;
}

