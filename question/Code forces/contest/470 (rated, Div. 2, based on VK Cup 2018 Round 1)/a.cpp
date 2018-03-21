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
const int maxn= 1000;
char a[maxn][maxn];
int r,c,ans;
int check(int i,int j){
	if (a[i-1][j]=='W')
		return 1;
	if (a[i+1][j]=='W')
		return 1;
	if (a[i][j-1]=='W')
		return 1;
	if (a[i][j+1]=='W')
		return 1;
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&r, &c);
	for (int i=1;i<=r;i++)
		scanf("%s",a[i]+1);
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			if (a[i][j]=='.')
				a[i][j]='D';
			else if (a[i][j]=='S'){
				if (check(i,j))
					ans=1;
			}
	if (ans){
		printf("No");
	}else {
		printf("Yes\n");
		for (int i=1;i<=r;i++)
			printf("%s\n",a[i]+1);
	}
}
