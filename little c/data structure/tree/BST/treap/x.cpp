#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
const int maxn= 300001;
struct node *null;
struct node{
	node *ch[2];
	int v,r,s;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void clear(){r=rand();v= s= 0,ch[0]=ch[1]=null;}
	void mt(){s= ch[0]->s+ch[1]->s+1;}
	node(int x):v(x),r(rand()),s(0){ch[0]= ch[1]= null;}
};
node *root;
int n,m,i,x;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null) o= new node(x);
	else {
		int d= o->cmp(x);
		insert(o->ch[d],x);
		if (o->ch[d]->r > o->r) rotate(o,d^1);
	}
	o->mt();
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
int find(node *o,int x){
	while (o!=null){
		int d= o->cmp(x);
		if (d==-1) return 1;
		o= o->ch[d];
	}
	return 0;
}
int getint(){
	char c= getchar();int re= 0,p= 1;
	while ((c<'0' || c>'9') && c!='-') c= getchar();
	if (c=='-') p= -1,c= getchar();
	while(c>='0' && c<='9') re= re*10+c-'0',c= getchar();
	return re*p;
}
void print(node *o){
	if (o==null) return;
	print(o->ch[0]);
	printf("%d ",o->v);
	print(o->ch[1]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);root= null;
	scanf("%d %d",&n,&m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		if (!find(root,x)) insert(root,x);
	}
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (find(root,x)) remove(root,x);
	}
	print(root);
	return 0;
}
