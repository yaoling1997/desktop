#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 1e6+10,M= 20,mo= 1e9+7;
vector< vector<ll> > f,sum;
vector<ll> g;
ll a[maxn],c[maxn];
ll n,l,k,K,B,ans,i,j,z,x,y,N,r;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d%I64d",&n, &l, &k);
	g.push_back(0);
	for (i= 0;i<n;i++){
		scanf("%I64d",&a[i]);
		c[i]= a[i];
		g.push_back(0);
	}
	if (l<=n){
		printf("%I64d\n",l);
		return 0;
	}
	sort(c,c+n);
	K= min(l/n,k);
	N= (l/n)%mo;
	r= l%n;
	f.push_back(g);
	sum.push_back(g);
	for (i= 1;i<=k;i++){
		f.push_back(g);
		sum.push_back(g);
	}
	for (i= 0;i<n;i++){
		f[1][i]= 1;
		sum[0][i]= 1;
	}
	sum[1][0]= 1;
	for (i= 1;i<n;i++)
		sum[1][i]= (f[1][i]+sum[1][i-1])%mo;
	for (i= 2;i<=K;i++){
		for (j= 0;j<n;j++){
			z= upper_bound(c,c+n,c[j])-c-1;
			f[i][j]= sum[i-1][z];
		}
		sum[i][0]= f[i][0];
		for (j= 1;j<n;j++)
			sum[i][j]= (f[i][j]+sum[i][j-1])%mo;
	}
	for (i= 1;i<=K;i++){
		ans= (ans+(N-i+1)*sum[i][n-1])%mo;
		for (j= 0;j<r;j++){
			z= upper_bound(c,c+n,a[j])-c-1;
			ans= (ans+sum[i-1][z])%mo;
		}
	}
	if (r&&K+1<=k){
		i= K+1;
		for (j= 0;j<r;j++){
			z= upper_bound(c,c+n,a[j])-c-1;
			ans= (ans+sum[i-1][z])%mo;
		}
	}
	ans= (ans+mo)%mo;
	printf("%I64d\n",ans);
	return 0;
}
