#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1e5;
char s[maxn];
int len,hh,mm,a,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	scanf("%d",&a);
	len= strlen(s+1);
	hh= mm= 0;
	for (i= 1;i<=len;i++){
		if (s[i]==':') break;
		hh= hh*10+s[i]-'0';
	}
	for (j= i+1;j<=len;j++)
		mm= mm*10+s[j]-'0';
	mm+= a;
	hh+= mm/60;
	mm%= 60;
	hh%= 24;
	if (hh<10) printf("0");
	printf("%d:",hh);
	if (mm<10) printf("0");
	printf("%d",mm);
}
