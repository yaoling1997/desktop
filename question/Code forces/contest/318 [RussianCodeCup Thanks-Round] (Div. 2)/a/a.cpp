#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
priority_queue<int> Q;
int n,i,x,y,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &x);
	for (i= 2;i<=n;i++){
		scanf("%d",&y);
		Q.push(y);
	}
	while (x<=Q.top()){
		y= Q.top();
		Q.pop();
		ans++;
		x++;
		y--;
		Q.push(y);
	}
	printf("%d",ans);
}
