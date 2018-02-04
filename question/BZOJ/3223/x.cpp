#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 2e5;
struct node *null;
struct node{
	node *ch[2];
	int v,s,flip;
	int cmp(int k){
		int d= ch[0]->s+1;
		if (k==d) return -1;
		return k>d;
	}
	void mt(){
		s= ch[0]->s+ch[1]->s+1;
	}
	void pushdown(){
		if (flip){
			ch[0]->flip^= 1;
			ch[1]->flip^= 1;
			swap(ch[0],ch[1]);
			flip= 0;
		}
	}
	node(int x):v(x),s(0),flip(0){ch[0]= ch[1]= null;}
};
int c[maxn];
node *root,*left,*mid,*right;
int n,m,i,x,y,top,bl;
node *build(int sz){
	if (!sz) return null;
	node *l= build(sz-sz/2-1);
	node *o= new node(c[top++]);
	o->ch[0]= l;
	o->ch[1]= build(sz/2);
	o->mt();
	return o;
}
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void splay(node *&o,int k){
	o->pushdown();
	int d= o->cmp(k);
	if (d!=-1){
		if (d) k-= o->ch[0]->s+1;
		node *p= o->ch[d];
		p->pushdown();
		int d2= p->cmp(k);
		if (d2!=-1){
			if (d2) k-= p->ch[0]->s+1;
			splay(p->ch[d2],k);
			if (d==d2) rotate(o,d^1);
			else rotate(o->ch[d],d2^1);
		}rotate(o,d^1);
	}
}
void split(node *o,int k,node *&left,node *&right){
	splay(o,k);
	left= o;
	right= o->ch[1];
	o->ch[1]= null;
	o->mt();
}
node *merge(node *left,node *right){
	splay(left,left->s);
	left->ch[1]= right;
	left->mt();
	return left;
}
void print(node *o){
	if (o==null) return;
	o->pushdown();
	print(o->ch[0]);
	if (!bl){
		bl= 1;
		return;
	}
	printf("%d ",o->v);
	print(o->ch[1]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++) c[i]= i;
	root= build(n+1);
	for (int a1= 1;a1<=m;a1++){
		scanf("%d %d",&x, &y);
		split(root,x,left,mid);
		split(mid,y-x+1,mid,right);
		mid->flip^= 1;
		mid->pushdown();
		root= merge(merge(left,mid),right);
	}print(root);
	return 0;
}
