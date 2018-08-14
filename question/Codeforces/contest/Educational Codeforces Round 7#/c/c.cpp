#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
int L[maxn],R[maxn],a[maxn];
int x,y,z,n,m,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		L[i]= R[i]= i;
	}
	for (i= 2;i<=n;i++)
		if (a[i-1]==a[i])
			L[i]= L[i-1];
	for (i= n-1;i>0;i--)
		if (a[i]==a[i+1])
			R[i]= R[i+1];
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		if (a[x]!=z){
			printf("%d\n",x);
		}else if (a[y]!=z){
			printf("%d\n",y);
		}else if (R[x]<y) printf("%d\n",R[x]+1);
		else printf("-1\n");
	}return 0;
}
