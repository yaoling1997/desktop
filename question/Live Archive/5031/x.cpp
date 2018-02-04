#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn= 1e6;
struct node *null;
struct node{
	node *ch[2];
	int v,r,s;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){s= ch[0]->s+ch[1]->s+1;}
	node(int x):v(x),r(rand()),s(0){ch[0]= ch[1]= null;}
};
struct edge{
	int u,v;
};
struct query{
	int b,x,y;
};
edge l[maxn];
node *a[maxn];
query Q[maxn];
int b[maxn],c[maxn],f[maxn];
char ch;
double ans;
int i,n,m,tot,x,y,cnt,a1;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null) o= new node(x);
	else {
		int d= o->cmp(x);if (d==-1) d= 1;
		insert(o->ch[d],x);
		if (o->r<o->ch[d]->r) rotate(o,d^1);
	}
	o->mt();
}
void remove(node *&o,int x){
	if (o==null) return;
	int d= o->cmp(x);
	if (d==-1){
		if (o->ch[0]==null) o= o->ch[1];
		else if (o->ch[1]==null) o= o->ch[0];
		else {
			int d2= o->ch[0]->r > o->ch[1]->r;
			rotate(o,d2);remove(o->ch[d2],x);
		}
	}else remove(o->ch[d],x);
	if (o!=null) o->mt();
}
char read(){
	char c= getchar();
	while (c<'A'||c>'Z') c= getchar();
	return c;
}
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
void dfs(node *&o,node *&O){
	if (o==null) return;
	dfs(o->ch[0],O);
	dfs(o->ch[1],O);
	insert(O,o->v);
	//delete o;
	o= null;
}
int find(node *o,int k){
	if (o==null) return 0;
	int d= o->ch[0]->s+1;
	if (k==d) return o->v;
	if (k>d) return find(o->ch[1],k-d);
	else return find(o->ch[0],k);
}
void init(int n){
	int i;
	for (i= 1;i<=n;i++)
		a[i]= null,f[i]= i;
	memset(b,0,sizeof(b));
	ans= tot= cnt= 0;
}
void combine(int x,int y){
	find(x);find(y);
	if (a[f[x]]->s>a[f[y]]->s){
		dfs(a[f[y]],a[f[x]]);
		f[f[y]]= f[x];
	}else {
		dfs(a[f[x]],a[f[y]]);
		f[f[x]]= f[y];
	}
}
void change(int x,int y){
	int fa= f[x];
	remove(a[fa],c[x]);
	insert(a[fa],y);
	c[x]= y;
}
int main()
{
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	null= new node(0);
	while (scanf("%d %d",&n, &m)!=EOF&&n){
		a1++;
		for (i= 1;i<=n;i++)
			scanf("%d",&c[i]);
		init(n);
		for (i= 1;i<=m;i++){
			scanf("%d %d",&x, &y);
			l[i]= (edge){x,y};
		}
		while (true){
			scanf("%c",&ch);
			if (ch=='D'){
				scanf("%d",&x);
				b[x]= 1;
				Q[++tot]= (query){1,x,0};
			}else if (ch=='Q'){
				scanf("%d %d",&x, &y);
				Q[++tot]= (query){2,x,y};
				cnt++;
			}else if (ch=='C'){
				scanf("%d %d",&x, &y);
				Q[++tot]= (query){3,x,c[x]};
				c[x]= y;
			}else if (ch=='E') break;
		}
		for (i= 1;i<=n;i++)
			insert(a[i],c[i]);
		for (i= 1;i<=m;i++)
			if (!b[i]){
				x= l[i].u;y= l[i].v;
				if (find(x)!=find(y))
					combine(f[x],f[y]);				
			}
		for (i= tot;i>0;i--){
			x= Q[i].b;
			if (x==1){
				//continue;				
				x= Q[i].x;
				if (x>m) continue;
				y= l[x].v;x= l[x].u;
				if (find(x)!=find(y))
					combine(f[x],f[y]);
			}else if (x==2){
				//continue;				
				x= find(Q[i].x);y= Q[i].y;
				if (y>a[x]->s) ans+= 0;
				else ans+= find(a[x],a[x]->s-y+1);
			}else {
				//continue;				
				x= Q[i].x;y= Q[i].y;
				find(x);
				change(x,y);
			}
		}
		printf("Case %d: %.6lf\n",a1, ans/cnt);
		//printf("%.6lf\n",ans/cnt);	
	}
	return 0;
}
