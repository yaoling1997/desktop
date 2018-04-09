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
const int maxn= 5e5,maxm=2e6;
int vis[maxm+10];
int sta[maxn];
int ans[maxn];
int a[maxn],b[maxn];
int la,lb;
int n;
void init(){
	vis[0]=vis[1]=1;
	for (int i=2;i<=maxm;i++)
		if (!vis[i]){
			sta[++la]=i;
			for (ll p=(ll)i*i;p<=maxm;p+=i)
				vis[p]=1;										
		}
}
bool ok(int x){
	lb=0;
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			b[++lb]=i;
			while (x%i==0){
				x/=i;
			}
		}
	if (x!=1)
		b[++lb]=x;
	for (int i=1;i<=lb;i++)
		if (vis[b[i]])
			return 0;
	return 1;
}
void solve(){
	//memset(vis,0,sizeof(vis));
	int p=1;
	for (;p<=n;p++)
		if (ok(a[p])){
			for (int i=1;i<=lb;i++)
				vis[b[i]]=1;
			ans[p]=a[p];
		}else break;
	if (p>n)
		return;
	for (int i=a[p]+1;;i++)
		if (ok(i)){
			for (int i=1;i<=lb;i++)
				vis[b[i]]=1;
			ans[p]=i;
			p++;
			break;
		}
	int q=1;
	for (;p<=n;p++){
		while (q<=la){
			if (!vis[sta[q]]){
				ans[p]=sta[q];
				q++;
				break;
			}
			q++;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	init();
	solve();
	for (int i=1;i<=n;i++)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}
