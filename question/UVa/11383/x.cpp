#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 600,oo= 1e6;
int c[maxn][maxn],s[maxn],t[maxn],lx[maxn],ly[maxn],d[maxn];
int n,i,j,ans;
bool match(int o){
	s[o]= 1;int i;
	for (i= 1;i<=n;i++)
		if (!t[i] && c[o][i]==lx[o]+ly[i]){
			t[i]= 1;
			if (!d[i]||match(d[i])){
				d[i]= o;
				return 1;
			}
		}
	return 0;
}
void update(){
	int i,j,a= oo;
	for (i= 1;i<=n;i++)
		if (s[i])
			for (j= 1;j<=n;j++)
				if (!t[j])
					a= min(a,lx[i]+ly[j]-c[i][j]);
	for (i= 1;i<=n;i++){
		if (s[i]) lx[i]-= a;
		if (t[i]) ly[i]+= a;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		ans= 0;
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				scanf("%d",&c[i][j]);
		for (i= 1;i<=n;i++){
			lx[i]= ly[i]= d[i]= 0;
			for (j= 1;j<=n;j++)
				lx[i]= max(lx[i],c[i][j]);
		}
		for (i= 1;i<=n;i++)
			for(;;){
				for (j= 1;j<=n;j++) s[j]= t[j]= 0;
				if (match(i)) break;
				else update();
			}
		for (i= 1;i<n;i++){
			printf("%d ",lx[i]);
			ans+= lx[i];
		}ans+= lx[i];printf("%d\n",lx[i]);
		for (i= 1;i<n;i++){
			printf("%d ",ly[i]);
			ans+= ly[i];
		}ans+= ly[i];printf("%d\n",ly[i]);
		printf("%d\n",ans);
	}
	return 0;
}
