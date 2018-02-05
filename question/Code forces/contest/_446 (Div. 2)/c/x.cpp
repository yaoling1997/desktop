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
int a[maxn];
int n,i,j,cnt,now;
int gcd(int a,int b){
	if (!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==1){
			cnt++;
		}
	}
	int ans=-1;
	if (cnt){
		ans=n-cnt;
	}else {
		for (i=1;i<=n;i++){
			now=a[i];
			for (j=i+1;j<=n;j++){
				now= gcd(now,a[j]);
				if (now==1)
					break;
			}
			if (now!=1)
				continue;
			if (ans==-1)
				ans= j-i+n-1;
			else
				ans= min(ans,j-i+n-1);
		}
	}
	printf("%d",ans);
	return 0;
}
