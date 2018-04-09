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
int per[maxn];
vector<int> Z,F;
double a[maxn],t[maxn];
double ans,ZT,FT;
int n,T;
void solve(){
	ans=0;
	double NT=min(ZT,FT);
	double now=0;
	for (int i=0;i<(int)Z.size();i++){
		int u=Z[i];
		if ((t[u]-T)*a[u]+now<=NT){
			now+=(t[u]-T)*a[u];
			ans+=a[u];
		}else {
			ans+=(NT-now)/(t[u]-T);
			now=NT;
		}
	}	
	now=0;
	for (int i=F.size()-1;i>=0;i--){
		int u=F[i];
		if ((T-t[u])*a[u]+now<=NT){
			now+=(T-t[u])*a[u];
			ans+=a[u];
		}else {
			ans+=(NT-now)/(T-t[u]);
			now=NT;
		}
	}	
}
bool cmp(int a,int b){
	return t[a]<t[b];
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &T);
	for (int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%lf",&t[i]);
		per[i]=i;
	}
	sort(per+1,per+n+1,cmp);
	for (int i=1;i<=n;i++)
		if (t[per[i]]<T){
			F.pb(per[i]);
			FT+=abs((t[per[i]]-T)*a[per[i]]);
		}else{
			Z.pb(per[i]);
			ZT+=abs((t[per[i]]-T)*a[per[i]]);
		}
	solve();
	printf("%.10f",ans);
	return 0;
}
