#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
struct node *null;
struct node{
	node *ch[2];
	int s,v,jj,flip,ma;
	int cmp(int k){
		int d= ch[0]->s;
		if (k==d+1) return -1;
		return k>d+1;
	}
	void mt(){
		s= ch[0]->s + ch[1]->s+1;
		ma= max(v,ch[0]->ma + ch[0]->jj);
		ma= max(ma,ch[1]->ma + ch[1]->jj);
	}
	void pushdown(){
		v+= jj;
		if (ch[0]!=null) ch[0]->jj+= jj;
		if (ch[1]!=null) ch[1]->jj+= jj;
		jj= 0;
		if (flip){
			flip= 0;
			swap(ch[0],ch[1]);
			ch[0]->flip^= 1;ch[1]->flip^=1;
		}
	}
	node(int x):s(0),v(x),jj(0),flip(0),ma(0){ch[0]= ch[1]= null;}
};
//node *a[maxn];
node *root,*left,*right,*o,*mid;
int n,m,x,y,z,i,top;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void splay(node*&o,int k){
	o->pushdown();
	int d= o->cmp(k);
	if (d!=-1){
		if (d) k-= o->ch[0]->s+1;
		node *p= o->ch[d];
		p->pushdown();
		int d2= p->cmp(k);
		if (d2!=-1){
			int k2= d2? k-p->ch[0]->s-1:k;
			splay(p->ch[d2],k2);
			if (d==d2) rotate(o,d^1);
			else rotate(o->ch[d],d2^1);
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
node *build(int sz){
	if (!sz) return null;
	node *l= build(sz/2);
	node *o= new node (0);
	o->ch[0]= l;
	o->ch[1]= build(sz-sz/2-1);
	o->mt();
	return o;
}
void print(node *o){
	if (o==null) return;
	o->pushdown();
	print(o->ch[0]);
	printf("%d ",o->v + o->jj);
	print(o->ch[1]);
}
int main()
{
    top= 0;
	//for (i= 0;i<=1000;i++) a[i]= new node (0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	null->ma= -99999999;
	scanf("%d %d",&n, &m);
	root= build(n+1);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d %d",&x, &y, &z);
			split(root,x,left,o);
			split(o,y-x+1,mid,right);
			mid->jj+= z;
			root= merge(merge(left,mid),right);
			//print(root);printf("\n");
		}else if (x==2){
			scanf("%d %d",&x, &y);
			split(root,x,left,o);
			split(o,y-x+1,mid,right);
			mid->flip^= 1;
			root= merge(merge(left,mid),right);
		}else {
			scanf("%d %d",&x, &y);
			split(root,x,left,o);
			split(o,y-x+1,mid,right);
			printf("%d\n",mid->ma);
			root= merge(merge(left,mid),right);
		}
	}
	return 0;
}
