#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 60,maxm= 1e6,maxl= 10,mo= 65521;
typedef ll matrix[maxn][maxn];
matrix a;
ll hash[maxm],antihash[maxn],f[maxl],col[maxl],F[maxl],b[maxl];
ll V[maxn],map[maxl][maxl];
ll n;
ll K,cnt,ans,i,last,bl;
ll find(ll *f,ll o){
	if (o==f[o]) return o;
	return f[o]= find(f,f[o]);
}
ll express(ll *f,ll l,ll r){
	ll i,tot= 0,sum= 0;
	memset(col,0,sizeof(col));
	memset(b,0,sizeof(b));
	for (i= l;i<=r;i++)
		if (b[f[i]]) col[i]= b[f[i]];
		else col[i]= b[f[i]]= ++tot;
	for (i= l;i<=r;i++)	sum= sum*10+col[i];
	return sum;
}
void go(){
	ll i,j;
	for (i= 1;i<=K;i++) f[i]= i;
	memset(col,0,sizeof(col));
	for (i= 1;i<=K;i++)
		for (j= i+1;j<=K;j++)
			if (map[i][j]){
				if (find(f,i)==find(f,j)) return;
				else f[f[i]]= f[j];
			}
	for (i= 1;i<=K;i++) find(f,i);	
	ll sum= express(f,1,K);	
	if (!hash[sum]) hash[sum]= ++cnt,antihash[cnt]= sum;
	V[hash[sum]]++;
	if (!bl&&sum==last)
		bl= 1,last= cnt;
}
void dfs(ll x,ll y){
	if (y>K) x++,y= x+1;
	if (x>=K) go();
	else {
		map[x][y]= 1;
		dfs(x,y+1);
		map[x][y]= 0;
		dfs(x,y+1);
	}
}
void comeon(ll o,ll *F,ll s){
	ll f[maxl],sum;
	memcpy(f,F,sizeof(f));
	if (o>K){
		for (ll i= 1;i<=K+1;i++) find(f,i);
		sum= express(f,2,K+1);
		a[s][hash[sum]]++;
		return;
	}
	comeon(o+1,f,s);
	if (find(f,K+1)!=find(f,o)){
		f[f[K+1]]= f[o];
		comeon(o+1,f,s);
	}
}
void prepare(){
	dfs(1,2);
	ll i,j,sum,p,q;
	for (i= 1;i<=cnt;i++){
		memset(col,0,sizeof(col));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		sum= antihash[i];
		p= K;q= 0;
		while (sum){
			col[p--]= sum%10;
			sum/= 10;
		}
		for (j= 1;j<=K;j++){
			if (!b[col[j]]) b[col[j]]= j;
			f[j]= b[col[j]];
			q+= col[j]==1;
		}f[K+1]= K+1;
		if (q==1) f[K+1]= f[1];
		comeon(1,f,i);
	}
}
void mul(matrix a,matrix b,matrix res){
	matrix c;
	memset(c,0,sizeof(c));
	ll i,j,k;
	for (i= 1;i<=cnt;i++)
		for (j= 1;j<=cnt;j++)
			for (k= 1;k<=cnt;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j])%mo;
	memcpy(res,c,sizeof(c));
}
void ksm(matrix a,ll b,matrix res){
	matrix t;
	memset(t,0,sizeof(t));
	ll i;
	for (i= 1;i<=cnt;i++)	t[i][i]= 1;
	while (b){
		if (b&1) mul(t,a,t);
		b>>= 1;mul(a,a,a);
	}memcpy(res,t,sizeof(t));
}
void chen(ll *V,matrix a,ll *res){
	ll b[maxn]= {0};
	ll i,j;
	for (i= 1;i<=cnt;i++)
		for (j= 1;j<=cnt;j++)
			b[i]= (b[i]+V[j]*a[j][i])%mo;
	memcpy(res,b,sizeof(b));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld",&K, &n);
	for (i= 1;i<=K;i++)	last= last*10+1;
	prepare();
	ksm(a,n-K,a);
	chen(V,a,V);
	printf("%lld",V[last]);
	return 0;
}
