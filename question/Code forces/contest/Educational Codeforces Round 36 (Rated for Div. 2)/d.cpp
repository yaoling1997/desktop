#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
queue<int> Q;
int nex[maxn],des[maxn],h[maxn],d[maxn],D[maxn],sta[maxn];
int n,m,tot,la,bl;
void addedge(int u,int v){
	nex[++tot]=h[u];
	des[tot]=v;
	h[u]=tot;
}
void topu(){
	for (int i=1;i<=n;i++)
		if (!d[i])
			Q.push(i);
	while (!Q.empty()){
		int u=Q.front();
		Q.pop();
		for (int i=h[u];i;i=nex[i]){
			int v=des[i];
			d[v]--;
			if (!d[v])
				Q.push(v);
		}
	}
}
bool check(int o){
	for (int i=1;i<=n;i++)
		D[i]=d[i];
	Q.push(o);
	D[o]=0;
	while (!Q.empty()){
		int u=Q.front();
		Q.pop();
		for (int i=h[u];i;i=nex[i]){
			int v=des[i];
			D[v]--;
			if (!D[v])
				Q.push(v);
		}
	}
	for (int i=1;i<=n;i++)
		if (D[i]>0)
			return false;
	return true;
}
bool solve(){
	la=0;
	for (int i=1;i<=n;i++){
		D[i]=d[i];
		if (d[i])
			sta[++la]=i;
	}
	if (!la){
		return true;
	}
	for (int i=1;i<=la;i++)
		if (d[sta[i]]==1){
			if (check(sta[i]))
				return true;
		}
	return false;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		addedge(x,y);
		d[y]++;
	}
	topu();
	bl= solve();
	printf("%s",bl?"YES":"NO");
	return 0;
}
