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
const int maxn= 5e5;
int a[maxn],t[maxn],s[maxn];
int n,k,M,sum;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		s[i]=s[i-1];
		if (!t[i])
			s[i]+=a[i];
		else
			sum+=a[i];
	}
	for (int i=1;i+k-1<=n;i++)
		M=max(M,sum+s[i+k-1]-s[i-1]);
	printf("%d",M);
	return 0;
}
