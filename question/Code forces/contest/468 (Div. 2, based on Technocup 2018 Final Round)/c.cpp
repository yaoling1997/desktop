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
const int maxn= 5e5,oo=1e9;
int a[maxn];
int n,Min=oo,Max=-oo,ans;
void solve(){
	if (a[n]-a[1]<2)
		return;
	int MinNum=0,MaxNum=0,MiddleNum=0;
	for (int i=1;i<=n;i++)
		if (a[i]==Min)
			MinNum++;
		else if (a[i]==Max)
			MaxNum++;
		else MiddleNum++;
	if (min(MinNum,MaxNum)>MiddleNum/2){
		for (int i=1;i<n-i+1;i++)
			if (a[i]==Min&&a[n-i+1]==Max)
				a[i]=a[n-i+1]=Min+1;
			else break;
		ans= 2*min(MinNum,MaxNum);
	}else {
		for (int i=1;i<n;i++)
			if (a[i]==Min+1&&a[i+1]==Min+1){
				a[i]=Min;
				a[i+1]=Max;				
			}
		ans= MiddleNum/2*2;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		Min=min(Min,a[i]);
		Max=max(Max,a[i]);
	}
	sort(a+1,a+n+1);
	solve();
	printf("%d\n",n-ans);
	for (int i=1;i<=n;i++)
		printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}
