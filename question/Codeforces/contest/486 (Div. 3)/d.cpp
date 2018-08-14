#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
vector<int> ans,now;
set<int> S;
int a[maxn];
int n;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		S.insert(a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		ll step=1;
		while (step<=2e9){
			int x=a[i];
			now.clear();
			now.pb(x);
			while (x+step<=1e9&&S.count(x+step)){
				x+=step;
				now.pb(x);
				if (now.size()==3)
					break;
			}
			if (now.size()>ans.size())
				ans=now;
			step<<=1;
		}
		if (ans.size()==3)
			break;
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<(int)ans.size();i++)
		printf("%d%c",ans[i],i<(int)ans.size()-1?' ':'\n');
	return 0;
}
