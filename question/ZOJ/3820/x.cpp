#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 2e5+1e4,oo= 1e8;
struct node{
	int v,fa,s;
};
vector<int> g[maxn];
queue<node> Q;
int sta[maxn],f[maxn],p[maxn],vis[maxn],d[maxn];
int ans[3];
int x,y,n,i,u,v,la,L,fx,fy,xy,x1,x2,y1,y2,now,X,Y,T;
void init(){
	int i;
	for (i= 1;i<=n;i++)
		g[i].clear();
}
void bfs(int s,int &re){
	while (!Q.empty()) Q.pop();
	L= -1;
	Q.push((node){s,0,0});
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		if (u.s>L){
			L= u.s;
			re= u.v;
		}
		int len= g[u.v].size(),i;
		for (i= 0;i<len;i++){
			int v= g[u.v][i];
			if (v==u.fa) continue;
			Q.push((node){v,u.v,u.s+1});
		}
	}
}
void get_diameter(int x,int y){
	while (!Q.empty()) Q.pop();
	Q.push((node){x,0,0});
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		int len= g[u.v].size(),i;
		for (i= 0;i<len;i++){
			int v= g[u.v][i];
			if (v==u.fa) continue;
			p[v]= u.v;
			Q.push((node){v,u.v,0});
		}
	}
	int u= y;
	sta[la= 1]= u;
	while (u!=x){
		u= p[u];
		sta[++la]= u;
	}
}
void get_f(){
	memset(vis,0,sizeof(vis));
	while (!Q.empty()) Q.pop();
	for (i= 1;i<=n;i++){
		f[i]= 0;
		if ((int)g[i].size()==1){
			Q.push((node){i,0,0});
			vis[i]= 1;
		}
		d[i]= g[i].size()-1;
	}
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		int len= g[u.v].size(),i;
		for (i= 0;i<len;i++){
			int v= g[u.v][i];
			if (vis[v]) continue;
			d[v]--;
			f[v]= max(f[v],f[u.v]+1);
			if (!d[v]){
				vis[v]= 1;
				Q.push((node){v,0,0});
			}
		}
	}
}
void get_next(int o,int &x1,int &x2,int fa){
	x1= x2= 0;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		if (f[v]>f[x1]){
			x2= x1;
			x1= v;
		}else if (f[v]>f[x2])
			x2= v;
	}
}
void update(){
	if (ans[0]>now){
		ans[0]= now;
		ans[1]= min(x,y);
		ans[2]= max(x,y);
	}
}
int max(int x1,int x2,int x3,int x4,int x5){
	x1= max(x1,x2);
	x1= max(x1,x3);
	x1= max(x1,x4);
	x1= max(x1,x5);
	return x1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for (int TT= 1;TT<=T;TT++){
		scanf("%d",&n);
		init();
		f[0]= -2;
		for (i= 1;i<n;i++){
			scanf("%d%d",&x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		u= v= 1;
		bfs(1,u);
		bfs(u,v);
		get_diameter(u,v);
		x= sta[la/2];
		y= sta[la/2+1];
		fx= 0;
		fy= x;
		xy= 1;
		get_f();
		get_next(x,x1,x2,y);
		get_next(y,y1,y2,fy);
		ans[0]= oo;
		now= max(0,f[x1]+1,f[y1]+1,-oo,-oo);
		update();
		X= Y= 0;
		while (now<=ans[0]&&x1+x2+y1+y2>0){
			xy++;
			if (f[x1]>f[y1]){
				X= max(X+1,f[x2]+2);
				fx= x;
				x= x1;
				get_next(x,x1,x2,fx);
			}else {
				Y= max(Y+1,f[y2]+2);
				fy= y;
				y= y1;
				get_next(y,y1,y2,fy);
			}
			now= max(xy/2,X,Y,f[x1]+1,f[y1]+1);
			update();
		}
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		//printf("%d\n",ans[0]);
	}
	return 0;
}
