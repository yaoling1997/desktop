#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 2e5;
ll f[maxn][20],h[maxn][20],Sf[maxn],Pf[maxn],C[maxn];
vector<int> g[maxn];
ll mo,r0,r1,r2;
ll n,m,i,x,y;
void prepare(int o,int fa){
	int len= g[o].size(),i,p= -1;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa){
			p= i;
			continue;
		}prepare(v,o);
	}
	if (p!=-1){
		g[o][p]= g[o][len-1];
		g[o].pop_back();
	}		
}
ll sf(int i){
	return Sf[i];
}
ll pf(int i){
	if (i<0) return 1;
	return Pf[i];
}
void get(int o,int b){
	ll len= g[o].size(),i,v;
	if (!len||!b) return;
	v= g[o][0];Pf[0]= (f[v][b-1]+h[v][b-1])%mo;
	Sf[len]= 1;
	for (i= 1;i<len;i++){
		v= g[o][i];
		Pf[i]= Pf[i-1]*(f[v][b-1]+h[v][b-1])%mo;
	}
	for (i= len-1;i>=0;i--){
		v= g[o][i];
		Sf[i]= Sf[i+1]*(f[v][b-1]+h[v][b-1])%mo;
	}
	C[len-1]= h[g[o][len-1]][b];C[len]= 0;
	for (i= len-2;i>=0;i--){
		v= g[o][i];
		C[i]= (C[i+1]*(h[v][b-1]+f[v][b-1])+h[v][b]*sf(i+1))%mo;
	}
	r0= sf(0);r1= r2= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		r1= (r1+pf(i-1)%mo*h[v][b]%mo*sf(i+1))%mo;
		r2= (r2+pf(i-1)*h[v][b]%mo*C[i+1])%mo;
	}
}
void dfs(ll o,ll b){
	if (b<0) return;
	ll &res= f[o][b],&Res= h[o][b];
	if (res!=-1) return;
	ll i,len= g[o].size(),v,v1,v2;
	for (i= 0;i<len;i++){
		v= g[o][i];
		dfs(v,b-1);
		dfs(v,b);
	}get(o,b);
	if (len<2){
		res= 0;
		goto pn;
	}
	if (!b){
		if (len!=2)	res= 0;
		else {
			v1= g[o][0],v2= g[o][1];
			res= h[v1][b]*h[v2][b]%mo;
		}goto pn;
	}
	res= r2%mo;	
 pn:
	if (len==0){
		Res= 1;
		return;
	}else if (len==1){
		v= g[o][0];
		Res= h[v][b];
		if (b)
			Res= (Res+h[v][b-1]+f[v][b-1])%mo;		
		return;
	}
	if (!b){
		Res= 0;
		return;
	}
	Res= (r0+r1)%mo;	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld %lld",&n, &m, &mo);
	if (mo==2) mo= 1000000008;
	if (m!=n-1){
		printf("-1\n-1");
		return 0;
	}
	for (i= 1;i<=m;i++){
		scanf("%lld %lld",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}prepare(1,0);
	memset(f,-1,sizeof(f));
	memset(h,-1,sizeof(h));
	for (i= 0;i<=20;i++){
		dfs(1,i);
		if (f[1][i]||h[1][i]){
			if (mo==1000000008) mo= 2;			
			printf("%lld\n%lld",i, (f[1][i]+h[1][i])%mo);
			break;
		}
	}
	return 0;
}
