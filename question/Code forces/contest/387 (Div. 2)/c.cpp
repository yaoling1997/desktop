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
int a[200];
int ans[maxn];
int n,q,i;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &q);
	for (int qq= 1;qq<=q;qq++){
		int t,k,d;
		scanf("%d%d%d",&t, &k, &d);
		vector<int> sta;
		for (i= 1;i<=n;i++){
			if ((int)sta.size()>=k)
				break;
			if (a[i]<=t)
				sta.pb(i);			
		}
		int len= sta.size();
		if (len<k){
			ans[qq]= -1;
		}else {
			int sum= 0;
			for (i= 0;i<len;i++){
				sum+= sta[i];
				a[sta[i]]= t+d;
			}
			ans[qq]= sum;
		}
	}
	for (i= 1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
