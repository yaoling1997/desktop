#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 80000,oo= 1e8;
struct node *null;
struct node{
	node *ch[2];
	int v,r,s,v2,v3,b,b2;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){
		s= ch[0]->s+ch[1]->s+1;
		v3= v2;b2= b;
		for (int i= 0;i<=1;i++)
			if (v3>ch[i]->v3)
				v3= ch[i]->v3,b2= ch[i]->b2;
	}
	node(int x,int y,int z):v(x),r(rand()),s(0),v2(y),v3(oo),b(z),b2(z){
		ch[0]= ch[1]= null;
	}
};
struct point{
	int x,y,b;
	ll d;
};
struct edge{
	int u,v,d;
	bool operator <(const edge &a)const{
		return d<a.d;
	}
};
vector<int> g[maxn];
point p[maxn];
edge l[10*maxn];
int b[maxn],f[maxn],use[10*maxn];
int a[maxn],stack[maxn],X[maxn];
node *root;
ll c[maxn];
ll sum;
int n,i,top,ans,m;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x,int y,int z){
	if (o==null) o= new node(x,y,z);
	else {
		int d= o->cmp(x);
		if (d==-1) d= 1;
		insert(o->ch[d],x,y,z);
		if (o->ch[d]->r>o->r) rotate(o,d^1);
	}o->mt();
}
int find(node *o,int x,int opt){
	node *p= o;int re= 0,s= oo;
	while (p!=null){
		int d= p->cmp(x);
		if (d==-1) d= opt;
		if (d==opt){
			if (s>p->v2){
				s= p->v2;
				re= p->b;
			}
			if (s>p->ch[d^1]->v3){
				s= p->ch[d^1]->v3;
				re= p->ch[d^1]->b2;
			}
		}p= p->ch[d];
	}return re;
}
void addedge(point a,point b){
	int d= abs(a.x-b.x)+abs(a.y-b.y);
	int x= a.b,y= b.b;
	if (x>y) swap(x,y);
	l[++top]= (edge){x,y,d};
}
bool cmp(point a,point b){
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool cmp1(point a,point b){
	return a.b<b.b;
}
void getedges(){
	int i,k,b1;
	for (k= 1;k<=4;k++){
		root= null;
		sort(p+1,p+n+1,cmp);
		for (i= 1;i<=n;i++)
			b[p[i].b]= i;
		for (i= n;i>0;i--){
			b1= find(root,p[i].x-p[i].y,1);
			if (b1) addedge(p[i],p[b[b1]]);
			insert(root,p[i].x-p[i].y,p[i].x+p[i].y,p[i].b);
		}
		if (k==1){
			for (i= 1;i<=n;i++)
				swap(p[i].x,p[i].y);
		}else if (k==2){
			for (i= 1;i<=n;i++)
				p[i].y*= -1;
		}else if (k==3){
			for (i= 1;i<=n;i++){
				p[i].y*= -1,p[i].x*= -1;
				swap(p[i].x,p[i].y);
			}
		}else {
			for (i= 1;i<=n;i++){
				p[i].y*= -1;
			}
		}
	}
}
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
int kruskal(){
	int i,re= 0,cnt= 0;
	sort(l+1,l+top+1);
	for (i= 1;i<=n;i++)
		f[i]= i;
	for (i= 1;i<=top;i++){
		int u= l[i].u,v= l[i].v;
		if (find(u)!=find(v)){
			f[f[u]]= f[v];
			re+= l[i].d;
			g[l[i].u].push_back(l[i].v);
			g[l[i].v].push_back(l[i].u);
			cnt++;
			if (cnt==n-1) break;
		}
	}return re;
}
int gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
void dfs(int o,int fa){
	int i,len= g[o].size(),L,R;
	ll ans= p[fa].d;
	L= min(p[o].x,p[fa].x);R= max(p[o].x,p[fa].x);
	if (p[fa].x>p[o].x){
		for (i= L;i<R;i++){
			ans-= c[b[a[i]]];
			b[a[i]]++;
			ans+= c[b[a[i]]];
		}
	}else {
		for (i= L;i<R;i++){
			ans-= c[b[a[i]]];
			b[a[i]]--;
			ans+= c[b[a[i]]];
		}
	}
	L= min(p[o].y,p[fa].y);R= max(p[o].y,p[fa].y);
	if (p[fa].y<p[o].y){
		for (i= L+1;i<=R;i++){
			ans-= c[b[a[i]]];
			b[a[i]]++;
			ans+= c[b[a[i]]];
		}
	}else {
		for (i= L+1;i<=R;i++){
			ans-= c[b[a[i]]];
			b[a[i]]--;
			ans+= c[b[a[i]]];
		}
	}
	p[o].d= ans;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v!=fa)
			dfs(v,o);
	}
	L= min(p[o].x,p[fa].x);R= max(p[o].x,p[fa].x);
	if (p[fa].x>p[o].x){
		for (i= L;i<R;i++){
			b[a[i]]--;
		}
	}else {
		for (i= L;i<R;i++){
			b[a[i]]++;
		}
	}
	L= min(p[o].y,p[fa].y);R= max(p[o].y,p[fa].y);
	if (p[fa].y<p[o].y){
		for (i= L+1;i<=R;i++){
			b[a[i]]--;
		}
	}else {
		for (i= L+1;i<=R;i++){
			b[a[i]]++;
		}
	}	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	root= null= new node(0,0,0);
	scanf("%d %d",&m, &n);
	for (i= 1;i<=m;i++)
		c[i]= (ll)i*(i-1)/2;
	for (i= 1;i<=m;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=n;i++){
		scanf("%d %d",&p[i].x, &p[i].y);
		p[i].b= i;
	}
	getedges();
	kruskal();
	sort(p+1,p+n+1,cmp1);
	memset(b,0,sizeof(b));
	for (i= p[1].x;i<=p[1].y;i++){
		p[1].d-= c[b[a[i]]];
		b[a[i]]++;p[1].d+= c[b[a[i]]];
	}
	int len= g[1].size();
	for (i= 0;i<len;i++){
		int v= g[1][i];
		dfs(v,1);
	}
	for (i= 1;i<=n;i++){
		ll x= p[i].x,y= p[i].y;
		ll z= gcd(p[i].d,c[y-x+1]);
		printf("%lld/%lld\n",p[i].d/z,c[y-x+1]/z);
	}
	return 0;
}
