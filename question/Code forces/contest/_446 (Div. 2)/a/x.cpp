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
int a[maxn],b[maxn];
int n;
ll sum;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		sum= sum+a[i];
	}
	for (int i= 1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	printf("%s",b[n]+b[n-1]>=sum?"YES":"NO");
	return 0;
}
