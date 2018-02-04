#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 60000,base= 500,maxm= 2e6;
struct que{
	int l,r,t,b;
};
struct TT{
	int p,u,v;
};
que wk[maxn];
TT jd[maxn];
char s[maxn];
int a[maxn],b[maxn],c[maxm],ans[maxn];
int n,m,i,x,y,z,tot,top,now,l,r,t;
bool cmp(que a,que b){
	return a.l/base!=b.l/base? a.l<b.l:a.r/base!=b.r/base?a.r<b.r:a.t<b.t;
}
void goT(int o){
	int i;
	if (t<o){
		for (i= t+1;i<=o;i++){
			TT J= jd[i];
			if (l<=J.p&&J.p<=r){
				c[J.u]--;if (!c[J.u]) now--;
				c[J.v]++;if (c[J.v]==1) now++;
			}b[J.p]= J.v;
		}
	}else {
		for (i= t;i>o;i--){
			TT J= jd[i];
			if (l<=J.p&&J.p<=r){
				c[J.v]--;if (!c[J.v]) now--;
				c[J.u]++;if (c[J.u]==1) now++;
			}b[J.p]= J.u;
		}
	}t= o;
}
void goL(int o){
	int i;
	if (l<o){
		for (i= l;i<o;i++){
			c[b[i]]--;
			if (!c[b[i]]) now--;
		}
	}else for (i= l-1;i>=o;i--){
			c[b[i]]++;
			if (c[b[i]]==1) now++;
		}
	l= o;
}
void goR(int o){
	int i;
	if (r<o){
		for (i= r+1;i<=o;i++){
			c[b[i]]++;
			if (c[b[i]]==1) now++;
		}
	}else for (i= r;i>o;i--){
			c[b[i]]--;
			if (!c[b[i]]) now--;
		}
	r= o;
}
void solve(){
	l= 1;r= 1;c[b[1]]= 1;t= 0;now= 1;
	for (int i= 1;i<=tot;i++){
		que lpn= wk[i];
		goT(lpn.t);
		if (lpn.l>r){
			goR(lpn.r);
			goL(lpn.l);
		}else {
			goL(lpn.l);			
			goR(lpn.r);
		}
		ans[wk[i].b]= now;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]= a[i];
	}
	for (int a1= 1;a1<=m;a1++){
		scanf("%s",s+1);
		scanf("%d %d",&x, &y);
		if (s[1]=='Q'){
			tot++;
			wk[tot]= (que){x,y,top,tot};
		}else {
			jd[++top]= (TT){x,a[x],y};
			a[x]= y;
		}
	}sort(wk+1,wk+tot+1,cmp);
	solve();
	for (i= 1;i<=tot;i++)
		printf("%d\n",ans[i]);
	return 0;
}

