#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 2e6;
int a[maxn],b[maxn];
int n,i,x,ans,M;
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		M= max(M,x);
		b[x]++;
	}
	for (i= 0;i<=M;i++){
		ans+= b[i]&1;
		b[i+1]+= b[i]/2;
	}
	while (b[M+1]){
		M++;
		ans+= b[M]&1;
		b[M+1]+= b[M]/2;
	}printf("%d",ans);
	return 0;
}
