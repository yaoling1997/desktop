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
char s[maxn];
int p[maxn];
int i,j,bl,n,now,m,x;
int num(char c){
	return c=='('?1:-1;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n= strlen(s+1);
	for (i= 1;i<=n;i++)
		p[i]= p[i-1]+num(s[i]);
	for (i= n;i>0;i--)
		if (s[i]=='('&&p[i-1]>0){
			bl= 1;
			s[i]= ')';
			now= p[i-1]-1;
			break;
		}
	if (!bl) printf("No solution");
	else {		
		for (m= (n-i-now)/2;m;m--)
			s[++i]= '(';
		for (i++;i<=n;i++)
			s[i]= ')';
		printf("%s",s+1);
	}
	return 0;
}
