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
set<int> X[maxn];
set<int> S;
int cnt[maxn];
int n,m,i,k;
void dfs(int o){
	cnt[k]++;
	set<int> tmp;
	for (set<int>::iterator it=S.begin();it!=S.end();it++){
		if (X[o].count(*it))
			continue;
		tmp.insert(*it);
	}
	for (set<int>::iterator it=tmp.begin();it!=tmp.end();it++){
		S.erase(*it);
	}
	for (set<int>::iterator it=tmp.begin();it!=tmp.end();it++){
		dfs(*it);
	}
	
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		X[x].insert(y);
		X[y].insert(x);
	}
	for (int i=1;i<=n;i++)
		S.insert(i);
	while (!S.empty()){
		k++;
		int x= *S.begin();
		S.erase(x);
		dfs(x);
	}
	sort(cnt+1,cnt+k+1);
	printf("%d\n",k);
	for (int i= 1;i<=k;i++)
		printf("%d%c",cnt[i],i<k?' ':'\n');
	return 0;
}
