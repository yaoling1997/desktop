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
int n,pos,l,r,ans;
void solve(){
	if (l==1&&r==n)
		return;
	if (l==1){
		ans=abs(r-pos)+1;
		return;
	}
	if (r==n){
		ans=abs(pos-l)+1;
		return;
	}
	ans=r-l+min(abs(pos-l),abs(pos-r))+2;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d%d",&n, &pos, &l, &r);
	solve();
	printf("%d",ans);
	return 0;
}
