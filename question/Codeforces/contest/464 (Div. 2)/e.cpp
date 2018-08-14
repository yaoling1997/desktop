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
const int maxn= 6e5;
double a[maxn];
double sum;
int n,cnt,j,tot;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	j=1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&x);
			a[++tot]=x;
			while ((cnt+1)*a[j]<sum+x){
				sum+=a[j];
				cnt++;
				j++;
			}
		}else {
			printf("%.10lf\n",a[tot]-(sum+a[tot])/(cnt+1));
		}
	}
}
