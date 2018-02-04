#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 1050,maxm= 2*maxn,oo= 1e9;
//const int maxn= 100,maxm= 2*maxn,oo= 1e8;
vector<int> X;
vector<int> beg;
vector< vector<int> > f[maxm];
int ch[maxm][2];
int F[maxn][maxn],B[maxn],C[maxn],a[maxm];
int i,j,n,x,H,tot,top,ans;
void pre(int h){
	vector<int> x;
	int i,lim,o= ++tot;
	lim= 1<<h;
	for (i= 0;i<=lim;i++) x.push_back(-1);
	lim= 1<<(H-h);
	for (i= 0;i<=lim;i++)
		f[o].push_back(x);
	if (h==H){
		a[tot]= ++top;
		return;
	}
	ch[o][0]= tot+1;
	pre(h+1);
	ch[o][1]= tot+1;
	pre(h+1);   
}
int dfs(int o,int n,int p,int h){
	int u= (1<<(H-h))<=n*2? 0:1;
	p+= u<<(h-1);
	int &res= f[o][n][p],i,x,y,v,l,r;
	if (res!=-1) return res;
	if (h==H){
		res= 0;int cnt= 0,mid;	
		v= a[o];x= u;
		res+= C[v]*(x!=B[v]);
		for (i= 1;i<h;i++){
			y= 1<<(i-1);
			l= cnt+1;r= cnt+(1<<(H-i));
			mid= (l+r)>>1;
			if (((p&y)!=0)!=x){			
				if (v>mid) res+= F[v][mid]-F[v][l-1];
				else res+= F[v][r]-F[v][mid];
			}
			if (v>mid)
				cnt+= 1<<(H-i-1);			
		}
	}else {
		res= oo;
		l= ch[o][0],r= ch[o][1];
		int maxi= min(1<<(H-h-1),n);
		int mini= max(0,n-(1<<(H-h-1))),sum1,sum2;
		for (i= mini;i<=maxi;i++){
			sum1= dfs(l,i,p,h+1);
			sum2= dfs(r,n-i,p,h+1);
			res= min(res,sum1+sum2);
		}			
	}return res;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	if (!n){
		printf("0\n");
		return 0;
	}H= n+1;
	n= 1<<n;
	for (i= 1;i<=n;i++) scanf("%d",&B[i]);
	for (i= 1;i<=n;i++) scanf("%d",&C[i]);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			if (i!=j) F[i][j]= -1;
	for (i= 1;i<=n*(n-1)/2;i++){
		scanf("%d",&x);
		X.push_back(x);
	}x= 0;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			if (F[i][j]==-1)
				F[i][j]= F[j][i]= X[x++];
	for (i= 1;i<=n;i++)
		for (j= 2;j<=n;j++)
			F[i][j]+= F[i][j-1];
	pre(1);ans= oo;
	for (i= 0;i<=n;i++)
		ans= min(ans,dfs(1,i,0,1));
	printf("%d\n",ans);
	return 0;
}
