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
const int maxn= 5e5,maxm=1e6+10;
set<int> S;
ll a[maxn];
int c[maxn],d[maxm];
int n,m;
void add(int o,int x){
	while (o<=n){
		a[o]+=x;
		o+=o&-o;
	}
}
ll sum(int o){
	ll re=0;
	while (o){
		re+= a[o];
		o-=o&-o;
	}
	return re;
}
void prepare(){
	for (int i=1;i<maxm;i++)
		for (int j=i;j<maxm;j+=i)
			d[j]++;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		S.insert(i);
		add(i,c[i]);
	}
	prepare();
	for (int tt=1;tt<=m;tt++){
		int x,y,z;
		scanf("%d%d%d",&x, &y, &z);
		if (x==1){
			set<int>::iterator it=S.lower_bound(y);
			while (*it<=z&&it!=S.end()){
				int g=*it;
				add(g,d[c[g]]-c[g]);
				c[g]=d[c[g]];
				if (c[g]<=2) it=S.erase(it);
				else {
					it++;
				}
			}
		}else {
			ll ans=sum(z)-sum(y-1);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
