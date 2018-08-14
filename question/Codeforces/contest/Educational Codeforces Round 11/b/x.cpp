#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int a[200][10];
int n,m,i,j,x,y,now;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		now++;
		a[i][1]= now;
		if (now==m) break;
		now++;
		a[i][4]= now;
		if (now==m) break;		
	}
	if (now<m){
		for (i= 1;i<=n;i++){
			now++;
			a[i][2]= now;
			if (now==m) break;
			now++;
			a[i][3]= now;
			if (now==m) break;		
		}		
	}
	for (i= 1;i<=n;i++){
		if (a[i][2]) printf("%d ",a[i][2]);
		if (a[i][1]) printf("%d ",a[i][1]);
		if (a[i][3]) printf("%d ",a[i][3]);
		if (a[i][4]) printf("%d ",a[i][4]);		
	}return 0;
}
