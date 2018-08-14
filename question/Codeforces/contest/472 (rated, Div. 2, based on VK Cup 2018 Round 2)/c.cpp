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
int E[maxn];
int n,U;
int bl;
double ans;
void solve(){
	int j=1;
	for (int i=1;i<=n;i++){
		while (j<=n&&E[j]-E[i]<=U){
			j++;
		}
		int k=j-1;
		if (k-i>1){
			bl=1;
			ans=max(ans,(double)(E[k]-E[i+1])/(E[k]-E[i]));
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &U);
	for (int i=1;i<=n;i++){
		scanf("%d",&E[i]);
	}
	solve();
	if (bl)
		printf("%.10f",ans);
	else
		printf("-1");
	return 0;
}
