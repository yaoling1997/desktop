#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e3;
struct node{
	int id,party,c;
};
vector<node> V[maxn];
node a[maxn];
int vis[maxn];
ll ans;
int tim,n,m;
ll ok(int mid){
	ll ans=0;
	int cnt=0;
	for (int i=2;i<=m;i++){
		int len=V[i].size();
		if (len>mid)
			for (int j=0;j<len-mid;j++){
				vis[V[i][j].id]=tim;
				ans+=V[i][j].c;
				cnt++;
			}
	}
	if (cnt+(int)V[1].size()>mid)
		return ans;
	for (int i=1;i<=n;i++){
		if (vis[a[i].id]==tim||a[i].party==1)
			continue;
		ans+=a[i].c;
		cnt++;
		if (cnt+(int)V[1].size()>mid)
			break;
	}
	return ans;
}
void solve(){
	ans=3000*1e9+10;
	ll re;
	for (int i=0;i<n;i++){
		tim++;
		re= ok(i);
		ans=min(ans,re);
	}
}
bool cmp(node a,node b){
	return a.c<b.c;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		a[i]=(node){i,x,y};
		V[x].pb(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=m;i++)
		sort(V[i].begin(),V[i].end(),cmp);
	solve();
	cout<<ans;
	return 0;
}
