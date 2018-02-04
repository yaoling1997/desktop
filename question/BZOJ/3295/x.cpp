#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 200001;
struct node *null;
struct node{
	node *ch[2];
	int v,s,r;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){s= ch[0]->s+ch[1]->s+1;}
	node(int x):v(x),s(0),r(rand()){ch[0]= ch[1]= null;}
};
node *a[maxn];
int c[maxn],c1[maxn],c2[maxn],zx[maxn],zy[maxn];
ll e[maxn],d[maxn];
int n,m,i,j,x;
ll ans,sum1,sum2;
void merge(int p,int q){
	if (p==q) return;
	int mid= (p+q)>>1,i,j= mid+1,k;
	merge(p,mid);merge(mid+1,q);
	for (i= p;i<=mid;i++){
		c1[i]= c[i];
		e[i]= d[i];
	}
	for (i= mid+1;i<=q;i++){
		c2[i]= c[i];
		e[i]= d[i];
	}
	i= p;
	for (k= p;k<=q;k++)
		if (j<=q && (i>mid || c1[i]>c2[j])){
			c[k]= c2[j];
			d[k]= e[j++]+mid-i+1;
		}else {
			c[k]= c1[i];
			d[k]= e[i++];
		}
}
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null){o= new node(x);}
	else {
		int d= o->cmp(x);
		if (d==-1) d=1;
		insert(o->ch[d],x);
		if (o->ch[d]->r > o->r) rotate(o,d^1);
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
int count2(node *o,int x){
	if (o==null) return 0;
	int d= o->cmp(x);
	if (d==-1) d= 1;
	if (!d) return o->ch[1]->s+1+count2(o->ch[0],x);
	else return count2(o->ch[1],x);
}
int count1(node *o,int x){
	if (o==null) return 0;
	int d= o->cmp(x);
	if (d==-1) d= 0;
	if (d) return o->ch[0]->s+1+count1(o->ch[1],x);
	else return count1(o->ch[0],x);
}
int lowbit(int o){return o&(-o);}
void add(int o,int x){
	while (o<=n){
		insert(a[o],x);
		o+= lowbit(o);
	}
}
int ma(int o,int x){
	int re= 0;int o1= o;
	while (o){
		re+= count1(a[o],x);
		ans-= count2(a[o],x);
		o-= lowbit(o);
	}
	o= o1;
	while (o<=n){
		remove(a[o],x);
		o+= lowbit(o);
	}return re;
}
int mi(int o,int x){
	int re= 0;
	while (o){
		re+= count1(a[o],x);
		o-= lowbit(o);
	}return re;
}
int getint(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9') c= getchar();
	while (c>='0' && c<='9') re= re*10+c-'0',c= getchar();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	while (scanf("%d %d\n",&n, &m)!=EOF){
		ans= 0;for (i= 1;i<=n;i++) d[i]= 0;
		for (i= 1;i<=n;i++)
			a[i]= null;
		for (i= 1;i<=n;i++){
			scanf("%d",&c[i]);
			zx[i]= c[i];
			zy[c[i]]= i;
			add(i,c[i]);
		}
		merge(1,n);
		for (i= 1;i<=n;i++) ans+= d[i];
		for (i= 1;i<=m;i++){
			printf("%lld\n",ans);
			scanf("%d",&x);
			x= zy[x];
			sum1= ma(x,zx[x]);
			sum2= mi(n,zx[x]);
			ans-= sum2-sum1;
		}
	}
	return 0;
}
