#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5;
int a[maxn];
int n,K,i,j,x,y,z,p,cnt,l,r,M;
bool rich(int m){
	int i,sum= 0;
	for (i= 1;i<=n;i++)
		if (a[i]>m){
			sum+= a[i]-m;
			if (sum>K) return 0;
		}
	return 1;
}
bool poor(int m){
	int i,sum= 0;
	for (i= 1;i<=n;i++)
		if (a[i]<m){
			sum+= m-a[i];
			if (sum>cnt) return 0;
		}
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &K);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		M= max(M,a[i]);
	}
	l= -1;r= M;
	while (l+1<r){
		int m= (l+r)>>1;
		if (rich(m)) r= m;
		else l= m;
	}
	for (i= 1;i<=n;i++)
		if (a[i]>r){
			cnt+= a[i]-r;
			a[i]= r;
		}
	if (r&&K>cnt)
		for (i= 1;i<=n;i++)
			if (a[i]>r-1){
				cnt++;
				a[i]--;
				if (K==cnt) break;
			}
	l= 0,r= M+1;
	while (l+1<r){
		int m= (l+r)>>1;
		if (poor(m)) l= m;
		else r= m;
	}
	for (i= 1;i<=n;i++)
		if (a[i]<l){
			cnt-= l-a[i];
			a[i]= l;
		}
	if (cnt)
		for (i= 1;i<=n;i++)
			if (a[i]<l+1){
				a[i]++;
				cnt--;
				if (!cnt) break;
			}
	sort(a+1,a+n+1);
	printf("%d",a[n]-a[1]);
	return 0;
}
