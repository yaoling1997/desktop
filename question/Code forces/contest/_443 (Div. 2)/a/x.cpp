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
int s,d;
int n,i,now= 0;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&s, &d);
		int k= 0;
		if (now-s>=0)
			k= (now-s)/d+1;
		now= s+k*d;
	}
	printf("%d",now);
	return 0;
}
