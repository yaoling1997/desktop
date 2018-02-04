#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn= 5e5,sig= 30;
struct node{
	int ch[sig+1];
	int v,fa,last;
	vector<int> X;
};
struct query{
	int x,y;
};
node a[maxn];
query que[maxn];
vector<int> G[maxn],g[maxn];
char s[maxn];
int B[maxn],F[maxn],ans[maxn],c[maxn];
int len,i,tot,top,cnt,now,q,x,y;
int idx(char c){return c-'a';}
void getFail(){
	queue<int> Q;
	int i,j;
	for (i= 0;i<=sig;i++){
		int u= a[0].ch[i];
		if (!u) continue;
		g[0].push_back(u);
		F[u]= 0;
		Q.push(u);
	}
	while (!Q.empty()){
		int u= Q.front();Q.pop();
		for (i= 0;i<=sig;i++){
			int v= a[u].ch[i];
			if (!v) continue;
			Q.push(v);
			j= F[u];
			while (j && !a[j].ch[i]) j= F[j];
			F[v]= a[j].ch[i];
			g[a[j].ch[i]].push_back(v);			
		}
	}
}
void encode(int o){
	a[o].v= a[o].last= ++cnt;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		encode(v);
		a[o].last= a[v].last;
	}
}
int lowbit(int o){return o & (-o);}
void change(int o,int w){
	while (o<=cnt){
		c[o]+= w;
		o+= lowbit(o);
	}
}
int sum(int o){
	int re= 0;
	while (o>0){
		re+= c[o];
		o-= lowbit(o);
	}return re;
}
int get(int l,int r){
	int x= sum(r)-sum(l-1);
	return x;
}
void dfs(int o){
	int i,j,k;
	change(a[o].v,1);
	if (a[o].X.size())
		for (i= 0;i<a[o].X.size();i++){
			j= a[o].X[i];
			for (k= 0;k<G[j].size();k++){
				int u,v;
				u= B[que[G[j][k]].x];
				v= a[u].last;u= a[u].v;
				ans[G[j][k]]= get(u,v);
			}
		}	
	for (i= 0;i<=sig;i++){
		int v= a[o].ch[i];
		if (!v) continue;
		dfs(v);
	}change(a[o].v,-1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	len= strlen(s+1);
	for (i= 1;i<=len;i++){
		if (s[i]=='B'){
			now= a[now].fa;
		}else if (s[i]=='P'){			
			a[now].X.push_back(++top);
			B[top]= now;
		}else {
			int c= idx(s[i]);
			if (a[now].ch[c]) now= a[now].ch[c];
			else {
				a[now].ch[c]= ++tot;
				a[tot].fa= now;
				now= tot;
			}
		}
	}
	scanf("%d",&q);
	for (i= 1;i<=q;i++){
		scanf("%d %d",&x, &y);
		que[i]= (query){x,y};
		G[y].push_back(i);
	}
	getFail();
	encode(0);
	dfs(0);
	for (i= 1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
