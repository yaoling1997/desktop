#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 30,mo= 1e9+7;
typedef ll matrix[maxn][maxn];
typedef ll vec[maxn];
struct move{
	ll x,y;
}T[10];
ll n,m,q,i,j,k,o,x,y,z,t,M;
matrix a,O;
vec ans,f;
void mul(matrix a,matrix b,matrix res){
	matrix c= {0};
	ll i,j,k;
	for (i= 1;i<=M;i++)
		for (j= 1;j<=M;j++)
			for (k= 1;k<=M;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j])%mo;
	memcpy(res,c,sizeof(c));
}
void pow(matrix a,ll b,matrix res){
	matrix I= {0},c= {0};
	if (b<0){
		memcpy(res,a,sizeof(I));
		return;
	}
	ll i;
	for (i= 1;i<=M;i++)
		I[i][i]= 1;
	memcpy(c,a,sizeof(c));
	while (b){
		if (b&1) mul(I,c,I);
		b>>= 1;mul(c,c,c);
	}
	memcpy(res,I,sizeof(I));
}
void get(vec f,matrix a,vec res){
	vec c= {0};
	ll i,j;
	for (i= 1;i<=M;i++)
		for (j= 1;j<=M;j++)
			c[i]= (c[i]+f[j]*a[j][i])%mo;
	memcpy(res,c,sizeof(c));
}
ll num(ll x,ll y){
	if (x<1||x>n||y<1||y>m) return -1;
	return (x-1)*m+y;
}
void add(ll x,ll i,ll j,matrix a){
	ll y= num(i,j);
	if (y==-1) return;
	a[y][x]= 1;
}
void clear(ll x,ll i,ll j,matrix a){
	ll y= num(i,j);
	if (y==-1) return;
	a[y][x]= 0;
}
int main()
{
	scanf("%lld%lld%lld",&n, &m, &q);
	T[0]= (move){-1,0};
	T[1]= (move){1,0};
	T[2]= (move){0,-1};
	T[3]= (move){0,1};
	T[4]= (move){0,0};
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			x= num(i,j);
			for (k= 0;k<5;k++){
				ll xx= i+T[k].x,yy= j+T[k].y;
				add(x,xx,yy,O);
			}
		}
	}
	M= n*m;
	t= 1;
	ans[1]= 1;
	for (i= 1;i<=q;i++){
		scanf("%lld%lld%lld%lld",&o, &x, &y, &z);
		if (o==3) z++;
		if (o==1){
			pow(O,z-t,a);
			get(ans,a,ans);
			printf("%lld\n",ans[num(x,y)]);
		}else if (o==2){
			pow(O,z-t,a);
			get(ans,a,ans);			
			o= num(x,y);
			for (k= 0;k<5;k++){
				ll xx= x+T[k].x,yy= y+T[k].y;
				clear(o,xx,yy,O);
			}
			ans[num(x,y)]= 0;
		}else {
			pow(O,z-t-1,a);
			get(ans,a,ans);
			for (j= 1;j<=M;j++)
				f[j]= ans[j];
			get(ans,O,ans);
			o= num(x,y);
			for (k= 0;k<5;k++){
				ll xx= x+T[k].x,yy= y+T[k].y;
				add(o,xx,yy,O);
				if (k==4) continue;
				if (num(xx,yy)!=-1)
					ans[num(x,y)]= (ans[num(x,y)]+f[num(xx,yy)])%mo;
			}
		}
		t= z;
	}return 0;
}
