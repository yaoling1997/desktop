#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5+10,maxm= 3e7;
vector<int> g[maxn];
int c[maxn],f[maxn],size[maxn],a[maxn],b[maxn];
char ch[maxm],s[maxn];
int head[maxm],next[maxm];
int tot,n,i,x,y,ans;
void get(int o,int fa,int now,int &cnt){
	int i,bl= 0;
	for (i= head[now];i;i= next[i])
		if (ch[i]==s[o]){
			bl= 1;
			break;
		}
	if (bl) now= i;
	else {
		next[++tot]= head[now];
		head[now]= tot;
		ch[tot]= s[o];
		now= tot;
		cnt++;
	}
	int len= g[o].size();
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		get(v,o,now,cnt);
	}
}
void dfs(int o,int fa){
	int len= g[o].size(),i,p= 0,&cnt= f[o];
	size[o]= 1;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
		if (p==0||size[v]>size[p])
			p= v;
		size[o]+= size[v];
	}
	a[o]= ++tot;
	ch[tot]= s[o];
	cnt= 1;
	if (p){
		head[tot]= a[p];
		cnt+= f[p];
		for (i= 0;i<len;i++){
			int v= g[o][i];
			if (v==fa||v==p) continue;
			get(v,o,a[o],cnt);
		}
	}
}
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	scanf("%s",s+1);
	for (i= 1;i<n;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for (i= 1;i<=n;i++)
		b[i]= f[i]+c[i];
	sort(b+1,b+n+1);
	ans= 1;
	for (i= n-1;i>0;i--)
		if (b[i]==b[i+1])
			ans++;
		else break;
	printf("%d\n",b[n]);
	printf("%d\n",ans);
	return 0;
}
