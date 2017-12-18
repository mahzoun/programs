/* In the Name of God */ 

#include <bits/stdc++.h>
#define F first
#define S second
using namespace std ;

const int maxn = 100001 ;

typedef long long ll ;
typedef long double ld ;
typedef pair<int , int > pii ;

class Node
{
	char c ;	
	Node* N[30]={0} ;
	
	Node(char c)
	{	
		this->c = c; 
	}

};

class Dic
{
	Node* head = new Node();

	void add(string s)
	{
		Node* now = head ;
		
		for(int i = 0 ; i < s.size() ; i ++ )
		{
			if(now->N[s[i]-'A']==0)	
				now->N[s[i]-'A'] = new Node(s[i]);
			else
				now=now->N[s[i]-'A'];
		}

	}
	
};

int main()
{ 
	int n ;
	cin>>n;
	
	Dic *d = new Dic();

	for(int i = 1 ;  i <= n ; i ++ )
	{
		string s ;
		cin>>s;
		d->add(s);
	}	
}