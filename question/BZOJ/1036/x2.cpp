#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
const int maxn= 50001,oo= 99999999;
struct node *null;
struct node{
	node *ch[2],*par;
	int v,z[2],ba;
	void mt(){
		z[0]= max(ch[0]->z[0],max(ch[1]->z[0],v));
		z[1]= ch[0]->z[1]+ch[1]->z[1]+v;
	}
	node(int x):v(x){
		z[0]= z[1]= v;par= null;
		ch[0]= ch[1]= null;
	}
};
node *a[maxn];
vector<int> g[maxn];
int vis[maxn],d[maxn],fa[maxn];
int n,q,i,j,x,y,time,askmax,asksum;
char ch;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];
	o->ch[d^1]= k->ch[d];
	k->ch[d]->par= o;
	k->ch[d]= o;
	k->par= o->par;
	o->par= k;
	if (k->par->ch[0]==o || k->par->ch[1]==o)
		k->par->ch[k->par->ch[1]==o]= k;
	o->mt();k->mt();o= k;
}
void splay(node *&o){
	node *p= o->par;
	if (p->ch[0]!=o && p->ch[1]!=o) return;
	if (p->ch[0]==o) rotate(p,1);
	else rotate(p,0);
	splay(p);
}
void dfs(int o,int s){
	d[o]= s;int len= g[o].size();
	for (int i= 0;i<len;i++){
		int v= g[o][i];
		if (!d[v]){
			a[v]->par= a[o];
			dfs(v,s+1);
		}
	}
}
node *access(node *u){
	node *v= null;
	while (u!=null){
		splay(u);
		u->ch[1]= v;
		(v= u)->mt();
		u= u->par;
	}
	return v;
}
void ask(int o){
	access(a[x]);
	node *lca= access(a[y]);
	askmax= max(lca->ch[1]->z[0],lca->v);asksum= lca->ch[1]->z[1]+lca->v;
	access(a[x]);
	askmax= max(askmax,lca->ch[1]->z[0]);asksum+= lca->ch[1]->z[1];
	if (o==1) printf("%d\n",askmax);
	else printf("%d\n",asksum);
}
void change(){
	a[x]->v= y;
	splay(a[x]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);null->z[0]= -oo;
	scanf("%d",&n);
	for (i= 1;i<=n-1;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	a[0]= null;
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		a[i]= new node(x);
		a[i]->ba= i;
		a[i]->mt();
	}a[1]->par= null;
	dfs(1,1);
	scanf("%d",&q);
	for (i= 1;i<=q;i++){
		for (j= 1;j<=5;j++)
			scanf("%c",&ch);
		if (ch=='X'){
			scanf("%d %d",&x, &y);
			ask(1);
		}else if (ch=='M'){
			scanf("%d %d",&x, &y);
			ask(2);
		}else {
			for (j= 1;j<=2;j++)
				scanf("%c",&ch);
			scanf("%d %d",&x, &y);
			change();
		}
	}
	return 0;
}
