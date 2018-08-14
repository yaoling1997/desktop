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
bool vis[maxn];
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int x=1,y=1;
	while (y<=1000){
		vis[y]=1;
		x=x+y;
		swap(x,y);
	}
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		if (vis[i])
			printf("O");
		else printf("o");
	return 0;
}
