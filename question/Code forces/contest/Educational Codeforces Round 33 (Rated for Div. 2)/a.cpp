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
int n,x,y,z;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	x=1;
	y=2;
	z=3;
	for (int i=1;i<=n;i++){
		int c;
		scanf("%d",&c);
		if (c==x)
			swap(y,z);
		else if (c==y)
			swap(x,z);
		else {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
