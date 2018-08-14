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
const int maxn= 5e5,maxm= 4e6;
int vis[maxm];
int X[maxn],Y[maxn];
int n;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i= 1;i<=n;i++){
        scanf("%d",&X[i]);
        vis[X[i]]= 1;
	}
	for (int i= 1;i<=n;i++){
        scanf("%d",&Y[i]);
        vis[Y[i]]= 1;
	}
	int cnt= 0;
    for (int i= 1;i<=n;i++)
        for (int j= 1;j<=n;j++)
            if (vis[X[i]^Y[j]])
                cnt++;
    printf("%s",cnt%2?"Koyomi":"Karen");
    return 0;
}
