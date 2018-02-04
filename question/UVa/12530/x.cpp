#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 300001;
vector<int> g[maxn];
char s[100][100];
int vis[maxn],d[maxn],map[100][100];
int R,C,tim,i,j,k,ans,cnt,pp,tot;
void init(){
	memset(map,0,sizeof(map));
}
bool ok(int x,int y){
	if (x<1||y<1||x>R||y>C) return 0;
	if (s[x][y]=='X') return 0;
	return 1;
}
void color(int x,int y,int z){
	cnt++;
	int o= map[x][y]= ++tot;
	if (ok(x+1,y)&&!map[x+1][y]){
		color(x+1,y,z^1);
	}
	if (ok(x-1,y)&&!map[x-1][y]){
		color(x-1,y,z^1);
	}
	if (ok(x,y+1)&&!map[x][y+1]){
		color(x,y+1,z^1);
	}
	if (ok(x,y-1)&&!map[x][y-1]){
		color(x,y-1,z^1);
	}
	if (z){
		if (ok(x+1,y)) g[o].push_back(map[x+1][y]);
		if (ok(x-1,y)) g[o].push_back(map[x-1][y]);
		if (ok(x,y+1)) g[o].push_back(map[x][y+1]);
		if (ok(x,y-1)) g[o].push_back(map[x][y-1]);
	}
}
bool find(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (vis[v]!=tim){
			vis[v]= tim;
			if (!d[v]||find(d[v])){
				d[v]= o;
				return 1;
			}
		}
	}return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d",&R, &C)>0){
		init();
		ans= 2;
		for (i= 1;i<=R;i++)
			scanf("%s",s[i]+1);
		for (i= 1;i<=R;i++)
			for (j= 1;j<=C;j++)
				if (s[i][j]=='.'&&!map[i][j]){
					cnt= pp= 0;
					while (tot){
						g[tot].clear();
						d[tot--]= 0;
					}
					color(i,j,1);
					if (cnt&1){
						ans= 1;
						goto pn;
					}
					for (k= 1;k<=tot;k++){
						tim++;
						if (find(k)) pp++;
					}
					if (pp*2!=cnt){
						ans= 1;
						goto pn;
					}
				}
	pn:printf("%d\n",ans);
	}
	//printf("ok");
	return 0;
}
