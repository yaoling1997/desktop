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
typedef pair<ll,ll> PA;
ll a[maxn],A[maxn];
PA b[maxn];
int n,m,tot,x;
bool cmp(PA c,PA d){
	return a[c.first]*A[c.second]<a[d.first]*A[d.second];
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=x;
	}
	for (int i=1;i<=m;i++){
		scanf("%d",&x);
		A[i]=x;
		for (int j=1;j<=n;j++)
			b[++tot]=make_pair(j,i);
	}
	sort(b+1,b+tot+1,cmp);
	int k= b[tot].first;
	for (int i=tot-1;i>0;i--)
		if (b[i].first==k)
			continue;
		else {
			ll x= a[b[i].first]*A[b[i].second];
			printf("%I64d",a[b[i].first]*A[b[i].second]);
			break;
		}
	return 0;
}
