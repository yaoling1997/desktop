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
typedef pair<int,int> PA;
PA a[maxn];
int t,n,x,y,now;
bool cmp(PA a,PA b){
	return a.first<b.first;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&t);
	for (int tt=1;tt<=t;tt++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d",&a[i].first,&a[i].second);
		}
		stable_sort(a+1,a+n+1,cmp);
		now=0;
		for (int i=1;i<=n;i++){
			PA u=a[i];
			if (u.first>now)
				now=u.first;
			int ans=now;
			if (u.second<now)
				ans=0;
			else now++;
			printf("%d%c",ans,i<n?' ':'\n');
		}
	}
	return 0;
}
