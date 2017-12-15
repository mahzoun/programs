#include <iostream>
#include <algorithm>
using namespace std;

#define lch(r) ( 2*(r)+1 )
#define rch(r) ( 2*(r)+2 )

const int MAX_N = 100000 + 10;

int tree[4*MAX_N];
int tot[4*MAX_N];
int n;

int actualSum(int r, int le, int ri) { return (ri-le+1)*tot[r] + tree[r]; }
int common(int x, int y, int i, int j) { return min(y, j) - max(x, i) + 1; }

void update(int r, int le, int ri, int i, int j, int delta)
{
if ( j<le || ri<i ) return;
if ( i<=le && ri<=j )
{
tot[r] += delta;
return;
}
int mid = (le+ri) / 2;
update(lch(r), le, mid, i, j, delta);
update(rch(r), mid+1,ri,i, j, delta);
tree[r] = actualSum(lch(r), le, mid) + actualSum(rch(r), mid+1, ri);
}

int sum(int r, int le, int ri, int i, int j)
{
if ( j<le || ri<i ) return 0;
if ( i<=le && ri<=j ) return actualSum(r, le, ri);
int mid = (le+ri) / 2;
/*
tot[lch(r)] += tot[r];
tot[rch(r)] += tot[r];
tot[r] = 0;
*/
return  sum(lch(r), le, mid, i, j) +
sum(rch(r), mid+1, ri, i, j) +
common(le, ri, i, j)*tot[r];
}

int main()
{


return 0;
}

