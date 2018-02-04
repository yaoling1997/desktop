#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e4;
int f[maxn],s[maxn],a[maxn];
int n,T,i,j,ans,mx;
int val(int i){
	i%= n;
	if (!i) i= n;
	return a[i];
}
void getf(int n,int k){
	int i,j;
	for (i= 1;i<=n*k;i++){
		f[i]= 1;
		for (j= max(1,i-n);j<i;j++)
			if (val(i)>=val(j))
				f[i]= max(f[i],f[j]+1);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &T);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	if (2*n*n>n*T){
		getf(n,T);
		for (i= 1;i<=n*T;i++)
			ans= max(ans,f[i]);
	}else {
		getf(n,n);
		for (i= 1;i<=n*n;i++)
			ans= max(ans,f[i]);
		for (i= 1;i<=300;i++)
			mx= max(mx,s[i]);
		ans= ans+(T-n)*mx;
	}
	printf("%d\n",ans);
	return 0;
}
