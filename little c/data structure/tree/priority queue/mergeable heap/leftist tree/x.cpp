#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 100001;
struct node *null;
struct node{
	node *ch[2],*par;
	int v,d;
	node (int x):v(x),d(0){ch[0]= ch[1]= null;}
};
node *a[maxn],*l[maxn];
node *root;
int n,m,i,x;
node *merge(node *a,node *b){
	if (a==null) return b;
	if (b==null) return a;
	if (a->v > b->v) swap(a,b);
	a->ch[1]= merge(a->ch[1],b);a->ch[1]->par= a;
	if (a->ch[0]->d < a->ch[1]->d)
		swap(a->ch[0],a->ch[1]);
	a->d= a->ch[1]->d+1;
	return a;
}
void insert(node *&a,int x){
	node *b= new node(x);
	a= merge(a,b);
}
void pop(node *&a){
	a= merge(a->ch[0],a->ch[1]);
}
node *build(int n){
	int i,f= 1,r= n;
	for (i= 1;i<=n;i++)
		l[i]= a[i];
	while (f<r){
		l[++r]= merge(l[f],l[f+1]);
		f+= 2;
	}
	return l[f];
}
void del(node *x){
	node *q= x->par;
	node *p= merge(x->ch[0],x->ch[1]);
	p->par= q;
	if (q==null) return;
	q->ch[q->ch[1]==x]= p;
	while (q!=null){
		if (q->ch[0]->d<q->ch[1]->d)
			swap(q->ch[0],q->ch[1]);
		if (q->ch[1]->d+1==q->d) return;
		q->d= q->ch[1]->d+1;
		p= q;
		q= q->par;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);null->d= -1;
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		a[i]= new node(x);
	}
	root= build(n);
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		insert(root,x);
	}
	while (root!=null){
		printf("%d ",root->v);
		pop(root);
	}
	return 0;
}
