#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001;
struct node *null;
struct node{
	node *ch[2];
	int s,v;
	int cmp(int k){
		int d= ch[0]->s;
		if (d+1==k) return -1;
		return k>d+1;
	}
	void mt(){s= ch[0]->s + ch[1]->s+1;}
	node(int x):s(0),v(x){ch[0]= ch[1]= null;}
};
node *root,*o,*left,*right,*mid;
int a[maxn];
int n,m,i,j,top,x,y,bl;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void splay(node *&o,int k){
	int d= o->cmp(k);
	if (d!=-1){
		if (d) k-= o->ch[0]->s+1;
		node *p= o->ch[d];
		int d2= p->cmp(k);
		if (d2!=-1){
			int k2= d2 ? k-p->ch[0]->s-1 : k;
			splay(p->ch[d2],k2);
			if (d==d2) rotate(o,d^1);else rotate(o->ch[d],d2^1);
		}rotate(o,d^1);
	}
}
node *merge(node *left,node *right){
	splay(left,left->s);
	left->ch[1]= right;
	left->mt();
	return left;
}
void split(node *o,int k,node *&left,node *&right){
	splay(o,k);
	left= o;
	right= o->ch[1];
	o->ch[1]= null;
	left->mt();
}
node *build (int sz){
	if (!sz) return null;
	node *l= build(sz/2);
	node *o= new node(a[top++]);
	o->ch[0]= l;
	o->ch[1]= build(sz-sz/2-1);
	o->mt();
	return o;
}
void print(node *o){
	if (o==null) return;
	print(o->ch[0]);
	if (bl)	printf("%d ",o->v);
	else bl= 1;
	print(o->ch[1]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++) scanf("%d",&a[i]);
	root= build(n+1);
	for (i= 1;i<=m;i++){
		top= 0;
		scanf("%d %d",&x, &y);
		for (j= 0;j<y;j++)
			scanf("%d",&a[j]);
		split(root,x+1,left,right);
		mid= build(y);
		root= merge(merge(left,mid),right);
	}
	print(root);
}
