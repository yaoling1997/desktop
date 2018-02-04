#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 6e5;
set<int> S;
multiset<int> MS;
int a[maxn];
int n,k,ans,l,r,cnt,p,i,x;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &k);
	p= 1;
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		if (cnt<k){
			S.insert(a[i]);
			MS.insert(a[i]);
			cnt= S.size();
		}else {
			if (S.count(a[i])){
				MS.insert(a[i]);				
			}else {
				while (cnt==k){
					x= a[p];
					p++;
					MS.erase(MS.find(x));
					if (MS.count(x)==0)
						S.erase(x);
					cnt= S.size();
				}
				S.insert(a[i]);
				MS.insert(a[i]);
				cnt= S.size();
			}
		}
		if (i-p+1>ans){
			ans= i-p+1;
			l= p;
			r= i;
		}
	}
	printf("%d %d\n",l, r);
	return 0;
}
