#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
const int maxn= 60001,oo= 1e9;
struct node *null;
struct node{
	node *ch[2];
	int v,s,r;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){
		s= 1+ch[0]->s+ch[1]->s;
	}
	node(int x):v(x),s(0),r(rand()){ch[0]= ch[1]= null;}
};
node *a[maxn];
int c[maxn];
int n,m,x,y,z,i,sum,sum1,ans;
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null){o= new node(x);}
	else {
		int d= o->cmp(x);
		if (d) d=1;
		insert(o->ch[d],x);if (o->ch[d]->r > o->r) rotate(o,d^1);
	}
	o->mt();
}
void remove(node *&o,int x){
	int d= o->cmp(x);
	if (d==-1){
		if (o->ch[0]==null) o= o->ch[1];
		else if (o->ch[1]==null) o= o->ch[0];
		else {
			int d2= (o->ch[0]->r > o->ch[1]->r);
			rotate(o,d2);remove(o->ch[d2],x);
		}
	}else remove(o->ch[d],x);
	if (o!=null) o->mt();
}
int lowbit(int o){return o&(-o);}
void add(int o,int x){
	while (o<=n){
		insert(a[o],x);
		o+= lowbit(o);
	}
}
int count(node *o,int x){
	if (o==null) return 0;
	int d= o->cmp(x),y= 0;
	if (d==-1) d= 0;
	if (d==1) y= o->ch[0]->s+1;
	return y+count(o->ch[d],x);
}
void find(int o,int x,int &re){
	re= 0;
	while (o){
		re+= count(a[o],x);
		o-= lowbit(o);
	}
}
void find1(int x,int y,int k,int &ans){
	int l=0,r= oo;
	while (l+1<r){
		int mid= (l+r)>>1;
		find(x-1,mid,sum);
		find(y,mid,sum1);
		if (sum1-sum>k-1) r= mid;
		else l= mid; 
	}
	ans= l;
}
void change(int o,int x){
	int y= c[o];
	while (o<=n){
		remove(a[o],y);
		insert(a[o],x);
		o+= lowbit(o);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	scanf("%d %d",&n, &m);
	for (i= 0;i<=n;i++)
		a[i]= null;
	for (i= 1;i<=n;i++){
		scanf("%d",&c[i]);
		add(i,c[i]);
	}
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d %d",&x, &y, &z);
			find(x-1,z,sum);
			find(y,z,sum1);
			printf("%d\n",sum1-sum+1);
		}else if (x==2){
			scanf("%d %d %d",&x, &y, &z);
			find1(x,y,z,ans);
			printf("%d\n",ans);
		}else if (x==3){
			scanf("%d %d\n",&x, &y);
			change(x,y);
			c[x]= y;
		}else if (x==4){
			scanf("%d %d %d",&x, &y, &z);
			find(x-1,z,sum);
			find(y,z,sum1);
			find1(x,y,sum1-sum,ans);
			printf("%d\n",ans);
		}else {
			scanf("%d %d %d",&x, &y, &z);
			z++;
			find(x-1,z,sum);
			find(y,z,sum1);
			find1(x,y,sum1-sum+1,ans);
			printf("%d\n",ans);
		}
	}
	return 0;
}
