#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
int sta[maxn];
int n,la,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);	
	for (i= 1;i<=n;i++){
		sta[++la]= 1;
		while (sta[la]==sta[la-1])
			++sta[--la];
	}
	for (i= 1;i<=la;i++)
		printf("%d%c",sta[i], i<la?' ':'\n');
	return 0;
}
