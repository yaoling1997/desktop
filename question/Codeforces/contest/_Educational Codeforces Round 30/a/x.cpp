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
int n,k,x,sum;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &k, &x);
	for (int i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+= a[i];
	}
	for (int i= n;i>0;i--)
		if (a[i]>x){
			k--;
			sum= sum-a[i]+x;
			if (!k)
				break;
		}
	printf("%d",sum);
	return 0;
}
