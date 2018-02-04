#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
const int maxn= 2e6;
map<int,int> M;
int a[maxn],A[maxn];
int n,m,i,j,x,ans,cnt;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		A[i]= x;
		if (x>m) continue;
		M[x]++;
	}
	for (i= 1;i<=m;i++)
		if (M.count(i)){
			cnt= M[i];
			for (j= 1;j*i<=m;j++)
				a[j*i]+= cnt;
		}
	ans= 1;
	for (i= 2;i<=m;i++)
		if (a[i]>a[ans])
			ans= i;
	printf("%d %d\n",ans, a[ans]);
	cnt= 0;
	for (i= 1;i<=n;i++)
		if (ans%A[i]==0){
			cnt++;
			if (cnt>1) printf(" ");
			printf("%d",i);
		}
	return 0;
}
