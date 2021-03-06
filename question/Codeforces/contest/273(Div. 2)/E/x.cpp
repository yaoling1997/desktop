#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll maxn= 1e6+20,E4= 1e4,E5= 1e5,E6= 1e6,E7= 1e7,mo= 5201314;
ll head[mo+10],next[maxn],des[maxn];
ll a1[maxn],a2[maxn],cnt[mo+10];
ll N,K,ans= -1,t1,t2,i,j,k,yu,tot;
void dfs(ll x,ll o){
	if (o>7){
		if (x) a1[++t1]= x;
		if (x>E6||(x>E5 && x/E5>x/E4%10))
			a2[++t2]= x;
		return;
	}
	ll i;
	if (x<10){
		if (x==0){
			dfs(x,o+1);
			for (i= 1;i<=9;i++)
				dfs(i,o+1);
		}else for (i= 0;i<=9;i++)
				  if (i!=x) dfs(x*10+i,o+1);
	}else {
		ll a= x/10%10,b= x%10;
		if (a>b){
			for (i= b+1;i<=9;i++)
				dfs(x*10+i,o+1);
		}else {
			for (i= 0;i<=b-1;i++)
				dfs(x*10+i,o+1);
		}
	}
}
ll get(ll x,ll y,ll z){
	return (z*10+x)*10+y;
}
void update(ll o){
	ll K= get(o/E6,o/E5%10,o%N),i;
	for (i= head[K%mo];i;i= next[i])
		if (des[i]==K){
			cnt[i]++;
			return;
		}
	next[++tot]= head[K%mo];
	des[tot]= K;
	head[K%mo]= tot;
	cnt[tot]++;
}
ll val(ll j,ll k,ll v){
	ll K= get(j,k,v),i;
	for (i= head[K%mo];i;i= next[i])
		if (des[i]==K) return cnt[i];
	return 0;
}
int main()
{
	scanf("%I64d %I64d",&N, &K);
	dfs(0,1);
	for (i= 1;i<=t1;i++)
		if (a1[i]%N==0){
			K--;
			if (!K){
				ans= a1[i];
				break;
			}
		}
	if (K){//l和r是波浪数,且l和r可以连在一起
		for (i= 1;i<=t2;i++){
			update(a2[i]);
		}
		for (i= 1;i<=t1;i++){
			yu= (N-a1[i]*E7%N)%N;//千万要加上括号再mod......
			for (j= 0;j<=9;j++)
				for (k= 0;k<=9;k++){
					if (j==k) continue;
					if (a1[i]<10){
						if ((a1[i]>j&&j<k)||(a1[i]<j&&j>k)){
							if (K>val(j,k,yu)) K-= val(j,k,yu);
							else goto pn;
						}
					}else {
						ll a= a1[i]/10%10,b= a1[i]%10;
						if ((a>b&&b<j&&j>k)||(a<b&&b>j&&j<k)){
							if (K>val(j,k,yu)) K-= val(j,k,yu);
							else goto pn;
						}
					}
				}
		}
		if (0){
		pn: for (ll h= 1;h<=t2;h++){
				ll a= a2[h]/E6,b= a2[h]/E5%10;
				if (a==j&&b==k&&a2[h]%N==yu){
					K--;
					if (K==0){
						ans= a1[i]*E7+a2[h];
						break;
					}
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
