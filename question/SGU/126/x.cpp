#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int A,B,x,y,ans,cnt;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&A, &B);	
	if (A>B) swap(A,B);
	if (!A){
		printf("0");
		return 0;
	}
	ans= 0;
	while (ans<=1e5){
		ans++;
		B-= A;
		A*= 2;
		if (!A||!B) break;
		if (A>B) swap(A,B);
	}
	if (ans>1e5) ans= -1;
	printf("%d\n",ans);
	return 0;
}
