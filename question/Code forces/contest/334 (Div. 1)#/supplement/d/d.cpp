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
const double eps= 1e-12;
const int maxn= 3e3,oo= 1e9;
ld X[maxn],Y[maxn];
int a[maxn],b[maxn],c[maxn],sh[maxn];
ll ans,cnt;
ld k1,k2;
int i,j,k,n;
int dcmp(ld x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
ld slope(int a,int b){
	if (!dcmp(X[b]-X[a])) return oo;
	return 1.0*(Y[b]-Y[a])/(X[b]-X[a]);
}
bool cmp(int a,int b){
	ld x,y;
	x= slope(i,a);
	y= slope(i,b);
	return x<y;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d%d",&a[i], &b[i], &c[i]);
		if (!b[i])
			X[i]= (ld)c[i]/a[i];
		else if (!a[i])
			Y[i]= (ld)c[i]/b[i];
		else {
			X[i]= (ld)a[i]*c[i]/(a[i]*a[i]+b[i]*b[i]);
			Y[i]= (ld)b[i]/a[i]*X[i];
		}
		sh[i]= i;
	}
	for (i= 1;i<=n;i++){
		sort(sh+1,sh+n+1,cmp);
		cnt= 0;k= 0;
		for (j= 1;j<=n;j++){
			int p= sh[j];
			if (p<=i) continue;
			if (!dcmp(X[p]-X[i])&&!dcmp(Y[p]-Y[i])){
				ans+= n-i-1;
				cnt= 0;
			}else if (cnt==0){
				cnt++;
				k= p;
			}else {
				k1= slope(i,k);
				k2= slope(i,p);
				if (!dcmp(k1-k2)) cnt++;
				else {
					ans+= cnt*(cnt-1)/2;
					cnt= 1;
					k= p;
				}
			}
		}
		if (cnt) ans+= cnt*(cnt-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
