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
const int maxn= 2e6;
int n,ans=1e7;
void solve(int n,int o){
	int p=1,x=n;
	for (int i=2;i*i<=n;i++)
		if (x%i==0){
			p=i;
			while (x%i==0)
				x/=i;
		}
	if (x!=1)
		p=x;
	if (p==n)
		return;
	if (o==1){
		ans=min(ans,n-p+1);
		return;
	}else{
		for (int j=n-p+1;j<=n;j++)
			solve(j,o-1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	solve(n,2);
	printf("%d",ans);
	return 0;
}
