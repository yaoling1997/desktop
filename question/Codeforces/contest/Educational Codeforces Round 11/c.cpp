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
int n,i,j,K,sum,ans,p,q;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &K);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+= a[i];
	}
	if (sum+K>=n){
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%d%c",1, i<n?' ':'\n');
	}else {
		j= 1;
		for (i= 1;i<=n;i++){
			while (j<=n){
				if (a[j]) j++;
				else if (K)
					j++,K--;
				else break;
			}
			if (j-i>ans){
				ans= j-i;
				p= i;
				q= j-1;
			}
			if (a[i]==0) K++;
		}
		for (i= p;i<=q;i++)
			a[i]= 1;
		printf("%d\n",ans);
		for (i= 1;i<=n;i++)
			printf("%d%c",a[i], i<n?' ':'\n');
	}return 0;
}
