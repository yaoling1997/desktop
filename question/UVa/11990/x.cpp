#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring>
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
	void clear(int x){r=rand();s=0;v=x,ch[0]=ch[1]=null;}
	void mt(){
		s= ch[0]->s+ch[1]->s+1;
	}
	node (int x=0):v(x){
		r= rand();s= 0;
		ch[0]= ch[1]= null;
	}
}ff[maxn*10];
int tot;
node *a[maxn];
int c[maxn],c1[maxn],c2[maxn],e[maxn],d[maxn],zx[maxn],zz[maxn],t[maxn];
int ans,an,n,m,i,x,sum,sum1;
int lowbit(int o){return o&(-o);}
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null){o=&ff[++tot];o->clear(x);o->mt();}
	else {
		int d= o->cmp(x);
		insert(o->ch[d],x);if (o->ch[d]->r > o->r) rotate(o,d^1);
	}o->mt();
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
void add(int o){
	int x= zx[o];
	while (o<=n){
		insert(a[o],x);
		o+= lowbit(o);
	}
}
int count(node *o,int x){
	if (o==null) return 0;
	int y= 0,d= o->cmp(x);
	if (d==-1) return o->ch[0]->s+1;
	if (d) y+= o->ch[0]->s+1;
	return y+count(o->ch[d],x);
}
void merge(int p,int q){
	if (q>p){
		int mid= (p+q)>>1,i,j=mid+1,k;
		merge(p,mid);merge(mid+1,q);
		for (i= p;i<=q;i++){
			c1[i]= c[i];
			e[i]= d[i];
		}
		for (i= mid+1;i<=q;i++){
			c2[i]= c[i];
			e[i]= d[i];
		}
		i= p;
		for (k= p;k<=q;k++)
			if (j<=q && (c1[i]>c2[j] || i>mid)){
				c[k]= c2[j];
				d[k]= e[j++];
				if (i<=mid) d[k]+= mid-i+1;
			}else {
				c[k]= c1[i];
				d[k]= e[i++];
			}
	}
}
void up(int o){
	int x= o;
	while (o>0){
		if (a[o]!=null){
			int gg= count(a[o],zx[x]);
			sum+= gg;
			ans-= a[o]->s-gg;
		}
		o-= lowbit(o);
	}
	o= x;
	while (o<=n){
		remove(a[o],zx[x]);
		o+= lowbit(o);
	}
}
void down(int o,int x){
	while (o>0){
		if (a[o]!=null)
			sum1+= count(a[o],x);
		o-= lowbit(o);
	}
}
int getint(){
	char ch= getchar();int re= 0;
	while (ch<'0' || ch>'9'){ch= getchar();}
	while(ch>='0' && ch<='9'){re= re*10+ch-'0';ch= getchar();}
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	while(scanf("%d %d",&n, &m)!=EOF){
		ans= 0;memset(d,0,sizeof(d));tot=0;
		for (i= 1;i<=n;i++)	a[i]= null;
		for (i= 1;i<=n;i++){
			x= getint();
			zz[x]= i;
			zx[i]= c[i]= x;
		}
		for (i= 1;i<=n;i++)
			add(i);
		merge(1,n);
		for (i= 1;i<=n;i++) ans+= d[i];
		for (i= 1;i<=m;i++){
			printf("%d\n",ans);
			x= getint();
			x= zz[x];
			sum= sum1= 0;
			up(x);
			down(n,zx[x]);
			ans-= sum1-sum+1;
		}
	}
	return 0;
}
