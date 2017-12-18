/* In the Name of God */ 

#include <bits/stdc++.h>
#define F first
#define S second
using namespace std ;

const int maxn = 100001 ;

typedef long long ll ;
typedef long double ld ;
typedef pair<int , int > pii ;


int n ;
pii point [maxn];


ld cross(pii a , pii b){	return a.F*b.S - a.S*b.F;	}
ld dot(pii a , pii b ){		return a.F*b.F + a.S*b.S;	}
ld length(pii a){	  return sqrt(a.F*a.F + a.S*a.S);	}
ld getSin(pii a , pii b){	return cross(a , b) / (length(a) * length(b));	}
ld getCos(pii a , pii b){	return dot(a , b) / (length(a) * length(b));	}
pii getVector(pii a , pii b ){	return pii(b.F-a.F , b.S-a.S);	}


ld getArea()
{
	ld ans = 0 ;
	for(int i = 2 ; i <n ; i ++ )
		ans += cross( getVector(point[1] , point[i])  , getVector(point[1] , point[i+1]) );
	return abs(ans / 2);
}

int main()
{ 
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++ )
		cin>>point[i].F >> point[i].S ;

	cout<<getArea();

}