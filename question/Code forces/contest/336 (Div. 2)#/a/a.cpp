#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e3;
int a[maxn];
int n,s,i,j,x,y,z,now;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &s);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		a[x]= max(a[x],y);
	}
	for (i= s;i>=0;i--){
		if (i!=s) now++;
		now= max(now,a[i]);
	}
	printf("%d\n",now);
	return 0;
}
