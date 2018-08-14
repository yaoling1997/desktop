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
int n,x;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &x);
	for (int i= 1;i<=n;i++){
		int a;
		scanf("%d",&a);
		x-= a;
	}
	x-= n-1;
	if (x==0)
		printf("YES");
	else
		printf("NO");
	return 0;
}
