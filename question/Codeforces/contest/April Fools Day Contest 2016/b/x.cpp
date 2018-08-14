#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int M[maxn],R[maxn];
int n,i,j,x,y,z,m;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	m= 1e7;
	for (i= 1;i<=n;i++)
		scanf("%d",&M[i]);
	for (i= 1;i<=n;i++)
		scanf("%d",&R[i]);
	for (i= 0;i<m;i++){
		x= 0;
		for (j= 1;j<=n;j++)
			if (i%M[j]==R[j]) x++;
		if (x>0) y++;
	}
	printf("%.6lf",y*1.0/m);
	return 0;
}
