#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
int P[maxn],b[maxn],st[maxn];
int n,K,i,T,M,ans,la;
void dfs(int o,int sum){
	int i,j,x;
	if (o>K){
		ans= max(ans,sum);
		return;
	}
	if (P[o]*P[o]>n){
		for (i= o;i<=K;i++){
			x= sum;
			for (j= P[i];j<=n;j+= P[i]){
				x+= b[j]?-1:1;
				b[j]^= 1;
			}
			if (x>sum){
				sum= x;
				st[++la]= P[i];
			}
			else for (j= P[i];j<=n;j+= P[i])
					 b[j]^= 1;			
		}
		ans= max(ans,sum);
		while (la){
			for (i= st[la];i<=n;i+= st[la])
				b[i]^= 1;
			la--;
		}
	}else {
		for (i= P[o];i<=n;i+= P[o]){
			sum+= b[i]?-1:1;
			b[i]^= 1;
		}
		dfs(o+1,sum);
		for (i= P[o];i<=n;i+= P[o]){
			sum+= b[i]?-1:1;
			b[i]^= 1;
		}
		dfs(o+1,sum);
	}
}
void init(){
	int i;
	for (i= 1;i<=n;i++)
		b[i]= 0;
	ans= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		scanf("%d%d",&n, &K);
		init();
		for (i= 1;i<=K;i++)
			scanf("%d",&P[i]);
		sort(P+1,P+K+1);
		K= unique(P+1,P+K+1)-P-1;
		dfs(1,0);
		printf("Case #%d: %d\n",t, ans);
	}return 0;
}
