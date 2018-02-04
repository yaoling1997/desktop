#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
int f[maxn],p[maxn],c[maxn],w[maxn],g[maxn];
int n,v,i;
void bag01(int val,int cost){
	for (int i= v;i>=cost;i--)
		f[i]= max(f[i],f[i-cost]+val);
}
void bag02(int o){
	for (int i= w[o];i<=v;i++)
		f[i]= max(f[i],f[i-w[o]]+c[o]);
}
void bag03(int o){
	if (c[o]*g[o]>=v) bag02(o);
	else {
		int k= 1,num= g[o];
		while (k<num){
			bag01(k*c[o],k*w[o]);
			num-= k;
			k*= 2;
		}
		bag01(num*c[o],num*w[o]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &v);
	for (i= 1;i<=n;i++){
		scanf("%d %d %d",&p[i], &c[i], &w[i]);
		if (p[i]==3) scanf("%d",&g[i]);
	}
	for (i= 1;i<=n;i++)
		if (p[i]==1) bag01(c[i],w[i]);
		else if (p[i]==2) bag02(i);
		else bag03(i);
	printf("%d",f[v]);
}
