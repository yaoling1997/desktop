#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 100001;
struct node *null;
struct node{
	node *ch[2];
	int v,d;
};
node *a[maxn];
node c[maxn];
ll ans,z;
int cnt[maxn],l[maxn];
int head[maxn],des[maxn],next[maxn];
int i,n,m,x,top;
node *merge(node *a,node *b){
	if (a==null) return b;
	if (b==null) return a;
	if (a->v < b->v) swap(a,b);
	a->ch[1]= merge(a->ch[1],b);
	if (a->ch[0]->d < a->ch[1]->d) swap(a->ch[0],a->ch[1]);
	a->d= a->ch[1]->d+1;
	return a;
}
void pop(node *&o){
	o= merge(o->ch[0],o->ch[1]);
}
node *dfs(int o){
	int i;	ll sum= a[o]->v;
	cnt[o]= 1;
	for (i= head[o];i;i= next[i]){
		int v= des[i];
		a[o]= merge(a[o],dfs(v));
		cnt[o]+= cnt[v];sum+= z;
	}
	while (sum>m){
		sum-= a[o]->v;cnt[o]--;
		pop(a[o]);
	}
	if (ans<(long long)cnt[o]*l[o])
		ans= max(ans,(long long)cnt[o]*l[o]);
	z= sum;
	return a[o];
}
int getint(){
	char ch= getchar();int re= 0;
	while (ch<'0' || ch>'9') ch= getchar();
	while (ch>='0' && ch<='9'){re= re*10+ch-'0';ch= getchar();}
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node();null->d= -1;null->ch[0]= null->ch[1]= null;
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		c[i].ch[0]= c[i].ch[1]= null;
	for (i= 1;i<=n;i++){
		a[i]= &c[i];
		x= getint();
		a[i]->v= getint();
		l[i]= getint();
		//scanf("%d %d %d",&x, &a[i]->v, &l[i]);
		next[++top]= head[x];head[x]= top;des[top]= i;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
