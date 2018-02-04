#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 6e5,oo= 1e9+76543221;
struct node *null;
struct node{
	node *ch[2];
	int v,s,flip,sum,z,l,m,r;
	int cmp(int k){
		int d= ch[0]->s;
		if (d+1==k) return -1;
		return k>d+1;
	}
	void mt(){
		s= ch[0]->s+ch[1]->s+1;
		int i,S[2]= {0},L[2],M[2],R[2];
		for (i= 0;i<=1;i++)
			L[i]= M[i]= R[i]= -oo;
		for (i= 0;i<=1;i++){
			if (ch[i]->z==oo){
				L[i]= ch[i]->l;
				M[i]= ch[i]->m;
				R[i]= ch[i]->r;
				S[i]+= ch[i]->sum;
			}else {
				int x= max(ch[i]->z,ch[i]->z*ch[i]->s);
				L[i]= M[i]= R[i]= x;
				S[i]+= ch[i]->z*ch[i]->s;
			}
			if (ch[i]->flip) swap(L[i],R[i]);
		}
		l= max(L[0],S[0]+v+max(0,L[1]));
		m= max(M[0],M[1]);
		m= max(m,max(0,R[0])+v+max(0,L[1]));
		r= max(R[1],max(0,R[0])+v+S[1]);
		sum= S[0]+S[1]+v;
	}
	void pushdown(){
		if (z!=oo){
			v= z;
			sum= s*z;
			l= m= r= max(z,sum);
			if (ch[0]!=null) ch[0]->z= z;
			if (ch[1]!=null) ch[1]->z= z;
			z= oo;
		}
		if (flip){
			flip= 0;
			swap(ch[0],ch[1]);
			if (ch[0]!=null) ch[0]->flip^= 1;
			if (ch[1]!=null) ch[1]->flip^= 1;
		}
	}
	void clear(){
		v= s= flip= sum= 0;
		z= oo;
		l= m= r= -oo;
		ch[0]= ch[1]= null;
	}
	node(int x):v(x),s(0),flip(0),sum(0),z(oo),l(-oo),m(-oo),r(-oo){
		ch[0]= ch[1]= null;
	}
};
node *stack[maxn];
char s[20];
int c[maxn];
node *root,*left,*mid,*right;
int n,m,i,j,x,y,z,la,top;
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
			else rotate(o->ch[d],d);
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
	left= o;
	right= o->ch[1];
	o->ch[1]= null;
	o->mt();
}
node *build(int sz){
	if (!sz) return null;
	node *l= build(sz/2);
	node *o;
	if (la){
		o= stack[la--];
		o->clear();
		o->v= c[top++];
	}else o= new node(c[top++]);
	o->ch[0]= l;
	o->ch[1]= build(sz-sz/2-1);
	o->mt();
	return o;
}
void recover(node *o){
	if (o==null) return;
	recover(o->ch[0]);
	stack[++la]= o;
	recover(o->ch[1]);
}
int main()
{
	null= new node(0);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	root= build(n+1);
	for (i= 1;i<=m;i++){
		scanf("%s",s+1);
		if (s[1]=='I'){//insert
			scanf("%d%d",&x, &y);
			if (y==0) continue;
			top= 1;
			for (j= 1;j<=y;j++)
				scanf("%d",&c[j]);
			mid= build(y);
			split(root,x+1,left,right);
			root= merge(merge(left,mid),right);
		}else if (s[1]=='D'){//delete
			scanf("%d%d",&x, &y);
			if (y==0) continue;			
			split(root,x,left,mid);
			split(mid,y,mid,right);
			recover(mid);
			root= merge(left,right);
		}else if (s[1]=='R'){//reverse
			scanf("%d%d",&x, &y);
			if (y==0) continue;			
			split(root,x,left,mid);
			split(mid,y,mid,right);
			mid->flip^= 1;
			root= merge(merge(left,mid),right);
		}else if (s[1]=='G'){//get-sum
			scanf("%d%d",&x, &y);
			if (y==0){
				printf("0\n");
				continue;
			}			
			split(root,x,left,mid);
			split(mid,y,mid,right);
			printf("%d\n",mid->sum);
			root= merge(merge(left,mid),right);
		}else if (s[3]=='K'){//make-same
			scanf("%d%d%d",&x, &y, &z);
			if (y==0) continue;			
			split(root,x,left,mid);
			split(mid,y,mid,right);
			mid->z= z;
			root= merge(merge(left,mid),right);
		}else{//max-sum
			split(root,1,left,right);
			printf("%d\n",right->m);
			root= merge(left,right);
		}
	}return 0;
}
