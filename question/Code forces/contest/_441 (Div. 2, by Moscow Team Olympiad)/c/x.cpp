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
const int maxn= 5e5,M= 8;
int d[10];
int n;
vector<int> ans;
void dfs(int o,int r,int cnt){
	if (o==0){
		if (r%2==0){
			r/= 2;
			if (r<10){
				cnt+= r;
				ans.pb(cnt);
			}
		}
		return;
	}
	for (int i= 0;i<10;i++){
		dfs(o-1,r,cnt*10);
		r-= d[o];
		cnt++;
		if (r<0)
			break;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	d[0]= 1;
	for (int i= 1;i<10;i++)
		d[i]= d[i-1]*10;
	for (int i= 0;i<10;i++)
		d[i]++;
	scanf("%d",&n);
	dfs(8,n,0);
	int len= ans.size();
	printf("%d\n",len);
	for (int i= 0;i<len;i++)
		printf("%d%c",ans[i],i<len-1?' ':'\n');
	return 0;
}
