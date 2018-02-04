#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 6e5,base= 1e5+1,oo= 1e8;
struct edge{
	int x,y,b;
}L[maxn];
vector<int> g[maxn];
char s[10];
int b[maxn],X[maxn],B[maxn],sta[maxn];
int n,m,i,j,x,y,z,la,ans,now;
bool dfs(int o){
	if (b[X[o]]) return 0;
	if (b[o]) return 1;
	b[o]= 1;sta[++la]= o;
	if (o>base) now++;
	int i,len= g[o].size();
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!dfs(v))
			return 0;
	}
	return 1;
}
bool solve(int n){
	memset(b,0,sizeof(b));	
	int re= 0,x;
	for (i= 1;i<=n;i++)
		if (!b[i]&&!b[X[i]]){
			now= 0;
			la= 0;			
			if (!dfs(i)){
				now= 0;				
				while (la) b[sta[la--]]= 0;
				if (!dfs(X[i])) return 0;
				re+= now;
			}else {
				x= now;
				now= 0;
				while (la) b[sta[la--]]= 0;
				if (!dfs(X[i])||now>x){
					now= 0;
					while (la) b[sta[la--]]= 0;
					dfs(i);
				}
				re+= now;								
			}
		}
	if (re<ans){
		ans= re;
		memcpy(B,b,sizeof(b));
	}
	return 1;
}
void get(int o){
	int i,x,y;
	for (i= 1;i<=n;i++){
		g[i].clear();
		g[i+base].clear();
	}
	for (i= 1;i<=m;i++){
		x= L[i].x;
		y= L[i].y;
		if (L[i].b==o){
			g[x].push_back(y);
			g[y].push_back(x);
			g[X[x]].push_back(X[y]);
			g[X[y]].push_back(X[x]);			
		}else {
			g[x].push_back(X[y]);
			g[y].push_back(X[x]);
			g[X[x]].push_back(y);
			g[X[y]].push_back(x);						
		}
	}
	solve(n);
}
void init(int n){
	for (i= 1;i<=n;i++){
		g[i].clear(),g[i+base].clear();
		X[i]= i+base,X[i+base]= i;
	}
	ans= oo;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	init(n);
	for (i= 1;i<=m;i++){
		scanf("%d%d%s",&x, &y, s+1);
		if (s[1]=='B') z= 0;
		else z= 1;
		L[i]= (edge){x,y,z};
	}
	get(0);
	get(1);
	if (ans==oo) printf("-1");
	else {
		printf("%d\n",ans);
		x= 0;
		for (i= 1;i<=n;i++)
			if (B[X[i]]){
				x++;
				printf("%d%c",i, x<ans?' ':'\n');
			}
	}
	return 0;
}