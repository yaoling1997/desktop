#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn= 110,maxl= 300,oo= 1e8;
struct query{
	int x1,y1,x2,y2,b;
};
struct node{
	int i,j,k,d;
	bool operator <(const node &a)const{
		return i>a.i||(i==a.i&&d>a.d);
	}
};
struct pre{
	int i,j,k,o;
};
query Q[maxn],A[maxn],B[maxn];
pre g[maxn][maxn][maxn];
char s[maxl];
int X[maxn],Y[maxn],X1[maxn],Y1[maxn],ran[maxn],ran1[maxn];
int a[maxn],b[maxn],fx[maxn],fy[maxn],c[maxn],c1[maxn],c2[maxn],use[maxn][maxn][maxn],vis[maxn][maxn][maxn],f[maxn][maxn][maxn];
int n,m,i,ans,K,tot,t1,t2,time,x1,x2,x3,x4;
int cost(int i){
	return (b[i]!=Y[i])*Y1[i];
}
void get(int i,int j,int k){
	pre u= g[i][j][k];
	fy[i]= u.o;
	if (i==0) return;
	get(u.i,u.j,u.k);
}
void go(int s){
	int i,j,k,d,x,x1,x2,y,y1,y2,p,q,z1,z2,bl;
	t1= t2= 0;time++;
	for (i= 0;i<=n;i++) b[i]= c[i]= ran[i]= ran1[i]= c1[i]= c2[i]= 0;
	for (i= 1;i<=K;i++) Q[i].b= 0;
	for (i= 1;i<=K;i++){
		x1= Q[i].x1;x2= Q[i].x2;
		y1= Q[i].y1;y2= Q[i].y2;
		y= y2-y1;x= x2-x1;z1= min(x1,x2);z2= max(x1,x2);
		if (x>0) q= 1;
		else q= -1;
		if (y>0){
			p= 1;
			if (x==0){
				if (a[x1]==-1) return;
				else {
					c[i]= 1;
					continue;
				}
			}
			if (a[x1]==p){
				if (a[x2]==-p){
					if (!b[y2]) b[y2]= q,c[i]= 1;
					else if (b[y2]!=q) return;
					else c[i]= 1;
				}else Q[i].b= q;
			}else {
				if (a[x2]==p){
					if (!b[y1]) b[y1]= q,c[i]= 1;
					else if (b[y1]!=q) return;
					else c[i]= 1;
				}else {
					if (!b[y1]) b[y1]= q;
					else if (b[y1]!=q) return;
					if (!b[y2]) b[y2]= q;
					else if (b[y2]!=q) return;
					bl= 0;
					for (j= z1;j<=z2;j++)
						if (a[j]==p){
							bl= 1;
							break;
						}
					if (!bl) return;
					c[i]= 1;
				}
			}
		}else if (y<0){
			p= -1;
			if (x==0){
				if (a[x1]==1) return;
				else {
					c[i]= 1;
					continue;
				}
			}
			if (a[x1]==p){
				if (a[x2]==-p){
					if (!b[y2]) b[y2]= q,c[i]= 1;
					else if (b[y2]!=q) return;
					else c[i]= 1;
				}else Q[i].b= q;
			}else {
				if (a[x2]==p){
					if (!b[y1]) b[y1]= q,c[i]= 1;
					else if (b[y1]!=q) return;
					else c[i]= 1;
				}else {
					if (!b[y1]) b[y1]= q;
					else if (b[y1]!=q) return;
					if (!b[y2]) b[y2]= q;
					else if (b[y2]!=q) return;
					bl= 0;
					for (j= z1;j<=z2;j++)
						if (a[j]==p){
							bl= 1;
							break;
						}
					if (!bl) return;
					c[i]= 1;
				}
			}			
		}else {
			if (!b[y1]) b[y1]= q,c[i]= 1;
			else if (b[y1]!=q) return;
			else c[i]= 1;
		}
	}
	for (i= 1;i<=K;i++)
		if (!c[i]){
			if (Q[i].b==1) A[++t1]= Q[i];
			else B[++t2]= Q[i];
		}
	for (i= 1;i<=t1;i++)
		if (A[i].y1>A[i].y2) swap(A[i].y1,A[i].y2);
	for (i= 1;i<=t2;i++)
		if (B[i].y1>B[i].y2) swap(B[i].y1,B[i].y2);
	for (i= 1;i<=t1;i++)
		for (j= 1;j<=t1;j++){
			if (i==j||c1[j]) continue;
			if (A[i].y1<=A[j].y1&&A[j].y2<=A[i].y2){
				c1[i]= 1;
				break;
			}
		}
	for (i= 1;i<=t2;i++)
		for (j= 1;j<=t2;j++){
			if (i==j||c2[j]) continue;
			if (B[i].y1<=B[j].y1&&B[j].y2<=B[i].y2){
				c2[i]= 1;
				break;
			}
		}
	t1++;t2++;
	A[t1].y1= A[t1].y2= n+1;B[t2].y1= B[t2].y2= n+1;
	for (i= 0;i<=n;i++){
		k= 0;
		for (j= 1;j<=t1;j++){
			if (!c1[j]&&A[j].y1>i&&(!k||A[k].y1>A[j].y1))
				k= j;
		}
		ran[i]= k;
		k= 0;
		for (j= 1;j<=t2;j++){
			if (!c2[j]&&B[j].y1>i&&(!k||B[k].y1>B[j].y1))
				k= j;
		}
		ran1[i]= k;
	}
	priority_queue<node> Q;
	Q.push((node){0,ran[0],ran1[0],0});
	while (!Q.empty()){
		node u= Q.top();
		Q.pop();
		i= u.i,j= u.j,k= u.k,d= u.d;
		if (vis[i][j][k]==time) continue;
		vis[i][j][k]= time;
		if (i==n){
			if (j==t1&&k==t2){
				if (ans>d+s){
					ans= d+s;
					for (x= 1;x<=m;x++)
						fx[x]= a[x];
					get(i,j,k);
				}
				return;
			}continue;
		}
		if (!b[i+1]){
			if (i+1<B[k].y2){
				b[i+1]= 1;
				x= d+cost(i+1);
				if (use[i+1][ran[i+1]][k]!=time||(use[i+1][ran[i+1]][k]==time&&f[i+1][ran[i+1]][k]>x)){
					use[i+1][ran[i+1]][k]= time;
					f[i+1][ran[i+1]][k]= x;
					g[i+1][ran[i+1]][k]= (pre){i,j,k,1};
					Q.push((node){i+1,ran[i+1],k,x});
				}
			}
			if (i+1<A[j].y2){
				b[i+1]= -1;
				x= d+cost(i+1);
				if (use[i+1][j][ran1[i+1]]!=time||(use[i+1][j][ran1[i+1]]==time&&f[i+1][j][ran1[i+1]]>x)){
					use[i+1][j][ran1[i+1]]= time;
					f[i+1][j][ran1[i+1]]= x;
					g[i+1][j][ran1[i+1]]= (pre){i,j,k,-1};	
					Q.push((node){i+1,j,ran1[i+1],x});
				}
			}b[i+1]= 0;
		}else {
			if (b[i+1]==1){
				if (i+1>=B[k].y2) continue;
				x= d+cost(i+1);
				if (use[i+1][ran[i+1]][k]!=time||(use[i+1][ran[i+1]][k]==time&&f[i+1][ran[i+1]][k]>x)){
					use[i+1][ran[i+1]][k]= time;
					f[i+1][ran[i+1]][k]= x;
					g[i+1][ran[i+1]][k]= (pre){i,j,k,1};					
					Q.push((node){i+1,ran[i+1],k,x});
				}
			}else {
				if (i+1>=A[j].y2) continue;
				x= d+cost(i+1);
				if (use[i+1][j][ran1[i+1]]!=time||(use[i+1][j][ran1[i+1]]==time&&f[i+1][j][ran1[i+1]]>x)){
					use[i+1][j][ran1[i+1]]= time;
					f[i+1][j][ran1[i+1]]= x;
					g[i+1][j][ran1[i+1]]= (pre){i,j,k,-1};						
					Q.push((node){i+1,j,ran1[i+1],x});
				}				
			}
		}
	}
}
void dfs(int o,int s){
	if (s>ans) return;
	if (o<=m){
		a[o]= 1;
		dfs(o+1,s+(a[o]!=X[o])*X1[o]);		
		a[o]= -1;
		dfs(o+1,s+(a[o]!=X[o])*X1[o]);
	}else go(s);
}
int main()
{
	freopen("manhattan.in","r",stdin);
	freopen("manhattan.out","w",stdout);
	scanf("%d %d",&m, &n);
	ans= oo;
	scanf("%s",s+1);
	for (i= 1;i<=m;i++)
		if (s[i]=='E') X[i]= 1;
		else X[i]= -1;
	scanf("%s",s+1);
	for (i= 1;i<=n;i++)
		if (s[i]=='S') Y[i]= 1;
		else Y[i]= -1;
	for (i= 1;i<=m;i++)
		scanf("%d",&X1[i]);
	for (i= 1;i<=n;i++)
		scanf("%d",&Y1[i]);
	scanf("%d",&K);
	for (i= 1;i<=K;i++){
		scanf("%d %d %d %d",&x1, &x2, &x3, &x4);
		if (x1==x3&&x2==x4) continue;
		Q[++tot]= (query){x1,x2,x3,x4};
	}K= tot;
	dfs(1,0);
	if (ans!=oo){
		printf("possible\n");
		printf("%d\n",ans);
		for (i= 1;i<=m;i++)
			if (fx[i]==1) printf("E");
			else printf("W");
		printf("\n");
		for (i= 1;i<=n;i++)
			if (fy[i]==1) printf("S");
			else printf("N");
		printf("\n");
	}else printf("impossible\n");
	return 0;
}
