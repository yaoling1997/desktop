#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const ld eps= 1e-12;
const int maxn= 3e5,oo= 1e9;
ld f[maxn];
int a[maxn];
double ans;
ld l,r,x;
int n,i,Min= oo;
bool ok(ld x){
	ld A= -oo,B= oo;
	int i;
	for (i= 1;i<=n;i++){
		f[i]= max(f[i-1],(ld)0)+a[i]-x;
		A= max(f[i],A);
	}
	for (i= 1;i<=n;i++){
		f[i]= min(f[i-1],(ld)0)+a[i]-x;
		B= min(B,f[i]);
	}
	ans= max(A,-B);
	return A>-B;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		Min= min(Min,a[i]);
	}
	for (i= 1;i<=n;i++)
		a[i]-= Min;
	l= 0,r= oo;
	while (r-l>eps){
		ld mid= (l+r)/2;
		if (ok(mid)) l= mid;
		else r= mid;
	}
	x= Min+l;
	printf("%.15lf\n",ans);
	return 0;
}
	
