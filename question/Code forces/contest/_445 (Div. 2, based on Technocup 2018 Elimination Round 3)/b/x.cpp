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
int a[maxn];
int n,i,ans=-1;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[x]= i;
	}
	for (i= 0;i<=2e5;i++){
        if (a[i]!=0){
           if (ans==-1||a[ans]>a[i])
            ans= i;
        }
	}
	printf("%d",ans);
	return 0;
}
