#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int oo= 1e9;
struct edge{
	int v,w;
};
struct point{
	int x,y;
}Y[600];
struct out{
	int x,y,z;
}O[60];
vector<edge> g[60];
vector<int> s[60],t[60];
int M[60],X[60][60],lx[60],ly[600],S[60],T[600],d[600],e[60];
int W[60][60];
double ans;
int m,n,i,j,x,y,z,K,tot,k,cnt;
void init(){
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	int i;
	for (i= 1;i<=n;i++){
		s[i].clear();
		t[i].clear();
		g[i].clear();
	}
	tot= 0;
}
bool match(int o){
	S[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v,w= g[o][i].w;
		if (!T[v]&&lx[o]+ly[v]==w){
			T[v]= 1;
			if (!d[v]||match(d[v])){
				d[v]= o;
				e[o]= v;
				return 1;
			}
		}
	}return 0;
}
void update(){
	int a= oo;
	int i,j;
	for (i= 1;i<=n;i++)
		if (S[i]){
			int len= g[i].size();
			for (j= 0;j<len;j++){
				int v= g[i][j].v,w= g[i][j].w;
				if (!T[v])
					a= min(a,lx[i]+ly[v]-w);
			}
		}
	for (i= 1;i<=n;i++)
		if (S[i]) lx[i]-= a;		
	for (i= 1;i<=tot;i++)
		if (T[i])
			ly[i]+= a;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int beginT= clock();
	while (scanf("%d%d",&m, &n)>0){
		if (!m||!n) break;
		cnt++;
		if (cnt!=1) printf("\n");
		printf("Case %d\n",cnt);
		init();
		for (i= 1;i<=m;i++)
			scanf("%d",&M[i]);
		for (i= 1;i<=n;i++){
			scanf("%d",&K);
			for (j= 1;j<=K;j++){
				scanf("%d%d",&x, &y);
				s[i].push_back(x);
				t[i].push_back(y);
			}
		}
		for (i= 1;i<=n;i++){
			int len= s[i].size();
			for (j= 1;j<=m;j++){
				int bl= 0;
				for (k= len-1;k>=0;k--)
					if (s[i][k]<=M[j]){
						bl= 1;
						W[i][j]= t[i][k];
						break;
					}
				if (!bl) W[i][j]= oo/50;
			}
		}
		for (i= 1;i<=m;i++)
			for (j= 1;j<=n;j++){
				tot++;
				Y[tot]= (point){i,j};
				X[i][j]= tot;
				for (k= 1;k<=n;k++)
					g[k].push_back((edge){tot,-W[k][i]*j});
			}
		memset(ly,0,sizeof(ly));
		for (i= 1;i<=n;i++){
			lx[i]= -oo;
			int len= g[i].size(),j;
			for (j= 0;j<len;j++)
				lx[i]= max(lx[i],g[i][j].w);
		}
		for (i= 1;i<=n;i++)
			for (;;){
				for (j= 1;j<=n;j++) S[j]= 0;
				for (j= 1;j<=tot;j++) T[j]= 0;
				if (match(i)) break;
				else update();
			}
		ans= 0;
		for (i= 1;i<=n;i++)
			ans+= lx[i]+ly[e[i]];
		ans*= -1;
		ans/= n;
		printf("Average turnaround time = %.2lf\n",ans);
		for (i= 1;i<=m;i++){
			int now= 0;
			for (j= n;j>0;j--){
				int v= X[i][j];
				if (d[v]){
					O[d[v]].x= i;
					O[d[v]].y= now;
					now+= W[d[v]][i];
					O[d[v]].z= now;
				}
			}
		}
		for (i= 1;i<=n;i++){
			x= O[i].x;
			y= O[i].y;
			z= O[i].z;
			printf("Program %d runs in region %d from %d to %d\n",i, x, y, z);			
		}
		/*for (i= 1;i<=n;i++){
			int u= e[i];
			x= Y[u].x;
			y= z= 0;
			for (j= 1;j<Y[u].y;j++){
				int s= W[d[X[x][j]]][x];
				y+= s;
			}			
			z= y+W[i][x];
			printf("Program %d runs in region %d from %d to %d\n",i, x, y, z);
			}*/
		
	}
	int endT= clock();
	//printf("%.2lf\n",(endT-beginT)/1000.0);
	return 0;
}
