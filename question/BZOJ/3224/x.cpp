#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct node *null;
struct node{
	node *ch[2];
	int v,r,s;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	int cmp2(int k){
		int d= ch[0]->s+1;
		if (d==k) return -1;
		return k>d;
	}
	void mt(){
		s= ch[0]->s+ch[1]->s+1;
	}
	node(int x):v(x),r(rand()),s(0){ch[0]= ch[1]= null;}
};
node *root;
int x,y,ans,m;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null) o= new node(x);
	else {
		int d= o->cmp(x);
		if (d==-1) d= 1;
		insert(o->ch[d],x);
		if (o->ch[d]->r > o->r) rotate(o,d^1);
	}o->mt();
}
void remove(node *&o,int x){
	if (o==null) return;
	int d= o->cmp(x);
	if (d==-1){
		if (o->ch[0]==null) o= o->ch[1];
		else if (o->ch[1]==null) o= o->ch[0];
		else {
			int d2= o->ch[0]->r > o->ch[1]->r;
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
	}else remove(o->ch[d],x);
	if (o!=null) o->mt();
}
void rank(node *o,int x){
	ans= 0;
	while (o!=null){
		int d= o->cmp(x);
		if (d==-1) d= 0;
		if (d) ans+= o->ch[0]->s+1;
		o= o->ch[d];
	}ans++;
}
void rank2(node *o,int x){
	ans= 0;
	while (o!=null){
		int d= o->cmp(x);
		if (d==-1) d= 1;
		if (d) ans+= o->ch[0]->s+1;
		o= o->ch[d];
	}ans++;
}
void sa(node *o,int k){
	while (o!=null){
		int d= o->cmp2(k);
		if (d==-1){
			ans= o->v;
			return;
		}
		if (d) k-= o->ch[0]->s+1;
		o= o->ch[d];
	}
}
void pre(node *o,int x){
	rank(o,x);
	sa(o,ans-1);
}
void suc(node *o,int x){
	rank2(o,x);
	sa(o,ans);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	root= null= new node(0);
	scanf("%d",&m);
	for (int a1= 1;a1<=m;a1++){
		scanf("%d %d",&x, &y);
		if (x==1)
			insert(root,y);
		else if (x==2)
			remove(root,y);
		else if (x==3)
			rank(root,y);
		else if (x==4)
			sa(root,y);
		else if (x==5)
			pre(root,y);
		else suc(root,y);		
		if (3<=x&&x<=6)
			printf("%d\n",ans);		
	}return 0;
}
