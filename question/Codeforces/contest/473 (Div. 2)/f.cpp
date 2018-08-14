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
const int maxn= 5e5,maxm=2e6,mo=1e9+7;
struct node{
	int l,x;
}Q[maxn];
int vis[maxm],sta[maxm];
int per[maxn],a[maxn],ans[maxn];
int la,n,q;
bool cmp(int a,int b){
	return Q[a].l<Q[b].l;
}
void solve(){
	vis[0]=1;
	int now=1,p=0;
	sta[la=1]=0;
	for (int i=1;i<=q;i++){
		int l=Q[per[i]].l,x=Q[per[i]].x;
		while (p<l){
			p++;
			if (vis[a[p]])
				now=now*2%mo;
			else {
				int tmp=la;
				for (int j=1;j<=tmp;j++){
					vis[sta[j]^a[p]]=1;
					sta[++la]=sta[j]^a[p];
				}
			}
		}
		ans[per[i]]=vis[x]?now:0;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &q);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		Q[i]=(node){x,y};
		per[i]=i;
	}
	sort(per+1,per+q+1,cmp);
	solve();
	for (int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
