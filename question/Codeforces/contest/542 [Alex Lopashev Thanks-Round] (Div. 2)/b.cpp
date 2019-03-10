#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int a[maxn];
pair<int,int> b[maxn];
ll ans;
int n;
ll getAns(){
	ll re=0;
	int p=1,q=1;
	for (int i=1;i<=n;i++){
		int t=b[2*i-1].second;
		int k=b[2*i].second;
		int delta=min(abs(t-p)+abs(k-q),abs(t-q)+abs(k-p));
		re+=delta;
		p=t;
		q=k;
	}
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++){
		scanf("%d",&a[i]);
		b[i]=make_pair(a[i],i);
	}
	sort(b+1,b+2*n+1);
	ans=getAns();
	printf("%I64d",ans);
	return 0;
}
