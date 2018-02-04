#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 2e3+10,oo= 1e9;
double f[maxn][maxn][2][2];
ll left[maxn],right[maxn],a[maxn];
double p,q;
ll n,h,i,j;
double cost(ll x,ll y){
	return a[y]-a[x];
}
double dfs(ll l,ll r,ll d1,ll d2){
	if (l>r) return 0;
	double &res= f[l][r][d1][d2];
	if (res>-1) return res;
	ll L= max(left[r],l),R= min(right[l],r);
	ll x,y;
	x= min(h,a[l]-a[l-1]);
	if (d1) x= min(x,a[l]-a[l-1]-h);
	y= min(h,a[r+1]-a[r]);
	if (!d2) y= min(y,a[r+1]-a[r]-h);
	res= 0;
	res= 0.5*p*(x+dfs(l+1,r,0,d2));                                //左树左倒
	if (R==r){                             //左树右倒
		res+= 0.5*q*(a[r]-a[l]+y);
	}else {
		res+= 0.5*q*(a[R]-a[l]+h+dfs(R+1,r,1,d2));
	}
	res+= 0.5*q*(y+dfs(l,r-1,d1,1));
	if (L==l){
		res+= 0.5*p*(a[r]-a[l]+x);
	}else {
		res+= 0.5*p*(a[r]-a[L]+h+dfs(l,L-1,d1,0));
	}
	return res;
}
int main()
{
	scanf("%lld%lld%lf",&n, &h, &p);
	q= 1-p;
	for (i= 1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (i= 0;i<=n;i++)
		for (j= 0;j<=n;j++)
			for (ll I= 0;I<2;I++)
				for (ll J= 0;J<2;J++)
					f[i][j][I][J]= -1000;
	a[0]= -oo;
	a[n+1]= oo;
	sort(a+1,a+n+1);
	left[1]= 1;right[n]= n;
	for (i= 2;i<=n;i++)
		if (a[i]-a[i-1]<h)
			left[i]= left[i-1];
		else left[i]= i;
	for (i= n-1;i>0;i--)
		if (a[i+1]-a[i]<h)
			right[i]= right[i+1];
		else right[i]= i;
	dfs(1,n,1,1);
	printf("%.9lf",f[1][n][1][1]);
	return 0;
}
