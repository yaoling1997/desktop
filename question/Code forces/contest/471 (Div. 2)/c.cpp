#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const double eps=1e-10;
const ll oo=1e18;
const int maxn= 5e5;
vector<ll> v;
int Q;
void init(){
	for (ll i=2;i<=1e6;i++){
		ll r=i;
		while (r<=1e18&&log10(r)+log10(i)<=18){
			r*=i;
			ll s=sqrt(r);
			if (r!=s*s)
				v.pb(r);
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}
ll solve(ll o){
	return upper_bound(v.begin(),v.end(),o)-v.begin()+sqrt(o)+eps;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	init();
	scanf("%d",&Q);
	for (int tt=1;tt<=Q;tt++){
		ll L,R,ans;
		//scanf("%I64d%I64d",&L,&R);
		cin>>L>>R;
		ans=solve(R)-solve(L-1);
		cout<<ans<<endl;
	}
	return 0;
}
