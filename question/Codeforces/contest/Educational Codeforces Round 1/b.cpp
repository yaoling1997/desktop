#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e4;
char s[maxn],t[maxn];
int i,len,n,x,y,z,m,la;
int main()
{
	scanf("%s",s+1);
	len= strlen(s+1);
	scanf("%d",&n);
	for (int N= 1;N<=n;N++){
		scanf("%d%d%d",&x, &y, &z);
		m= y-x+1;
		z%= m;
		la= 0;
		for (i= y-z+1;i<=y;i++)
			t[++la]= s[i];
		for (i= x;i<y-z+1;i++)
			t[++la]= s[i];
		for (i= x;i<=y;i++)
			s[i]= t[i-x+1];
	}
	printf("%s",s+1);
	return 0;
}
