#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3e4;
struct node{
	double x;
	int p;
}a[maxn];
int n,sum,left,i,j;
bool cmp(node a,node b){
	return a.x<b.x;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf%d",&a[i].x, &a[i].p);
		sum+= a[i].p;
	}
	sort(a+1,a+n+1,cmp);
	for (i= 1;i<=n;i++){
		if (left+a[i].p>=sum-left-a[i].p){
			printf("%.5lf\n",a[i].x);
			break;
		}
		left+= a[i].p;
	}
	return 0;
}