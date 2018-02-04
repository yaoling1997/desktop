#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct node *null;
struct node{
	node *ch[2],*par;
	int v,s,z,b;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){s= ch[0]->s+ch[1]->s+b;}
	void pushdown(){
		v+= z;
		ch[0]->z+= z;ch[1]->z+= z;
		z= 0;
	}
	node(int x):v(x),s(0),z(0),b(1){ch[0]= ch[1]= null;}
};
node *root;
char ch;
int n,x,i,v,ans,sum;
void rotate(node *&o,int d){
	node *k= o->ch[d^1],*fa= o->par;
	o->ch[d^1]= k->ch[d];
	k->ch[d]->par= o;
	k->ch[d]= o;
	o->par= k;
	k->par= fa;
	if (fa->ch[0]==o || fa->ch[1]==o)
		fa->ch[fa->ch[1]==o]= k;
	o->mt();k->mt();
	o= k;
}
void splay(node *&o){
	node *p= o->par;o->mt();
	if (p->ch[0]!=o && p->ch[1]!=o){
		root= o;
		return;
	}
	if (p->ch[0]==o) rotate(p,1);
	else rotate(p,0);
	splay(p);
}
void insert(node *&o,int x){
	if (o==null){
		o= new node(x),o->par= null->par;o->mt();
		splay(o);
	}
	else{
		o->pushdown();
		int d= o->cmp(x);
		if (d==-1){
			o->b++;
			splay(o);
			return;
		}
		o->ch[d]->par= o;
		insert(o->ch[d],x);
	}
}
void del(node *o,int x){
	if (o==null) return;
	node *p= o;
	while (o!=null){
		o->pushdown();
		int d= o->cmp(x);
		if (o->v>=x)
			if (p->v<x || o->v-x<p->v-x) p= o;
		if (d==-1) break;
		o= o->ch[d];
	}
	root= p;
	splay(root);
	if (root->v<x) root= null;
	else root->ch[0]= null,root->mt();
}
int find(node *o,int k){
	if (o==null) return -1;
	o->pushdown();
	if (o->ch[0]->s+o->b>=k && o->ch[0]->s+1<=k) return o->v;
	if (o->ch[0]->s+o->b<k)
		return find(o->ch[1],k-o->ch[0]->s-o->b);
	else return find(o->ch[0],k);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	root= null= new node(0);root->par= null;
	scanf("%d %d",&n, &v);
	for (int a1= 1;a1<=n;a1++){
		do scanf("%c",&ch);
		while (ch<'A'||ch>'Z');
		scanf("%d",&x);
		if (ch=='I'){
			if (x<v) continue;
			insert(root,x);sum++;
		}else if (ch=='A'){
			root->z+= x;
		}else if (ch=='S'){
			root->z-= x;
			del(root,v);
		}else {
			if (x>root->s) ans= -1;
			else {
				x= root->s-x+1;
				ans= find(root,x);
			}
			printf("%d\n",ans);
		}
	}
	printf("%d\n",sum-root->s);
	return 0;
}
