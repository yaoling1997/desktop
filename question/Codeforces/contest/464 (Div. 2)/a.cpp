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
int f[maxn];
int n,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		f[i]=x;
	}
	for (int i=1;i<=n;i++)
		if (f[f[f[i]]]==i){
			printf("YES");
			return 0;
		}
	printf("NO");
	return 0;
}
