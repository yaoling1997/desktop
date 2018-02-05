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
int a[maxn];
int n,i,sum,la;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i= 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (x==0)
			continue;
		sum+= x;
		if (sum==0){
			a[++la]= i;
			sum= x;
		}
	}
	a[0]= 1;
	a[++la]= n+1;
	if (sum==0){
		printf("NO");
	}else {
		printf("YES\n");
		printf("%d\n",la);
		for (i= 1;i<=la;i++)
			printf("%d %d\n",a[i-1],a[i]-1);
	}
	return 0;
}
