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
int n,d,ans,rest,acc;
bool deal(int a){
	if (acc>d)
		return false;
	if (!a){
		if (acc<0){
			int tmp=min(rest,-acc);
			acc+= tmp;
			rest-=tmp;
		}
		if (acc<0){
			rest=d;
			ans++;
			acc=0;
		}
	}else {
		rest=min(rest,d-acc);
	}
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &d);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		acc+= x;
		if (!deal(x)){
			printf("-1");
			return 0;
		}
	}
	printf("%d",ans);
	return 0;
}
