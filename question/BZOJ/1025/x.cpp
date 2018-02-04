#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 3001;
ll f[200][maxn],x,ans;
int stack[maxn],b[maxn];
int top,n,i,j,k;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 2;i<=n;i++)
		if (!b[i]){
			stack[++top]= i;
			j= i*i;
			while (j<=n){
				b[j]= 1;
				j+= i;
			}
		}
	f[0][0]= 1;
	for (i= 1;i<=top;i++)
		for (j= 0;j<=n;j++){
			f[i][j]+= f[i-1][j];
			x= 1;
			for (k= 1;k<=1000;k++){
				x*= stack[i];
				if (x>j) break;
				f[i][j]+= f[i-1][j-x];
			}
		}
	for (i= 0;i<=n;i++)
		ans+= f[top][i];
	printf("%lld\n",ans);
	return 0;
}
