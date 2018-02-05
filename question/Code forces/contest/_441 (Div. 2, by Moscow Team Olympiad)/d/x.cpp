#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int f[maxn],a[maxn];
int n;
int find(int o){
	if (o==f[o])
		return o;
	return f[o]= find(f[o]);
}
void combine(int x,int y){
	if (find(x)!=find(y)){
		f[find(y)]=find(x);
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i= 1;i<=n;i++)
		f[i]= i;
	printf("%d",1);
	for (int i= 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x]= 1;
		if (a[x+1]==1){
			combine(x,x+1);
		}
		if (a[x-1]==1){
			combine(x-1,x);
		}
		int ans;
		if (a[n]==1)
			ans= i-(n-find(n)+1)+1;
		else ans= i+1;
		printf(" %d",ans);
	}
	return 0;
}
