#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define rep(i,a,n) for (int i= a;i<=n;i++)
#define ll long long
using namespace std;
const int maxn= 2e5+10,maxm= 1e6+10,M= 1e6,mo= 1e9+7;
struct query{
	int l,r,h;
}Q[maxn];
ll ans[maxn];
int A[maxm][10],L[maxm],vis[maxm];
int B[maxn][10],C[maxn];
int up[maxm],down[maxm],sum[maxn];
int a[maxn];
ll now;
int i,j,k,q,l,r,n,m,x,y,z,base,xx,yy,X,Y,I;
bool cmpl(query a,query b){
	return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
bool cmpr(query a,query b){
	return a.r<b.r||(a.r==b.r&&a.l<b.l);
}
void gcd(int a,int b,int &x,int &y){
	if (!b){
		x= 1;
		y= 0;
		return;
	}
	gcd(b,a%b,x,y);
	int t= x;
	x= y;
	y= t-a/b*y;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	up[1]= down[1]= 1;
	for (i= 2;i<=M;i++){
		if (vis[i]) continue;
		gcd(i,mo,x,y);
		gcd(i-1,mo,xx,yy);
		x= (x+mo)%mo;
		xx= (xx+mo)%mo;
		up[i]= (ll)(i-1)*x%mo;
		down[i]= (ll)i*xx%mo;		
		j= i;
		while (j<=M){
			vis[j]= 1;
			L[j]++;
			A[j][L[j]]= i;
			j+= i;
		}
	}
	a[0]= sum[0]= 1;
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]= (ll)sum[i-1]*a[i]%mo;
		C[i]= L[a[i]];
		for (j= 1;j<=C[i];j++)
			B[i][j]= A[a[i]][j];
	}
	scanf("%d",&q);
	base= 600;
	for (i= 1;i<=q;i++){
		scanf("%d%d",&x, &y);
		Q[i]= (query){x,y,i};
	}	
	sort(Q+1,Q+q+1,cmpl);
	memset(vis,0,sizeof(vis));
	l= r= 0;
	now= 1;
	for (i= 1;i<=q;i+= base){
		m= min(i+base-1,q);
		sort(Q+i,Q+m+1,cmpr);
		rep(j,i,m){
			x= Q[j].l,y= Q[j].r;
			while (x<l){
				l--;
				rep(I,1,C[l]){
					int y= B[l][I];
					vis[y]++;
					if (vis[y]==1)
						now= now*up[y]%mo;
				}				
			}
			while (l<x){
				rep(I,1,C[l]){
					int y= B[l][I];
					vis[y]--;
					if (vis[y]==0)
						now= now*down[y]%mo;
				}					
				l++;
			}
			while (y<r){
				rep(I,1,C[r]){
					int y= B[r][I];
					vis[y]--;
					if (vis[y]==0)
						now= now*down[y]%mo;
				}					
				r--;
			}
			while (r<y){
				r++;
				rep(I,1,C[r]){
					int y= B[r][I];
					vis[y]++;
					if (vis[y]==1)
						now= now*up[y]%mo;
				}								
			}
			gcd(sum[l-1],mo,x,y);
			ans[Q[j].h]= now*sum[r]%mo*x%mo;
		}
	}
	for (i= 1;i<=q;i++)
		printf("%lld\n",(ans[i]+mo)%mo);
	return 0;
}
