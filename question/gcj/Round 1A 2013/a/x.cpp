#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll oo= 2e18+2;
const int maxn= 2e5;
int T;
ll R,t,l,r;
bool ok(ll n){
	ld x= (ld)n*(2*R+2*n-1);
	return x<=t;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		cin>>R>>t;
		l= 0,r= oo;
		while (l+1<r){
			ll m= (l+r)>>1;
			if (ok(m)) l= m;
			else r= m;
		}
		printf("Case #%d: ",tt);
		cout<<l<<endl;
	}
	return 0;
}
