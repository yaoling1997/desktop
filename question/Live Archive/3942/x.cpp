#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 400000,maxl= 500000,mo= 20071027;
char s[maxn],st[maxn];
int head[maxn],next[maxl],ch[maxl],bb[maxl],f[maxn];
int len,tot,n,i,cnt;
int idx(char c){return c-'a';}
void add(char *s){
	int len= strlen(s+1),i,j,now= 0;
	for (i= 1;i<=len;i++){
		int c= idx(s[i]),bl= 0;
		if (head[now])
			for (j= head[now];j;j= next[j])
				if (ch[j]==c){
					bl= 1;
					break;
				}
		if (bl) now= j;
		else {
			next[++tot]= head[now];
			head[now]= tot;
			ch[tot]= c;
			now= tot;
		}
	}
	bb[now]= 1;
}
int dfs(int o){
	if (f[o]!=-1) return f[o];
	f[o]= 0;
	int now= 0,i,j;
	for (i= o;i<=len;i++){
		int c= idx(st[i]),bl= 0;
		if (head[now])
			for (j= head[now];j;j= next[j])
				if (ch[j]==c){
					bl= 1;
					break;
				}
		if (!bl) break;
		if (bb[j]) f[o]= (f[o]+dfs(o+i-o+1))%mo;
		now= j;
	}
	return f[o];
}
void init(int len){
	memset(f,-1,sizeof(f));
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(bb,0,sizeof(bb));
	tot= 0;f[len+1]= 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%s",st+1)!=EOF){
		cnt++;
		len= strlen(st+1);
		init(len);
		scanf("%d",&n);
		for (i= 1;i<=n;i++){
			scanf("%s",s+1);
			add(s);
		}
		dfs(1);
		printf("Case %d: %d\n",cnt, f[1]);
	}
	return 0;
}
