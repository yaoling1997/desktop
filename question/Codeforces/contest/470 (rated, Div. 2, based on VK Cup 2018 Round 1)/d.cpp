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
const int maxn= 5e5,M=30,maxm=maxn*M;
struct node{
	int v;
	int ch[2];
}a[maxm];
int tmp[50];
int A[maxn],ans[maxn];
int tot,n,now;
bool ok(int o){
	return o!=0&&a[o].v;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for (int tt=1;tt<=n;tt++){
		int x;
		scanf("%d",&x);
		for (int i=0;i<M;i++){
			tmp[i]=x&1;
			x>>=1;
		}
		now=0;
		a[now].v++;
		for (int i=M-1;i>=0;i--){
			x=tmp[i];
			if (!a[now].ch[x])
				a[now].ch[x]=++tot;
			now=a[now].ch[x];
			a[now].v++;
		}
	}
	for (int tt=1;tt<=n;tt++){
		int x=A[tt],cnt=0;
		for (int i=0;i<M;i++){
			tmp[i]=x&1;
			x>>=1;
		}
		now=0;
		a[now].v--;
		for (int i=M-1;i>=0;i--){
			x=tmp[i];
			if (!ok(a[now].ch[x]))
				x^=1;
			cnt=cnt*2+x;
			now=a[now].ch[x];
			a[now].v--;
		}
		ans[tt]=cnt;
	}
	for (int i=1;i<=n;i++)
		printf("%d%c",ans[i]^A[i],i<n?' ':'\n');
	return 0;
}
