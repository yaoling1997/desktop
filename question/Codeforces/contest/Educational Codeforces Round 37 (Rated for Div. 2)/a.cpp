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
const int maxn= 5e5,oo=1e9;
int a[maxn];
int n,i,j,k,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		scanf("%d%d",&n, &k);
		ans=0;
		for (int i= 1;i<=k;i++){
			scanf("%d",&a[i]);
			if (i==1){
				ans= max(ans,a[i]);
			}
			if (i==k){
				ans= max(ans,n-a[i]+1);
			}
			if (i>1)
				ans= max(ans,(a[i]-a[i-1]+1+1)/2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
