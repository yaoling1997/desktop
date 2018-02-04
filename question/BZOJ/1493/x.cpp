#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 600001,oo= 1e8;
struct node *null;
struct node{
	node *ch[2];
	int v,s,flip,z,a,x[2];
	int cmp(int k){
		int d= ch[0]->s+1;
		if (k==d) return -1;
		return k>d;
	}
	void mt(){
		s= ch[0]->s+ch[1]->s+1;
		x[0]= x[1]= a= 0;
		int i,l[2]= {0},z;
		for (i= 0;i<=1;i++)
			if (ch[i]!=null){
				z= ch[i]->flip;
				if (ch[i]->z) a++,x[i]= ch[i]->z,l[i]= ch[i]->z;
				else a+= ch[i]->a,x[i]= ch[i]->x[i^z],l[i]= ch[i]->x[i^1^z];
			}else l[i]= v,a++;
		if (v!=l[0]&&v!=l[1]) a++;
		if (v==l[0]&&v==l[1]) a--;
		for (i= 0;i<=1;i++)
			if (!x[i]) x[i]= v;
	}
	void pushdown(){
		if (flip){
			flip= 0;
			ch[0]->flip^= 1;
			ch[1]->flip^= 1;
			swap(ch[0],ch[1]);
			swap(x[0],x[1]);
		}
		if (z){
			ch[0]->z = ch[1]->z = v= z;
			z= 0;mt();
		}
	}
	node(int x):v(x),s(0),flip(0),z(0),a(0){
		ch[0]= ch[1]= null;
		this->x[0]= this->x[1]= 0;
	}
};
int c[maxn];
node *root,*left,*mid,*right,*o;
char ch;
int n,i,tot,x,y,z,q,xx,yy,ans;
int random(int o){return rand()%o;}
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void splay(node *&o,int k){
	o->pushdown();
	int d= o->cmp(k);
	if (d!=-1){
		if (d) k-= o->ch[0]->s+1;
		node *p= o->ch[d];
		p->pushdown();
		int d2= p->cmp(k);
		if (d2!=-1){
			if (d2) k-= p->ch[0]->s+1;
			splay(p->ch[d2],k);
			if (d==d2) rotate(o,d^1);
			else rotate(o->ch[d],d2^1);
		}rotate(o,d^1);
	}
}
void split(node *o,int k,node *&left,node *&right){
	splay(o,k);
	left= o;
	right= o->ch[1];
	o->ch[1]= null;
	o->mt();
}
node *merge(node *left,node *right){
	splay(left,left->s);
	left->ch[1]= right;
	left->mt();
	return left;
}
node *build(int sz){
	if (!sz) return null;
	node *l= build(sz/2);
	node *o= new node(c[++tot]);
	o->ch[0]= l;
	o->ch[1]= build(sz-sz/2-1);
	o->mt();
	return o;
}
int find(node *o,int k){
	o->pushdown();
	int d= o->cmp(k);
	if (d==-1) return o->v;
	return find(o->ch[d],k-(d?o->ch[0]->s+1:0));
}
void change(node *o,int k,int x){
	o->pushdown();	
	int d= o->cmp(k);
	if (d==-1){
		o->v= x;
		o->mt();
		return;
	}change(o->ch[d],k-(d?o->ch[0]->s+1:0),x);
	o->mt();
}
void read(char &c){
	do c= getchar();
	while (c==' '||c=='\n'||c=='\r');
}
void P(int x,int y,int z){
	split(root,x,left,mid);
	split(mid,y-x+1,mid,right);
	mid->z= z;
	//root= merge(left,mid);root= merge(root,right);
	root= merge(merge(left,mid),right);
}
int C(int x,int y){
	int res;
	split(root,x,left,mid);
	split(mid,y-x+1,mid,right);
	res= mid->a;
	root= merge(left,mid);
	root= merge(root,right);
	//root= merge(merge(left,mid),right);
	return res;
}
void print(node *o){
	if (o==null) return;
	o->pushdown();
	print(o->ch[0]);
	printf("%d ",o->v);
	print(o->ch[1]);
}
void Print(){
	print(root);
	printf("\n");
}
int main()
{
	null= new node(0);
	scanf("%d %d",&n, &x);	
	for (i= 1;i<=n;i++) scanf("%d",&c[i+1]);
	c[1]= c[2];
	root= build(n+1);
	scanf("%d",&q);
	for (int a1= 1;a1<=q;a1++){
		read(ch);
		if (ch=='R'){
			scanf("%d",&x);
			split(root,1,left,mid);
			split(mid,n-x,mid,right);
			root= merge(merge(left,right),mid);
			change(root,1,find(root,2));//
		}else if (ch=='F'){
			if (n<=2) continue;
			if (n&1){
				split(root,2,left,mid);
				split(mid,n/2,mid,right);
				mid->flip^= 1;
				right->flip^= 1;
				//mid->pushdown();right->pushdown();
				root= merge(left,right);
				root= merge(root,mid);
				//root= merge(merge(left,right),mid);
				change(root,1,find(root,2));//				
			}else {
				split(root,2,left,mid);
				split(mid,n/2-1,mid,o);
				split(o,1,o,right);
				mid->flip^= 1;
				right->flip^= 1;
				//mid->pushdown();right->pushdown();
				root= merge(merge(merge(left,right),o),mid);
				change(root,1,find(root,2));//								
			}
		}else if (ch=='S'){
			scanf("%d %d",&x, &y);
			x++;y++;
			xx= find(root,x);yy= find(root,y);
			if (xx!=yy){
				change(root,x,yy);
				change(root,y,xx);
				change(root,1,find(root,2));//								
			}
		}else if (ch=='P'){
			scanf("%d %d %d",&x, &y, &z);
			if (x<=y){
				P(x,y,z);
			}else {
				P(x,n,z);
				P(1,y,z);
			}change(root,1,find(root,2));//				
		}else if (ch=='C'){
			ch= getchar();
			if (ch=='\n'||ch=='\r'){
				ans= root->a;
				if (find(root,2)==find(root,n+1)) ans--;
				if (!ans) ans= 1;
				printf("%d\n",ans);
			}else {
				scanf("%d %d",&x, &y);
				if (x<=y){
					ans= C(x,y);
				}else {
					ans= C(x,n);
					ans+= C(1,y);
					if (find(root,2)==find(root,n+1)) ans--;
				}printf("%d\n",ans);
			}			
		}//Print();
	}return 0;
}
