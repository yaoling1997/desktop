#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 100;
struct node{
	int v,c;
}b[maxn],a[maxn];
int n,m,k,i,j,ans,x,la,lb;
void get(int x,node *a,int &la){
	la= 0;
	for (int i= 2;i*i<=x;i++)
		if (x%i==0){
			la++;
			a[la].v= i;
			while (x%i==0){
				x/= i;
				a[la].c++;
			}
		}
	if (x>1){
		a[++la].v= x;
		a[la].c= 1;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &k);
	get(k,b,lb);
	for (int N= 1;N<=n;N++){
		scanf("%d",&x);
		la= 0;
		memset(a,0,sizeof(a));		get(x,a,la);
		j= 1;
		int bl= 1;
		for (i= 1;i<=la;i++){
			if (j>lb) break;
			if (a[i].v>b[j].v) break;
			if (a[i].v==b[j].v&&a[i].c*m>=b[j].c) j++;
		}
		if (j<=lb) bl= 0;
		ans+= bl;
	}
	printf("%d",ans);
	return 0;
}
