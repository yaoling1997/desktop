#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e5;
struct point{
	int d[3],w;	
};
struct node{
	int d[3],w,M;
	int split,L[3],R[3],ch[2];
};
point P[maxn];
node a[maxn];
int last[maxn],next[maxn],A[maxn],B[maxn],range[3][2];
int n,m,i,x,y,z,root,tot,D,ans;
bool operator <(const point &a,const point &b){
	return a.d[D]<b.d[D];
}
void update(int o){
	int ch[2]= {a[o].ch[0],a[o].ch[1]};
	for (int i= 0;i<2;i++)
		if (ch[i])
			for (int j= 0;j<3;j++){
				a[o].L[j]= min(a[o].L[j],a[ch[i]].L[j]);
				a[o].R[j]= max(a[o].R[j],a[ch[i]].R[j]);
				a[o].M= max(a[o].M,a[ch[i]].M);
			}
				
}
double F(int l,int r){
	double x= 0,sum= 0;
	int i;
	for (i= l;i<=r;i++)
		x+= P[i].d[D];
	x/= r-l+1;
	for (i= l;i<=r;i++)
		sum+= (P[i].d[D]-x)*(P[i].d[D]-x);
	return sum/= r-l+1;
}
void build(int &o,int l,int r){
	if (!o) o= ++tot;
	int i,mid= (l+r)>>1;
	double f[3];i= 0;
	for (D= 0;D<3;D++){
		f[D]= F(l,r);
		i= f[D]>f[i]?D:i;
	}	
	D= i;
	sort(P+l,P+r+1);
	for (i= 0;i<3;i++)
		a[o].d[i]= a[o].L[i]= a[o].R[i]= P[mid].d[i];
	a[o].split= D;a[o].w= a[o].M= P[mid].w;
	if (l<mid) build(a[o].ch[0],l,mid-1);
	if (mid<r) build(a[o].ch[1],mid+1,r);
	update(o);
}
bool ok(int o){
	if (!o) return 0;
	for (int i= 0;i<3;i++)
		if (range[i][1]<a[o].L[i]||range[i][0]>a[o].R[i]) return 0;
	return 1;
}
void query(int o){
	if (a[o].M<=ans) return;
	bool bl= 1;int i;
	for (i= 0;i<3;i++)
		if (a[o].L[i]<range[i][0]||a[o].R[i]>range[i][1]){
			bl= 0;
			break;
		}
	if (bl){
		ans= max(ans,a[o].M);
		return;
	}
	bl= 1;
	for (i= 0;i<3;i++)
		if (a[o].d[i]<range[i][0]||a[o].d[i]>range[i][1]){
			bl= 0;
			break;
		}
	if (bl) ans= max(ans,a[o].w);	
	for (i= 0;i<2;i++)
		if (ok(a[o].ch[i]))
			query(a[o].ch[i]);
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&A[i]);
	for (i= 1;i<=n;i++){
		last[i]= B[A[i]];
		B[A[i]]= i;
	}
	for (i= 1;i<=n;i++) B[i]= n+1;
	for (i= n;i>0;i--){
		next[i]= B[A[i]];
		B[A[i]]= i;
	}
	for (i= 1;i<=n;i++)
		P[i]= (point){i,last[i],next[i],A[i]};
	build(root,1,n);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		x= (x+ans)%n+1;
		y= (y+ans)%n+1;
		if (x>y) swap(x,y);
		range[0][0]= x;
		range[0][1]= y;		
		range[1][0]= 0;
		range[1][1]= x-1;
		range[2][0]= y+1;
		range[2][1]= n+1;
		ans= 0;
		query(root);
		printf("%d\n",ans);
	}
	return 0;
}
