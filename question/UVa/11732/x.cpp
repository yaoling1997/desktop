#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 20000,maxl= 1e7;
char s[maxn];
ll size[maxl];
int head[maxl],next[maxl],ch[maxl];
ll ans;
int i,j,n,tot,cnt;
int idx(char c){return c;}
void add(char *s){
	int len= strlen(s+1),i,now= 0;
	for (i= 1;i<=len;i++){
		int c= idx(s[i]),bl= 0;
		for (j= head[now];j;j= next[j])
			if (ch[j]==c){
				bl= 1;
				break;
			}
		if (bl) size[now= j]++;
		else {
			next[++tot]= head[now];
			head[now]= tot;
			ch[tot]= c;
			size[now= tot]++;
		}
	}
}
void dfs(int o){
	ll sum= 0;
	int i;
	for (i= head[o];i;i= next[i]){
		sum+= size[i];
		ans+= size[i]*(size[i]-1);
	}
	for (i= head[o];i;i= next[i]){
		sum-= size[i];
		ans+= sum*size[i];
		dfs(i);
	}
}
void init(){
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(size,0,sizeof(ch));
	ans= tot= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		cnt++;
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%s",s+1);
			int len= strlen(s+1);
			s[len+1]= '!';s[len+2]= '\0';
			add(s);
		}
		dfs(0);
		printf("Case %d: %lld\n",cnt, ans);
	}
	return 0;
}
