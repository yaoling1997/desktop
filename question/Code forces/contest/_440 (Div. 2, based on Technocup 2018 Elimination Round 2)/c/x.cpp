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
int q;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&q);
	for (int qq= 1;qq<=q;qq++){
		int x;
		scanf("%d",&x);
		int r= x%4,ans= -1;
		if (r==0){
			ans= x/4;
		}else if (r==1){
			if (x/4>=2){
				ans= x/4-1;
			}
		}else if (r==2){
			if (x/4>=1){
				ans= x/4;
			}
		}else {
			if (x/4>=3){
				ans= x/4-1;
			}
		}
		printf("%d\n",ans);
	}return 0;
}
