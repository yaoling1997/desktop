#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
map<int,int> M[maxn];
map<int,int> X;
int a[maxn];
int k,tot;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&k);
	for (int i=1;i<=k;i++){
		int n,sum=0;
		scanf("%d",&n);
		for (int j=1;j<=n;j++){
			scanf("%d",a+j);
			sum+=a[j];
		}
		for (int j=1;j<=n;j++){
			int x=sum-a[j];
			if (!X.count(x)){
				X[x]=++tot;
			}
			x=X[x];
			M[x][i]=j;
		}
	}
	for (int i=1;i<=tot;i++)
		if (M[i].size()>1){
			printf("YES\n");
			map<int,int>:: iterator it=M[i].begin();
			printf("%d %d\n",it->first,it->second);
			it++;
			printf("%d %d\n",it->first,it->second);
			return 0;
		}
	printf("NO");
	return 0;
}
