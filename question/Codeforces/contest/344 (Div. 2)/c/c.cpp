#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
struct N{
	int r,t;
}sta[maxn];
struct node *null;
struct node{
	node *ch[2];
	int v,s,flip;
	int cmp(int k){
		int d= ch[0]->s;
		if (k==d+1) return -1;
		return k>d+1;
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
int a[maxn];
node *root,*left,*mid,*right;
int n,m,i,j,la,x,y,z,top,cnt;
bool cmp(int a,int b){
	return a>b;
}
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];
	k->ch[d]= o;o->mt();k->mt();o= k;
}
void splay(node *&o,int k){
	o->pushdown();
	int d= o->cmp(k);
	if (d!=-1){
		node *p= o->ch[d];
		p->pushdown();
		if (d) k-= o->ch[0]->s+1;
		int d2= p->cmp(k);
		if (d2!=-1){
			if (d2) k-= p->ch[0]->s+1;			
			splay(p->ch[d2],k);
			if (d!=d2) rotate(o->ch[d],d);
			else rotate(o,d^1);
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
	left= o;right= o->ch[1];
	o->ch[1]= null;
	o->mt();
}
node *build(int sz){
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
	o->pushdown();
	print(o->ch[0]);
	cnt++;
	if (cnt==1);
	else if (cnt==2) printf("%d",o->v);
	else printf(" %d",o->v);
	print(o->ch[1]);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	null= new node(0);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		while (la&&sta[la].r<=y) la--;
		if (la&&sta[la].t==x) continue;
		sta[++la]= (N){y,x};
	}
	if (sta[1].t==1)
		sort(a+1,a+sta[1].r+1);
	else sort(a+1,a+sta[1].r+1,cmp);
	root= build(n+1);
	for (i= 2;i<=la;i++){
		split(root,1,left,mid);
		split(mid,sta[i].r,mid,right);
		mid->flip^= 1;
		root= merge(left,merge(mid,right));
	}
	print(root);
}
