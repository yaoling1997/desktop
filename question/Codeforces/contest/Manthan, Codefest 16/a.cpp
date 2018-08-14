#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e4;
int f[maxn];
int a,b,c,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&a, &b, &c);
	f[0]= 1;
	for (i= 0;i<=c;i++)
		if (f[i]){
			f[i+a]= 1;
			f[i+b]= 1;
		}
	printf("%s",f[c]?"Yes":"No");
}
