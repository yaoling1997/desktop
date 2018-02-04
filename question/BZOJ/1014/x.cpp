#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ull unsigned long long
using namespace std;
const int maxn= 2e5,base= 37;
ull d[maxn];
struct node *null;
struct node{
	node *ch[2];
	ull m,v;
	int s;
	int cmp(int k){
		int d= ch[0]->s+1;
		if (d==k) return -1;
		return k>d;
	}
	void mt(){
		ull l= ch[0]->m,r= ch[1]->m;
		s= ch[0]->s+ch[1]->s+1;
		m= (l*d[1]+v)*d[ch[1]->s]+r;
	}
	node(int x):m(0),v(x),s(0){
		ch[0]= ch[1]= null;
	}
};
char s[maxn];
node *root,*left,*mid,*right;
char ch;
int n,m,ans,top,i,x,y;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void splay(node *&o,int k){
	int d= o->cmp(k);
	if (d!=-1){
		k-= d? o->ch[0]->s+1:0;
		node *p= o->ch[d];
		int d2= p->cmp(k);
		if (d2!=-1){
			k-= d2? p->ch[0]->s+1:0;
			splay(p->ch[d2],k);
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
	left= o;right= o->ch[1];
	o->ch[1]= null;
	o->mt();
}
node *build(int sz){
	if (!sz) return null;
	node *l= build(sz/2);
	node *o= new node(s[top++]);
	o->ch[0]= l;
	o->ch[1]= build(sz-sz/2-1);
	o->mt();
	return o;
}
int get(int x,int y){
	n= root->s-1;
	int l= 0,r= n-max(x,y)+2;
	ull a,b;
	while (l+1<r){
		int m= (l+r)>>1;
		split(root,x,left,mid);
		split(mid,m,mid,right);
		a= mid->m;
		root= merge(merge(left,mid),right);
		split(root,y,left,mid);
		split(mid,m,mid,right);
		b= mid->m;
		root= merge(merge(left,mid),right);
		if (a==b) l= m;
		else r= m;
	}return l;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	d[0]= 1;
	for (i= 1;i<=1e5;i++)
		d[i]= d[i-1]*base;
	scanf("%s",s+1);
	n= strlen(s+1);
	root= build(n+1);
	scanf("%d",&m);
	for (int a1= 1;a1<=m;a1++){
		scanf("%s",s+1);
		if (s[1]=='Q'){
			scanf("%d %d",&x, &y);
			ans= get(x,y);
			printf("%d\n",ans);
		}else if (s[1]=='R'){
			scanf("%d %c",&x, &ch);
			split(root,x,left,mid);
			split(mid,1,mid,right);
			mid->v= ch;
			mid->mt();
			root= merge(merge(left,mid),right);
		}else {
			scanf("%d %c",&x, &ch);
			x++;
			split(root,x,left,right);
			mid= new node(ch);
			mid->mt();
			root= merge(merge(left,mid),right);
		}
	}return 0;
}
