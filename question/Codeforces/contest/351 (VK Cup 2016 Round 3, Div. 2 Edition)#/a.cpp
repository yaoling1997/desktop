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
int a[maxn],b[maxn];
int n,now,i,x,cnt;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		b[x]= 1;
	}
	for (i= 1;i<=90;i++)
		if (b[i]) cnt= 0;
		else{
			cnt++;
			if (cnt==15) break;
		}
	i= min(i,90);
	printf("%d",i);
	return 0;
}