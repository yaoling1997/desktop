#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 3e5,oo= 1e18;
priority_queue<ll> Q;
ll a[maxn],d[10][maxn];
ll n,b,c,i,j,x,y,K,sum,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d%I64d%I64d",&n, &K, &b, &c);
	b= min(b,5*c);
	for (i= 1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for (i= 1;i<=n;i++)
		for (j= 0;j<5;j++)
			d[((a[i]+j)%5+5)%5][i]= a[i]+j;
	ans= oo;
	for (j= 0;j<5;j++){
		while (!Q.empty())
			Q.pop();
		sum= 0;
		for (i= 1;i<=K;i++){
			x= (d[j][i]-a[i])*c+(d[j][K]-d[j][i])/5*b;
			sum+= x;
			Q.push(x);
		}
		ans= min(ans,sum);
		for (i= K+1;i<=n;i++){
			x= (d[j][i]-a[i])*c-(d[j][i]-d[j][K])/5*b;
			sum+= x;
			Q.push(x);
			sum-= Q.top();
			Q.pop();
			ans= min(ans,sum+b*K*(d[j][i]-d[j][K])/5);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
