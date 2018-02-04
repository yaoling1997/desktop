#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn= 3000001,maxl= 30000,sig= 100;
struct node{
	int ch[sig+1];
	int v;
};
char s[200][100],st[maxn];
node a[maxl];
int F[maxl],last[maxl],f[maxn],d[maxn];
int tot,n,i,Max;
void init(){
	int i;
	for (i= 1;i<=n;i++)
		f[i]= i;
	tot= Max= 0;
	memset(a,0,sizeof(a));
	memset(F,0,sizeof(F));
	memset(d,0,sizeof(d));
	memset(last,0,sizeof(last));
}
int idx(char c){return c-'a';}
void add(char *s,int o){
	int len= strlen(s+1),i,now= 0;
	for (i= 1;i<=len;i++){
		int c= idx(s[i]);
		if (a[now].ch[c]) now= a[now].ch[c];
		else {
			a[now].ch[c]= ++tot;
			now= tot;
		}
	}
	if (a[now].v) f[o]= a[now].v;
	else a[now].v= o;
}
void getFail(){
	queue<int> l;
	int c;
	for (c= 0;c<=sig;c++)
		if (a[0].ch[c])
			l.push(a[0].ch[c]);
	while (!l.empty()){
		int u= l.front();l.pop();
		for (c= 0;c<=sig;c++)
			if (a[u].ch[c]){
				int v= a[u].ch[c],o;
				o= F[u];
				while (o&&!a[o].ch[c]) o= F[o];
				F[v]= a[o].ch[c];
				last[v]= a[F[v]].v ? F[v]:last[F[v]];
				l.push(v);
			}
	}
}
void inc(int o){
	while (o){
		if (a[o].v)
			d[a[o].v]++;
		o= last[o];
	}
}
void find(char *s){
	int len= strlen(s+1),i,j= 0;
	for (i= 1;i<=len;i++){
		int c= idx(s[i]);
		while (j&&!a[j].ch[c]) j= F[j];
		j= a[j].ch[c];
		if (a[j].v) inc(j);
		else inc(last[j]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%s",s[i]+1);
			add(s[i],i);
		}
		getFail();
		scanf("%s",st+1);
		find(st);
		for (i= 1;i<=n;i++)
			Max= max(Max,d[i]);
		printf("%d\n",Max);
		for (i= 1;i<=n;i++)
			if (d[f[i]]==Max)
				printf("%s\n",s[i]+1);
	}
	return 0;
}
