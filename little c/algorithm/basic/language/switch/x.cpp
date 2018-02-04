#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
char s[10],op;
int a,b,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%s",&a, &b, s+1);
	op= s[1];
	switch(op){
	case '+':ans= a+b;break;
	case '-':ans= a-b;break;
	case '*':ans= a*b;break;
	case '/':ans= a/b;break;
	default:printf("Are you a stupid?");return 0;
	}
	printf("%d",ans);
	return 0;
}
