#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define gc getchar
using namespace std;
const int maxn= 30001;
struct node *null;
struct node{
	node *ch[2],*par;
	int v,s,flip;
	void mt(){s= ch[0]->s+ch[1]->s+1;}
	void pushdown(){
		if (flip){
			ch[0]->flip^= 1;
			ch[1]->flip^= 1;
			swap(ch[0],ch[1]);
			flip= 0;
		}
	}
	node(int x):v(x),s(0),flip(0){ch[0]= ch[1]= par= null;}
};
node *a[maxn];
char c;
int n,m,i,x,y;
void rotate(node *&o,int d){
	node *k= o->ch[d^1],*fa= o->par;
	o->ch[d^1]= k->ch[d];k->ch[d]->par= o;
	k->ch[d]= o;k->par= fa;o->par= k;
	if (fa->ch[0]==o || fa->ch[1]==o)
		fa->ch[fa->ch[1]==o]= k;
	o->mt();k->mt();o= k;
}
void pushdown(node *o){
	node *fa= o->par;
	if (fa->ch[0]==o||fa->ch[1]==o) pushdown(fa);
	o->pushdown();
}
void splay(node *&o){
	pushdown(o);
	while (true){
		node *p= o->par;
		if (p->ch[0]!=o && p->ch[1]!=o) return;
		rotate(p,p->ch[0]==o);
		//o= p;
	}
}
node *findRoot(node *o){
	while (o->par!=null) o= o->par;
	return o;
}
node *access(node *u){
	node *v= null;
	while (u!=null){
		splay(u);
		u->ch[1]= v;
		(v= u)->mt();
		u= u->par;
	}return v;
}
void makeRoot(node *u){
	access(u);
	splay(u);
	u->flip^= 1;
	//u->pushdown();
}
void link(node *u,node *v){
	makeRoot(u);
	u->par= v;
}
void cut(node *u,node *v){
	makeRoot(u);
	access(v);
	splay(v);
	v->ch[0]= u->par= null;
	v->mt();
}
void query(node *u,node *v){
	if (findRoot(u)==findRoot(v)) printf("Yes\n");
	else printf("No\n");
}
int gi(){
	char c= gc();int re= 0;
	while (c<'0'||c>'9') c= gc();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= gc();
	return re;
}
void init(int n){
	int i;
	for (i= 1;i<=n;i++)
		a[i]= new node(i);
}
int main()
{
	null= new node(0);
	n= gi();m= gi();
	init(n);
	for (int a1= 1;a1<=m;a1++){
		c= gc();
		if (c=='C'){
			for (i= 1;i<=6;i++) c= gc();
			x= gi();y= gi();
			link(a[x],a[y]);
		}else if (c=='D'){
			for (i= 1;i<=6;i++) c= gc();
			x= gi();y= gi();
			cut(a[x],a[y]);
		}else {
			for (i= 1;i<=4;i++) c= gc();
			x= gi();y= gi();
			query(a[x],a[y]);
		}
	}
	return 0;
}

