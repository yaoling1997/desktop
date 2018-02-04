#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const double eps= 1e-8;
const int maxn= 3e5,M= 1e9,K= sqrt(M)+eps;
int sta[maxn],vis[maxn];
int la,n,i,x,y,cnt;
bool prime(int x){
	int i,cnt= 0;
	for (i= 1;i<=la&&sta[i]<=sqrt(x)+eps;i++)
		while (x%sta[i]==0){
			x/= sta[i];
			cnt++;
		}
	if (x!=1) cnt++;
	return cnt==2;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for (i= 2;i<=K;i++){
		if (vis[i]) continue;
		int p= i*i;
		while (p<=K){
			vis[p]= 1;
			p+= i;
		}
	}
	vis[0]= vis[1]= 1;
	for (i= 2;i<=K;i++)
		if (!vis[i])
			sta[++la]= i;
	scanf("%d",&n);	
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		if (prime(x)) printf("Yes\n");
		else printf("No\n");
	}return 0;
}
