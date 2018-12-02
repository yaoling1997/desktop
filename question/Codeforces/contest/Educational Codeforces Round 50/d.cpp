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
int a[maxn],b[maxn];
ll sa,sb;
int n,m,ans;
int solve(){
	if (sa!=sb)
		return -1;
	int p=1,q=1,re=0;
	sa=sb=0;
	while (p<=n||q<=m){
		if (sa<=sb)
			sa+=a[p++];			
		else
			sb+=b[q++];
		if (sa==sb){
			re++;
		}
	}
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
		sa+=a[i];
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d",b+i);
		sb+=b[i];
	}
	ans= solve();
	printf("%d",ans);
	return 0;
}
