#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 300001;
struct node *null;
struct node{
	node *ch[2],* par;
	int s;
	int cmp(int k){
		int d= ch[0]->s;
		if (d+1==k)return -1;
		return k>d+1;
	}
	void mt(){s= ch[0]->s+ch[1]->s+1;}
	node():s(0){ch[0]= ch[1]= par= null;}
};
node *a[maxn];
vector<int> g[maxn];
int i,n,q,t,s,x,y,ans;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];
	k->ch[d]->par= o;
	k->ch[d]= o;k->par= o->par;o->par= k;
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
void dfs(int o){
	int len= g[o].size();
	for (int i= 0;i<len;i++){
		int v= g[o][i];
		a[v]->par= a[o];
		dfs(v);
	}
}
int access(node *v){
	node *u= null,*p= v;
	while (v!=null){
		splay(v);
		v->ch[1]= u;
		(u= v)->mt();
		v= v->par;
	}
	splay(p);
	return p->ch[0]->s;
}
void change(node *x,node *y){
	splay(x);
	x->ch[0]->par= x->par;
	x->par= y;x->ch[0]= null;x->mt();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node();a[0]= null;
	scanf("%d",&n);s= n+1;a[s]= new node();a[s]->mt();
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		a[i]= new node();a[i]->mt();
		int k= min(i+x,s);
		g[k].push_back(i);
	}
	dfs(s);
	scanf("%d",&q);
	for (t= 1;t<=q;t++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&x);x++;
			ans= access(a[x]);
			printf("%d\n",ans);
		}else {
			scanf("%d %d",&x, &y);x++;
			int z= min(s,x+y);
			change(a[x],a[z]);
		}
	}
	return 0;
}
