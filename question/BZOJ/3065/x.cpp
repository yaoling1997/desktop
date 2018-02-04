#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 6000001,L= 0,R= 70100,sz= 30,maxl= 300000;
struct node *null;
struct node{
	node *ch[2];
	int root;
	vector<int> g;
	node():root(0){ch[0]= ch[1]= null;}
};
int l1[maxn],r1[maxn],size[maxn],stack[maxl],c[maxl];
int ST[maxn];int top;
char ch;
node *head;
int n,tot,i,x,y,z,la,q,ans;
////////////////////////
int a[maxn],b[maxn],cc[maxn],ooo,sh,TT;
void dfs1(int o){
	if (l1[o]) dfs1(l1[o]);
	if (r1[o]) dfs1(r1[o]);
	cc[++TT]= o;
}
void check(node *o){
	node *p= o;int i,top= 0,tot= 0;TT= 0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(cc,0,sizeof(cc));
	while (p!=null){
		dfs1(p->root);
		a[++top]= size[p->root];
		for (i= 0;i<p->g.size();i++)
			b[++tot]= p->g[i];
		p= p->ch[1];
	}
	sort(cc+1,cc+TT+1);
}
/////////////////////////
void dfs(int o){
	if (!o) return;
	if (l1[o]) dfs(l1[o]);
	if (r1[o]) dfs(r1[o]);
	ST[++top]= o;
	l1[o]= r1[o]= size[o]= 0;
}
int create(){
	if (top) return ST[top--];
	return ++tot;
}
void clear(node *o){
	dfs(o->root);
	o->g.clear();
}
void insert(int &o,int l,int r,int v){
	if (!o) o= create();
	size[o]++;
	if (l+1==r) return;
	int mid= (l+r)>>1;
	if (v<mid) insert(l1[o],l,mid,v);
	else insert(r1[o],mid,r,v);
}
int remove(int &o,int l,int r,int v){
	if (l+1==r){
		if (size[o]) return size[o]--;
		else return 0;
	}
	int mid= (l+r)>>1,y= size[o];
	if (v<mid){
		if (remove(l1[o],l,mid,v)) size[o]--;
	}else if (remove(r1[o],mid,r,v)) size[o]--;
	return y!=size[o];
}
void add(node *o,int x){
	o->g.push_back(x);
	insert(o->root,L,R,x);
}
void pop(node *o){
	remove(o->root,L,R,o->g[o->g.size()-1]);
	o->g.pop_back();
}
void location(node *o,int k,node *&p,int &x){
	p= o;
	while(p!=null && k>p->g.size())
		k-= p->g.size(),p= p->ch[1];
	x= k-1;
}
node *merge(node *left,node *right){
	node *p= left;int i;
	while (p->ch[1]!=null) p= p->ch[1];
	if (p->g.size()+right->g.size()<=2*sz){
		for (i= 0;i<right->g.size();i++)
			add(p,right->g[i]);
		clear(right);
		right= right->ch[1];
	}
	p->ch[1]= right;right->ch[0]= p;
	return left;
}
void split(node *o,int x,node *&right){
	right= new node();
	int i;
	for (i= x+1;i<o->g.size();i++)
		add(right,o->g[i]);
	while (o->g.size()>x+1)
		pop(o);
	right->ch[1]= o->ch[1];
	o->ch[1]->ch[0]= right;
	o->ch[1]= null;
}
int ask(node *o,int x,int y,int k){
	x--;y-= x;
	node *p,*mid,*right;
	location(o,x,p,x);
	split(p,x,mid);
	location(mid,y,p,y);
	split(p,y,right);
	la= 0;
	p= mid;
	while (p!=null) stack[++la]= p->root,p= p->ch[1];
	int l= L,r= R;
	while (l+1<r){
		int mid= (l+r)>>1,i,sum= 0;
		for (i= 1;i<=la;i++)
			sum+= size[l1[stack[i]]];
		if (sum<k){
			k-= sum;			
			for (i= 1;i<=la;i++)
				stack[i]= r1[stack[i]];
			l= mid;
		}else {
			for (i= 1;i<=la;i++)
				stack[i]= l1[stack[i]];
			r= mid;
		}
	}
	o= merge(merge(o,mid),right);
	return l;
}
void change(node *o,int x,int y){
	node *p;
	location(o,x,p,x);
	remove(p->root,L,R,p->g[x]);
	p->g[x]= y;
	insert(p->root,L,R,y);
}
void insert(node *o,int x,int y){
	node *p,*mid= new node(),*right;
	location(o,x,p,x);
	split(p,x,right);
	add(mid,y);
	o= merge(merge(o,mid),right);
}
node *build(int n){
	int i;node *o= new node(),*p= o;
	for (i= 1;i<=n;i++){
		if (p->g.size()>=sz){
			p->ch[1]= new node();
			p->ch[1]->ch[0]= p;
			p= p->ch[1];
		}add(p,c[i]);
	}return o;
}
void mt(node *o){
	return;
	node *p= o;
	while (p->ch[1]!=null&&p!=null){
		node *right= p->ch[1];
		if (p->g.size()+right->g.size()<=2*sz){
			for (i= 0;i<right->g.size();i++)
				add(p,right->g[i]);
			clear(right);right= right->ch[1];
			p->ch[1]= right;
			right->ch[0]= p;
		}
		p= p->ch[1];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	null= new node();
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	head= build(n);
	scanf("%d",&q);
	for (int a1= 1;a1<=q;a1++){
		if (a1==sh)
			ooo++;
		scanf("%c%c",&ch,&ch);
		if (a1%5==0)mt(head);			
		if (ch=='Q'){
			scanf("%d %d %d",&x, &y, &z);
			//x^= ans;y^= ans;z^= ans;
			ans= ask(head,x,y,z);
			printf("%d\n",ans);
		}else if (ch=='M'){
			scanf("%d %d",&x, &y);
			//x^= ans;y^= ans;
			change(head,x,y);
		}else {
			scanf("%d %d",&x, &y);
			//x^= ans;y^= ans;
			x--;
			insert(head,x,y);
		}
	}
	return 0;
}
