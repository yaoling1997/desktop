#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 30000,oo=1e8,L= 0,R= oo,base= 3000;
vector<int> g[maxn];
int a[maxn],b[maxn],X[maxn],stack[maxn];
int n,i,l,r,bl,time,la,cnt;
void init(int n){
	time++;la= cnt= 0;
	for (i= 1;i<=n;i++)
		g[i].clear(),g[i+base].clear();
}
void link(int mid){
	int i,j;init(n);
	for (i= 1;i<=n;i++)
		for (j= i+1;j<=n;j++){
			if (abs(a[i]-a[j])<mid){
				g[i].push_back(j+base);
				g[j].push_back(i+base);cnt+= 2;
			}
			if (abs(a[i]-a[j+base])<mid){
				g[i].push_back(j);
				g[j+base].push_back(i+base);cnt+= 2;
			}
			if (abs(a[i+base]-a[j])<mid){
				g[i+base].push_back(j+base);
				g[j].push_back(i);cnt+= 2;
			}
			if (abs(a[i+base]-a[j+base])<mid){
				g[i+base].push_back(j);
				g[j+base].push_back(i);cnt+= 2;
			}
		}
}
bool dfs(int o){
	if (b[X[o]]==time) return 0;
	if (b[o]==time) return 1;
	b[o]= time;stack[++la]= o;
	int i,len= g[o].size();
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!dfs(v))return 0;
	}return 1;
}
bool solve(int n){
	int i;
	for (i= 1;i<=n;i++)
		if (!dfs(i)){
			while (la) b[stack[la--]]= 0;
			if (!dfs(X[i])) return 0;
		}
	return 1;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		for (i= 1;i<=n;i++){
			scanf("%d %d",&a[i], &a[i+base]);
			X[i]= i+base;X[i+base]= i;
		}
		l= L;r= R;
		while (l+1<r){
			int mid= (l+r)>>1;
			link(mid);
			bl= solve(n);
			if (bl) l= mid;
			else r= mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
