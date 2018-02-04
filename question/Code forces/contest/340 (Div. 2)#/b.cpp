#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int a[maxn];
ll ans,d;
int n,i,cnt;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt+= a[i];
	}
	if (cnt==0) printf("0");
	else if (cnt== 1) printf("1");
	else {
		ans= 1;
		int p,q;
		p= 1;q= n;
		while (a[p]==0) p++;
		while (a[q]==0) q--;
		for (i= p+1;i<=q;i++){
			if (a[i]==0) d++;
			else {
				ans*= d+1;
				d= 0;
			}
		}
		printf("%I64d",ans);
	}return 0;
}