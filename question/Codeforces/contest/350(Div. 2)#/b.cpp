#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int id[maxn];
int n,K,i;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &K);
	for (i= 1;i<=n;i++)
		scanf("%d",&id[i]);
	for (i= 1;i<=n;i++)
		if (K>i) K-= i;
		else {
			printf("%d",id[K]);
			break;
		}
	return 0;
}