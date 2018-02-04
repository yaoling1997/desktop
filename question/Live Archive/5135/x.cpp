#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 1e5;
struct edge{
	ll u,v;
}sta[maxn];
vector<ll> g[maxn];
vector<ll> bcc[maxn];
ll bccno[maxn],cut[maxn],low[maxn],pre[maxn];
ll num;
ll n,m,i,x,y,cnt,tim,la,ans,j;
int T;
void init(){
	memset(bccno,0,sizeof(bccno));
	memset(cut,0,sizeof(cut));
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	tim= 0;
	ll i;
	for (i= 1;i<=6e4;i++){
		g[i].clear();
		bcc[i].clear();
	}
	cnt= n= 0;
}
void dfs(ll o,ll fa){
	low[o]= pre[o]= ++tim;
	ll len= g[o].size(),i,child= 0;
	for (i= 0;i<len;i++){
		ll v= g[o][i];
		edge e= (edge){o,v};
		if (!pre[v]){
			sta[++la]= e;
			child++;
			dfs(v,o);
			low[o]= min(low[o],low[v]);
			if (low[v]>=pre[o]){
				cut[o]= 1;
				cnt++;
				for (;;){
					edge x= sta[la--];
					if (bccno[x.u]!=cnt){
						bcc[cnt].push_back(x.u);
						bccno[x.u]= cnt;
					}
					if (bccno[x.v]!=cnt){
						bcc[cnt].push_back(x.v);
						bccno[x.v]= cnt;
					}
					if (x.u==o&&x.v==v) break;
				}
			}
		}else if (pre[v]<pre[o]&&v!=fa){
			low[o]= min(low[o],pre[v]);
			sta[++la]= e;
		}
	}
	if (fa==-1&&child<=1) cut[o]= 0;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	for(;;){
		cin>>m;
		if (!m) break;
		T++;
		init();
		for (i= 1;i<=m;i++){
			cin>>x>>y;
			//scanf("%lld%lld",&x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
			n= max(n,x);
			n= max(n,y);
		}
		for (i= 1;i<=n;i++)
			if (!pre[i])
				dfs(i,-1);
		ans= 0;
		num= 1;
		for (i= 1;i<=cnt;i++){
			ll len= bcc[i].size();
			if (len==1){
				//ans++;
				continue;
			}
			x= 0;
			for (j= 0;j<len;j++){
				ll v= bcc[i][j];
				x+= cut[v];
			}
			if (x==0) num= num*len*(len-1)/2,ans+= 2;
			else if (x==1) num*= len-1,ans++;			
		}
		printf("Case %d: ",T);
		cout<<ans<<' '<<num<<endl;
	}return 0;
}
