#include<cstdio>
#include<cstdlib>
using namespace std;
int x;
int getint(){
	char c= getchar();int re= 0,p= 1;
	while ((c<'0'||c>'9')&&c!='-') c= getchar();
	if (c=='-') p*= -1,c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re*p;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	x= getint();
	printf("%d",x);
	return 0;
}
