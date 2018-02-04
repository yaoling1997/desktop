#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int K,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&K);
	if (K==1){
		printf("8");
		return 0;
	}
	ans= 1;
	if ((K-1)%3==0){
		ans+= 2;
		if ((K-1)%6==0) ans++;
	}
	printf("%d",ans);
	return 0;
}
