#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e3;
ll a[maxn],b[maxn];
ll A[maxn],B[maxn];
ll MA[maxn],MB[maxn];
map<ll,int> M;
int n,m,X,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		A[i]=A[i-1]+a[i];
	}
	for (int i=1;i<=m;i++){
		cin>>b[i];
		B[i]=B[i-1]+b[i];
	}
	cin>>X;
	for (int i=1;i<=m;i++){
		for (int j=1;j+i-1<=m;j++){
			ll tmp=B[j+i-1]-B[j-1];
			MB[i]=(MB[i]==0||MB[i]>tmp)?tmp:MB[i];
		}
		M[MB[i]]=i;
	}
	M[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j+i-1<=n;j++){
			ll tmp=A[j+i-1]-A[j-1];
			MA[i]=(MA[i]==0||MA[i]>tmp)?tmp:MA[i];
		}
		int now;
		map<ll,int>::iterator it=M.upper_bound(X/MA[i]);
		it--;
		now=i*it->second;
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
