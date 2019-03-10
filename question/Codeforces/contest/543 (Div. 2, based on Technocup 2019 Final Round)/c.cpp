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
const int maxn= 1e3+10;
int a[maxn],p[maxn],t[maxn],vis[maxn];
int n,k,ans;
int solve(){
	int re=0,id=1;
	for (int i=1;i<=k;i++){
		if (i>n)
			break;
		p[i]=i;
		id++;
		t[i]=1;
	}
	int m=0,tt=0,ooo=0;
	for (;;){
		tt++;
		if (tt==49)
			ooo++;
		bool bl=1;
		for (int i=1;i<=k;i++)
			if (p[i]!=0){
				bl=0;
				t[i]++;
				if (t[i]>a[p[i]]){
					if (id<=n){
						p[i]=id;
						id++;
						t[i]=1;
					}else{
						t[i]=p[i]=0;
					}
					m++;					
				}
			}
		int d=100.*m/n+0.5;
		for (int i=1;i<=k;i++)
			if (p[i]!=0){
				if (d==t[i]&&!vis[p[i]]){
					vis[p[i]]=1;
					re++;
				}
			}
		if (bl)
			break;
	}
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans= solve();
	printf("%d",ans);
}
