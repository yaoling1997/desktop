#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll maxn= 1e6+10;
vector<ll> g[maxn];
ll ok[maxn],val[maxn],f[maxn][2],mx[maxn],stack[maxn],vis[maxn];
ll F[maxn],G[maxn],next[maxn];
ll x,y,i,j,k,n,top,bl,B,now,ans,time,cnt;
void getcircle(int o){
	vis[o]= time;int v= next[o];
	if (!vis[v]){
		getcircle(v);
		if (bl){
			if (B){
				stack[++top]= o;
				ok[o]= 1;
				if (o==B) B= 0;
			}
		}
	}else if (vis[v]==time){
		bl= 1;B= v;
		stack[++top]= o;
		ok[o]= 1;
	}
}
void dfs(ll o,ll fa){
	ll len= g[o].size(),i;
	f[o][0]= val[o];
	for (i= 0;i<len;i++){
		ll v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
		f[o][1]+= mx[v];
		f[o][0]+= f[v][1];
	}mx[o]= max(f[o][0],f[o][1]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld %lld",&x, &y);
		val[i]= x;
		next[i]= y;
		g[i].push_back(y);
		g[y].push_back(i);
	}
	for (k= 1;k<=n;k++)
		if (!vis[k]){
			time++;
			getcircle(k);
			if (bl){
				cnt= 0;
				for (i= 1;i<=top;i++){
					ll u= stack[i];
					F[u]= G[u]= 0;
				}
				for (i= 1;i<=top;i++){
					ll u= stack[i],len= g[u].size();
					f[u][0]= val[u];
					for (j= 0;j<len;j++){
						ll v= g[u][j];
						if (ok[v]) continue;
						dfs(v,u);
						f[u][1]+= mx[v];
						f[u][0]+= f[v][1];
					}mx[u]= max(f[u][0],f[u][1]);
				}
				now= f[stack[1]][0]+f[stack[top]][1];
				if (top>2)
					now+= f[stack[2]][1];
				for (i= 3;i<top;i++){
					ll u= stack[i],v= stack[i-1];
					F[u]= f[u][0]+G[v];
					G[u]= f[u][1]+max(G[v],F[v]);
				}if (top>2)
					 now+= max(F[stack[top-1]],G[stack[top-1]]);
				cnt= now;
				for (i= 1;i<=top;i++){
					ll u= stack[i];
					F[u]= G[u]= 0;
				}
				now= f[stack[1]][1];
				for (i= 2;i<=top;i++){
					ll u= stack[i],v= stack[i-1];
					F[u]= f[u][0]+G[v];
					G[u]= f[u][1]+max(G[v],F[v]);		
				}
				now+= max(F[stack[top]],G[stack[top]]);
				cnt= max(cnt,now);
				ans+= cnt;bl= top= 0;
			}
		}
	printf("%lld\n",ans);
	return 0;
}
