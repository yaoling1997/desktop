#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
const int maxn= 300001,oo= 1e8;
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
};
struct edge{
	int u,v,d;
	bool operator <(const edge &a)const{
		return d<a.d;
	}
};
point p[maxn];
edge l[10*maxn];
int b[maxn],f[maxn],use[10*maxn];
node *root;
int n,i,top,ans;
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
		}
	}
}
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
int kruskal(){
	int i,re= 0;
	sort(l+1,l+top+1);
	for (i= 1;i<=n;i++)
		f[i]= i;
	for (i= 1;i<=top;i++){
		int u= l[i].u,v= l[i].v;
		if (find(u)!=find(v)){
			f[f[u]]= f[v];
			use[i]= 1;
			re+= l[i].d;
		}
	}return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	root= null= new node(0,0,0);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d %d",&p[i].x, &p[i].y);
		p[i].b= i;
	}
	getedges();
	ans= kruskal();
	printf("%d\n",ans);
	//for (i= 1;i<=top;i++)	if (use[i])printf("%d %d\n",l[i].u, l[i].v);		
	return 0;
}
