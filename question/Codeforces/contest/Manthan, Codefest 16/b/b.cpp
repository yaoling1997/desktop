#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 6e5;
int sta[maxn];
int n,m,i,j,cnt,la;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&m);
	for (i= 1;i<=5e5;i++){
		j= i;
		while (j%5==0){
			cnt++;
			j/= 5;
		}
		if (cnt==m) sta[++la]= i;
		if (cnt>m) break;
	}
	printf("%d\n",la);
	for (i= 1;i<=la;i++)
		printf("%d%c",sta[i],i<la?' ':'\n');
	return 0;
}
