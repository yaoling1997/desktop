#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 1050,maxm= 3e6;
struct node{
	ll x,y,z;
}P[maxm];
struct point{
	ll x,y;
}move[4],Y[maxm];
queue<point> Q;
ll a[maxn][maxn],X[maxn][maxn],M[maxn][maxn];
ll ans[maxn][maxn],vis[maxn][maxn];
ll f[maxm],N[maxm];
ll n,m,K,i,j,tot,cnt,bl;
ll find(ll o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
bool cmp(node a,node b){
	return a.z<b.z;
}
void get(ll x,ll y,ll bl,ll S){
	ll cnt= 1;	
	ans[x][y]= S;
	Q.push((point){x,y});
	vis[x][y]= 1;
	if (cnt==bl) return;
	while (!Q.empty()){
		point u= Q.front();
		Q.pop();
		for (ll i= 0;i<4;i++){
			ll xx= u.x+move[i].x;
			ll yy= u.y+move[i].y;
			if (M[xx][yy]&&!vis[xx][yy]){
				vis[xx][yy]= 1;
				cnt++;
				ans[xx][yy]= S;
				Q.push((point){xx,yy});
				if (cnt==bl) return;
			}
		}
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d%I64d",&n, &m, &K);
	move[0]= (point){-1,0};
	move[1]= (point){0,1};
	move[2]= (point){1,0};
	move[3]= (point){0,-1};
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			scanf("%I64d",&a[i][j]);
			X[i][j]= ++tot;
			Y[tot]= (point){i,j};
			f[tot]= tot;
			P[tot]= (node){i,j,a[i][j]};
		}
	sort(P+1,P+tot+1,cmp);
	for (i= tot;i>0;i--){
		ll x= P[i].x,y= P[i].y,z= P[i].z;
		M[x][y]= 1;
		N[X[x][y]]= 1;
		ll u= X[x][y];
		for (j= 0;j<4;j++){
			ll xx= x+move[j].x,yy= y+move[j].y;
			if (M[xx][yy]){
				ll v= find(X[xx][yy]);
				if (v==u) continue;
				f[v]= u;
				N[u]+= N[v];
			}
		}
		if (N[u]*z>=K&&K%z==0){
			bl= 1;
			get(x,y,K/z,z);
			break;
		}
	}
	if (bl){
		printf("YES\n");
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				printf("%I64d%c",ans[i][j],j<m?' ':'\n');
	}else {
		printf("NO\n");
	}return 0;
}