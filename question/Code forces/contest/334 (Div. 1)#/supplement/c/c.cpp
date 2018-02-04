#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int pre[]= {0,1,0,1,2};
int n,k,i,ans,x;
int sg(int x){
	if (x==0) return 0;
	if (x==1) return 1;
	if (k%2==0){
		if (x==2) return 2;
		return x%2==0;
	}else {
		if (x<=4) return pre[x];
		if (x%2) return 0;
		if (sg(x/2)==1) return 2;
		return 1;
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &k);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		x= sg(x);
		ans^= x;
	}
	printf("%s",ans?"Kevin":"Nicky");
	return 0;
}
