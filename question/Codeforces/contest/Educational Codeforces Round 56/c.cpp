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
ll a[maxn];
int n;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n/2;i++){
		ll x;
		scanf("%I64d",&x);
		if (i==1){
			a[1]=0;
			a[n]=x;
		}else {
			a[i]=a[i-1];
			a[n-i+1]=x-a[i];
			if (a[n-i+1]>a[n-i+2]){
				a[i]+=a[n-i+1]-a[n-i+2];
				a[n-i+1]=a[n-i+2];
			}
		}
	}
	for (int i=1;i<=n;i++)
		printf("%I64d%c",a[i],i<n?' ':'\n');
	return 0;
}
