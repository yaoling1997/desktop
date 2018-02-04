#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
set<int> S;
int a[maxn];
int n,i,ans,x,p;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		if (S.count(x)){
			ans++;
			S.clear();
			a[ans]= i;
		}else S.insert(x);
	}
	if (!ans) printf("-1");
	else {
		printf("%d\n",ans);
		p= 1;
		a[ans]= n;
		for (i= 1;i<=ans;i++){
			printf("%d %d\n",p, a[i]);
			p= a[i]+1;
		}
	}return 0;
}
