#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn= 3001,maxl= 500,sig= 200;
struct node{
	int ch[sig+1];
};
char s[maxn];
node a[maxl];
int b[sig],F[maxl],match[maxl],vis[maxl][sig];
double c[sig],f[maxl][sig];
char ch;
double ans;
int tot,L,T,K,i,n,ooo;
int idx(char c){return c;}
void add(char *s){
	int len= strlen(s+1),i,now= 0;
	for (i= 1;i<=len;i++){
		int c= idx(s[i]);
		if (a[now].ch[c]) now= a[now].ch[c];
		else {
			a[now].ch[c]= ++tot;
			now= tot;
		}
	}
	match[now]= 1;
}
void getFail(){
	int c;
	queue<int> l;
	for (c= 0;c<sig;c++)
		if (a[0].ch[c])
			l.push(a[0].ch[c]);
	while (!l.empty()){
		int o= l.front();l.pop();
		for (c= 0;c<sig;c++){
			int u= a[o].ch[c];
			if (!u){
				a[o].ch[c]= a[F[o]].ch[c];
				continue;
			}
			int v= F[o];
			while (v && !a[v].ch[c]) v= F[v];
			F[u]= a[v].ch[c];
			match[u]|= match[F[u]];
			l.push(u);			
		}
	}
}
double dfs(int o,int l){
	if (!l) return 1;
	if (vis[o][l]) return f[o][l];
	vis[o][l]= 1;
	int i;
	double re= 0;
	for (i= 0;i<=sig;i++)
		if (b[i]){
			if (match[a[o].ch[i]]!=1)
				re+= c[i]*dfs(a[o].ch[i],l-1);
			ooo++;
		}
	return f[o][l]= re;
}
void init(){
	tot= 0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(f,-1,sizeof(f));
	memset(F,0,sizeof(F));
	memset(vis,0,sizeof(vis));
	memset(match,0,sizeof(match));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&K);
		init();
		for (i= 1;i<=K;i++){
			scanf("%s",s+1);
			add(s);
		}
		scanf("%d\n",&n);
		for (i= 1;i<=n;i++){
			scanf("%c",&ch);
			b[ch]= 1;
			scanf("%lf\n",&c[ch]);
		}
		getFail();
		scanf("%d",&L);
		ans= dfs(0,L);
		printf("Case #%d: %.6lf\n",a1, ans);
	}
	return 0;
}
