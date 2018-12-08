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
int n,now;
int a[maxn];
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",n+1);
	for (int i=n-1;i>=0;i--){
		int z=i-(a[i]+now)%n;
		if (z<0)
			z+=n;
		printf("%d %d %d\n",1,i+1,z);
		now+=z;
	}
	printf("%d %d %d\n",2,n,n);
}
