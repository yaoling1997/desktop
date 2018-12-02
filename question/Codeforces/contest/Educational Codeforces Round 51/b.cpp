#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
ll l,r;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	cin>>l>>r;
	cout<<"YES"<<endl;
	for (ll i=l;i<=r;i+=2)
		cout<<i<<' '<<i+1<<endl;
}
