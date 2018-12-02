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
const int maxn= 200;
vector<int> v[maxn];
int s[maxn],a[maxn],ans[maxn],vis[maxn];
int n;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		v[s[i]].pb(i);
	}
	int o=0;
	for (int i=1;i<=100;i++)
		if ((int)v[i].size()==1){
			ans[v[i][0]]=o;
			o^=1;
			vis[i]=1;
		}
	if (o){
		for (int i=1;i<=100;i++)
			if ((int)v[i].size()>=3){
				ans[v[i][0]]=o;
				o^=1;
				for (int j=1;j<(int)v[i].size();j++)
					ans[v[i][j]]=o;
				vis[i]=1;
				break;
			}
	}
	if (o){
		printf("NO");
	}else {
		printf("YES\n");
		for (int i=1;i<=n;i++)
			printf("%c",ans[i]?'B':'A');
	}
	return 0;	
}
