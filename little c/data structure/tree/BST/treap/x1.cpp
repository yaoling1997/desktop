#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
struct node{
	node *ch[2];
	int r,v,s;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){
		s= 1;
		if (ch[0]!=NULL) s+= ch[0]->s;
		if (ch[1]!=NULL) s+= ch[1]->s;
	}
};
node *root;
int n,i,x,m;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==NULL){
		o= new node();
		o->ch[0]= o->ch[1]= NULL;o->v= x;o->r= rand();
	}else {
		int d= o->cmp(x);
		insert(o->ch[d],x);
		if (o->r < o->ch[d]->r) rotate(o,d^1);
	}
	o->mt();
}
void remove(node *&o,int x){
	int d= o->cmp(x);
	if (d==-1){
		if (o->ch[0]==NULL) o= o->ch[1];
		else if (o->ch[1]==NULL) o= o->ch[0];
		else {
			int d2= (o->ch[0]->r > o->ch[1]->r);
			rotate(o,d2);remove(o->ch[d2],x);
		}
	}else remove(o->ch[d],x);
	if (o!=NULL) o->mt();
}
int find(node *o,int x){
	while (o!=NULL){
		int d= o->cmp(x);
		if (d==-1) return 1;
		o= o->ch[d];
	}
	return 0;
}
int f_k(node *o,int k){
	int s= (o->ch[0]==NULL ? 0:o->ch[0]->s);
	if (k==s+1) return o->v;
	else if (k<=s) return f_k(o->ch[0],k);
	else return f_k(o->ch[1],k-s-1);
}
int f_rank(node *o,int x){
	if (o==NULL) return 1;
	if (x<=o->v) return f_rank(o->ch[0],x);
	return f_rank(o->ch[1],x)+(o->ch[0]==NULL ? 0:o->ch[0]->s)+1;
}
void print(node *o){
	if (o==NULL) return;
	print(o->ch[0]);
	printf("%d ",o->v);
	print(o->ch[1]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		if (!find(root,x))
			insert(root,x);
	}
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (find(root,x)){
			remove(root,x);
			n--;
		}
	}
	print(root);printf("\n");
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (find(root,x))
			printf("%d\n",f_rank(root,x));
		else printf("no!\n");
	}
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (x<=n && x>0)
			printf("%d\n",f_k(root,x));
		else printf("oh no!\n");
	}
	return 0;
}
