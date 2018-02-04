#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 30;
int m[maxn],a[maxn];
int i,ans,x,y;
int get(int i){
	return max(150*i,500*i-m[i]*i*2-50*a[i]);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	for (i= 1;i<=5;i++)
		scanf("%d",&m[i]);
	for (i= 1;i<=5;i++)
		scanf("%d",&a[i]);
	scanf("%d%d",&x, &y);
	for (i= 1;i<=5;i++)
		ans+= get(i);
	ans+= x*100-y*50;
	printf("%d\n",ans);
	return 0;
}
