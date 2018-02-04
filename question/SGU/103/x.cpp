#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 400,oo= 1e8;
struct junc{
	int c,r,t[2];
}J[maxn];
struct edge{
	int v,c;
};
struct node{
	int v,t;
	bool operator <(const node &a)const{
		return t>a.t;
	}
};
priority_queue<node> Q;
vector<edge> g[maxn];
char S[10];
int done[maxn],ans[maxn],p[maxn],d[maxn];
int s,t,n,m,x,y,z,xx,now,i;
junc getnow(junc u,int t){
	if (t<u.r) u.r-= t;
	else {
		t-= u.r;
		u.c^= 1;
		u.r= u.t[u.c];
		t%= u.t[0]+u.t[1];
		if (t<u.t[u.c]) u.r-= t;
		else {
			t-= u.t[u.c];
			u.c^= 1;
			u.r= u.t[u.c]-t;			
		}
	}return u;
}
int get(int u,int v,int s,int t){
	int re= s;
	junc U,V;
	U= getnow(J[u],t);
	V= getnow(J[v],t);
	if (U.c==V.c) return re;
	if (U.r==V.r){
		re+= U.r;
		U.c^= 1;
		V.c^= 1;
		U.r= U.t[U.c];
		V.r= V.t[V.c];
		if (U.r==V.r){
			re+= U.r;
			U.c^= 1;
			V.c^= 1;
			U.r= U.t[U.c];
			V.r= V.t[V.c];
			if (U.r==V.r) re= oo;
			else re+= min(U.r,V.r);
		}else re+= min(U.r,V.r);
	}else re+= min(U.r,V.r);
	return re;
}
void go(){
	d[s]= 0;
	Q.push((node){s,0});
	while (!Q.empty()){
		node u= Q.top();
		int len= g[u.v].size(),i;
		Q.pop();
		if (done[u.v]) continue;
		done[u.v]= 1;
		ans[u.v]= u.t;
		if (u.v==t) break;
		for (i= 0;i<len;i++){
			edge e= g[u.v][i];
			if (done[e.v]) continue;
			int re= get(u.v,e.v,e.c,u.t);
			if (re>=oo) continue;
			if (d[e.v]>u.t+re){
				d[e.v]= u.t+re;
				p[e.v]= u.v;
				Q.push((node){e.v,d[e.v]});
			}
		}
	}
}
void print(int o){
	if (!o) return;
	print(p[o]);
	printf("%d%c",o, o!=t?' ':'\n');
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d%d",&s, &t, &n, &m);
	for (i= 1;i<=n;i++){
		scanf("%s%d%d%d",S+1, &x, &y, &z);
		int xx= S[1]=='P';
		J[i]= (junc){xx,x,y,z};
		d[i]= oo;
	}
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		g[x].push_back((edge){y,z});
		g[y].push_back((edge){x,z});
	}
	go();
	if (done[t]){
		printf("%d\n",ans[t]);
		print(t);
	}else printf("0");
	return 0;
}
