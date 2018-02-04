#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn= 1000010;
const ll oo= 1e15;
int stack[maxn],q1[maxn],q2[maxn];
ll f[maxn],g[maxn],x[maxn],p[maxn],c[maxn];
ll y;
int i,j,n,k,top,bot;
ll count(int i,int j){
	ll y= f[j]+(p[i-1]-p[j])*x[i]-(g[i-1]-g[j])+c[i];
	return y;
}
int getint(){
	char c= getchar();int re= 0;
	while (c<'0' || c>'9') c= getchar();
	while (c>='0' && c<='9')re= re*10+c-'0',c= getchar();
	return re;
}
void update(int k){
	int i,j;
	if (q2[bot]<=k) bot++;
	while (top-bot+1){
		i= q1[top]= max(k+1,q1[top]),j= stack[top];
		if (count(i,k)<count(i,j)) top--;
		else {
			int l= i,r= q2[top]+1;
			while(l+1<r){
				int mid= l+((r-l)>>1);
				if (count(mid,k)<count(mid,j)) r= mid;
				else l= mid;
			}
			q2[top]= l;break;
		}
	}
	if (q2[top]!=n){
		stack[++top]= k,q1[top]= q2[top-1]+1,q2[top]= n;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		x[i]= getint();p[i]= getint();c[i]= getint();
		g[i]= p[i]*x[i]+g[i-1]; p[i]+= p[i-1];
	}
	f[0]= 0;stack[bot= top= 1]= 0;q1[1]= 1;q2[1]= n;
	for (i= 1;i<=n;i++){
		f[i]= count(i,stack[bot]);
		update(i);
	}
	printf("%lld",f[n]);
	return 0;
}
