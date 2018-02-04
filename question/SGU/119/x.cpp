#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e4;
pair<int,int> P[maxn];
vector<pair<int,int> > ans;
int A,B,n,i,j;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d",&A, &B);
	for (i= 1;i<=n;i++){
		P[i].first= A*i%n;
		P[i].second= B*i%n;
	}
	sort(P+1,P+n+1);
	ans.push_back(P[1]);
	for (i= 2;i<=n;i++)
		if (P[i].first!=P[i-1].first||P[i].second!=P[i-1].second)
			ans.push_back(P[i]);
	int len= ans.size();
	printf("%d\n",len);
	for (i= 0;i<len;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
