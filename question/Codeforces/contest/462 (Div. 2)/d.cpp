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
const int maxn= 5e3;
int a[maxn],b[maxn],c[maxn];
ll p;
int k,n,m;
void solve(){
	int zf=1;
	for (int i=0;i<=n;i++){
		c[i]-=b[i];
		if (zf==1){
			if (c[i]<=-k){
				c[i+1]--;
				c[i]+=k;
			}
			a[i]=-c[i];
		}else {
			if (c[i]<0){
				c[i+1]--;
				c[i]+=k;
			}
			a[i]=c[i];
		}
		zf*=-1;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%d",&p, &k);
	ll t=p;
	while (t){
		b[m]=t%k;
		t/=k;
		m++;
	}
	if (m&1){
		n=m+1;
	}else {
		n=m+2;
	}
	solve();
	while (!a[n])
		n--;
	printf("%d\n",n+1);
	for (int i=0;i<=n;i++)
		printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}
