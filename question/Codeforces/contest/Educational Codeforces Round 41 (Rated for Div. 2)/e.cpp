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
pair<int,int> b[maxn];
int a[maxn],c[maxn];
int n;
ll ans;
void add(int o,int v){
	while (o<=n){
		c[o]+=v;
		o+=o&-o;
	}
}
int find(int o){
	int re=0;
	while (o){
		re+=c[o];
		o-=o&-o;
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
		scanf("%d",&a[i]);
		a[i]=min(a[i],n);
		b[i]=mp(min(i-1,a[i]),i);
	}
	sort(b+1,b+n+1);
	int lb=n;
	for (int i=n;i>0;i--){
		while (lb&&b[lb].first>=i){
			add(b[lb].second,1);
			lb--;
		}
		if (a[i]>i){
			int re=find(i+a[i]-i)-find(i);
			ans+=re;
		}
	}
	printf("%I64d",ans);
	return 0;
}
