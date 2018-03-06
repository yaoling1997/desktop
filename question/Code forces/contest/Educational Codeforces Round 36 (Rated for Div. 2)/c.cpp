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
int a[20],b[20];
ll x,ans;
int la,lb;
void update(ll now){
	for (int i=9;i>=0;i--)
		for (int j=1;j<=a[i];j++)
			now=now*10+i;
	ans= max(ans,now);
}
void solve(){
	if (la<lb){
		for (int i=9;i>=0;i--)
			while (a[i]){
				a[i]--;
				printf("%d",i);
			}
		return;
	}
	ll now=0;
	for (int i=lb-1;i>=0;i--){
		for (int j=b[i]-1;j>=0;j--)
			if (a[j]){
				a[j]--;
				update(now*10+j);
				a[j]++;
				break;
			}
		if (a[b[i]]){
			a[b[i]]--;
			now=now*10+b[i];
		}else
			break;
	}
	if (now>ans)
		ans= now;
	printf("%I64d",ans);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d",&x);
	while (x){
		a[x%10]++;
		la++;
		x/=10;
	}
	scanf("%I64d",&x);
	while (x){
		b[lb++]=x%10;
		x/=10;
	}
	solve();
	return 0;
}
