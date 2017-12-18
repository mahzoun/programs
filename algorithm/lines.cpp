/* In the Name of God */ 

#include <bits/stdc++.h>
#define F first
#define S second
using namespace std ;

const int maxn = 100001 ;

typedef long long ll ;
typedef long double ld ;
typedef pair<int , int > pii ;

int A1 , B1 , C1 ;
int A2 , B2 . C2 ;



int main()
{ 
	// Ax + By = C 
	
	cin>>A1 >> B1 >> C1 ;
	cin>>A2 >> B2 >> C2 ;
	
	int det = A1*B2 - B1*A2;

	// intersect point 
	
	ld x = ld(C1*B2 - C2*B1)/det ;
	ld y = ld(C2*A1 - C1*A2)/det ;
	if(det == 0 )
		cout<<"parallel"<<endl;
	else
		cout<<x << " " << y << endl;
	/**/
	


}