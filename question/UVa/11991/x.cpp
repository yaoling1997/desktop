#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2e6;
vector<int> G[maxn];
int a[maxn];
int n,m,x,y,z,k,v,i,M;
void init(){
	M= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d",&n, &m)>0){		
		for (i= 1;i<=n;i++){
			scanf("%d",&a[i]);
			M= max(M,a[i]);			
		}
		for (i= 1;i<=M;i++)
			G[i].clear();
		for (i= 1;i<=n;i++)
			G[a[i]].push_back(i);
		for (i= 1;i<=m;i++){
			scanf("%d%d",&k, &v);
			if ((int)G[v].size()<k) printf("0\n");
			else printf("%d\n",G[v][k-1]);
		}
	}return 0;
}
