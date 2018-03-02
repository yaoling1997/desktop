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
int ans1,ans2;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while (t--){
		int x;
		scanf("%d",&x);
		ans1=-1;
		ans2=-1;
		for (int i=1;i*i<=x;i++)
			if (x%i==0){
				int a=i,b=x/i;
				if (a>=b)
					break;
				if ((a+b)&1)
					continue;
				int n= (a+b)>>1;
				int m= n/(b-n);
				if (n-n/m!=a)
					continue;
				ans1= n;
				ans2= m;
				break;
			}
		if (x==0){
			ans1= ans2= 1;
		}
		if (ans1==-1)
			printf("-1\n");
		else printf("%d %d\n",ans1,ans2);
	}
}
