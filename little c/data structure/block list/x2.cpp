#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
const int maxn= 300001,size= 300,oo= 1e5,L= -1,R= oo;
struct node *null;
struct node{
	node *ch[2];
	int v,s,r;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){s= ch[0]->s+ch[1]->s+1;}
	void clear(){
		v= s= 0;r= rand();
		ch[0]= ch[1]= null;
	}
	node(int x):v(x),s(0),r(rand()){ch[0]= ch[1]= null;}
};
struct Node *Null;
struct Node{
	Node *ch[2];
	vector<int> g;
	node *root;
	void clear(){
		g.clear();
		root= null;
		ch[0]= ch[1]= Null;
	}
	Node(){ch[0]= ch[1]= Null;root= null;}
};
struct checknode{
	int size;
};
checknode a[maxn];
Node *head,*p;
int c[maxn],b[maxn];
int n,m,i,x,y,z,ans,tot;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null){o= new node(x);}
	else {
		int d= o->cmp(x);
		if (d==-1) d= 1;
		insert(o->ch[d],x);
		if (o->ch[d]->r>o->r) rotate(o,d^1);
	}o->mt();
}
void remove(node *&o,int x){
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
int count(node *o,int x){
	if (o==null) return 0;
	int d= o->cmp(x);if (d==-1) d= 1;
	if (d) return count(o->ch[1],x);
	else return o->ch[1]->s+1+count(o->ch[0],x);
}
void add(Node *o,int x){
	o->g.push_back(x);
	insert(o->root,x);
}
void pop(Node *o){
	remove(o->root,o->g[o->g.size()-1]);
	o->g.pop_back();
}
Node *build(int n){
	int i;Node *o= new Node(),*p= o;
	for (i= 1;i<=n;i++){
		if (p->g.size()>=size){
			p->ch[0]= new Node();
			p->ch[0]->ch[1]= p;
			p= p->ch[0];
		}add(p,c[i]);
	}return o;
}
void location(Node *o,int k,Node *&p,int &x){
	p= o;
	while (k>p->g.size() && p!=Null)
		k-= p->g.size(),p= p->ch[0];
	x= k-1;
}
void split(Node *left,int x,Node *&right){
	right= new Node();int i;
	for (i= x+1;i<left->g.size();i++)
		add(right,left->g[i]);
	while (left->g.size()>x+1)
		pop(left);
	right->ch[0]= left->ch[0];
	left->ch[0]->ch[1]= right;
	left->ch[0]= Null;
}
Node *merge(Node *left, Node *right){
	int i;Node *p= left;
	while (p->ch[0]!=Null) p= p->ch[0];
	if (p->g.size()+right->g.size()<=2*size){
		for (i= 0;i<right->g.size();i++)
			add(p,right->g[i]);
		right= right->ch[0];
	}
	p->ch[0]= right;right->ch[1]= p;
	return left;
}
void insert(int x,Node *mid){
	Node *p,*right;
	location(head,x,p,x);
	split(p,x,right);
	head= merge(merge(head,mid),right);
}
void remove(int x,int y){
	Node *p,*mid,*right;
	x--;
	location(head,x,p,x);
	split(p,x,mid);
	location(mid,y,p,x);
	split(p,x,right);
	head= merge(head,right);
}
int find(int l,int r,int k){
	Node *p,*mid,*right;
	l--;r-= l;
	location(head,l,p,l);
	split(p,l,mid);
	location(mid,r,p,r);
	split(p,r,right);
	l= L,r= R;
	while (l+1<r){
		p= mid;int cnt= 0;
		int mid= (l+r)>>1;
		while (p!=Null){
			cnt+= count(p->root,mid);
			if (cnt>=k) break;
			p= p->ch[0];
		}
		if (cnt>=k) l= mid;
		else r= mid;
	}
	head= merge(merge(head,mid),right);
	return r;
}
void print(Node *o){
	int i;Node *p= o;
	while (p!=Null){
		for (i= 0;i<p->g.size();i++)
			printf("%d ",p->g[i]);
		p= p->ch[0];
	}
}
void check(Node *p){
	int top= 0;tot= 0;memset(b,0,sizeof(b));
	while (p!=Null){
		int len= p->g.size(),i;
		for (i= 0;i<p->g.size();i++)
			b[++top]= p->g[i];
		a[++tot].size= len;
		p= p->ch[0];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	null= new node(0);Null= new Node();
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	head= build(n);//check(head);
	for (int a1= 1;a1<=m;a1++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d",&x, &y);
			for (i= 1;i<=y;i++)
				scanf("%d",&c[i]);
			p= build(y);
			insert(x,p);
		}else if (x==2){
			scanf("%d %d",&x, &y);
			remove(x,y);
		}else {
			scanf("%d %d %d",&x, &y, &z);
			ans= find(x,y,z);
			printf("%d\n",ans);
		}
	}
	print(head);
	return 0;
}
