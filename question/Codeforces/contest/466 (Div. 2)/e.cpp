#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
multiset<int> S;
int a[maxn];
ll f[maxn];
ll sum;
int n,c;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &c);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]=x;
		f[i]=f[i-1]+x;
		sum+=x;
		S.insert(x);
		if (i>=c){
			f[i]=min(f[i],f[i-c]+sum-*S.begin());
			sum-=a[i-c+1];
			S.erase(S.find(a[i-c+1]));
		}
	}
	printf("%I64d",f[n]);
	return 0;
}
