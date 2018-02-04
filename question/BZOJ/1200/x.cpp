#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll maxn= 300001,oo= 1e12;
vector<ll> st[2];
ll a[maxn],f[2][20][2];
ll ans,i,n;
void Min(ll &a,ll b){a= min(a,b);}
void get(){
	ans= oo;
	st[0].clear();st[1].clear();
	ll o= 0,p= 1,i,j,k,len,len1;
	for (i= 1;i<=3;i++)
		for (k= a[i];k>=a[i]-2&&k>0;k--)
			if (k<=a[1]) st[0].push_back(k);
	len= st[0].size();
	for (i= 0;i<len;i++)
		f[0][i][0]= f[0][i][1]= a[1]-st[0][i];
	for (i= 2;i<=n;i++){
		o^= 1;p^= 1;st[o].clear();
		for (j= max(1ll,i-2);j<=i+2&&j<=n;j++)
			for (k= a[j];k>=a[j]-2&&k>0;k--)
				if (k<=a[i]) st[o].push_back(k);
		len= st[o].size();len1= st[p].size();
		for (j= 0;j<len;j++){
			f[o][j][0]= f[o][j][1]= oo;
			for (k= 0;k<len1;k++)
				if (st[p][k]<st[o][j]) Min(f[o][j][1],f[p][k][0]);
				else if (st[p][k]>st[o][j]) Min(f[o][j][0],f[p][k][1]);
				else Min(f[o][j][0],f[p][k][0]),Min(f[o][j][1],f[p][k][1]);
			f[o][j][0]+= a[i]-st[o][j];f[o][j][1]+= a[i]-st[o][j];
		}
	}
	for (i= 0;i<len;i++){
		ans= min(ans,f[o][i][0]);
		ans= min(ans,f[o][i][1]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++) scanf("%lld",&a[i]);
	get();
	printf("%lld\n",ans);
	return 0;
}
