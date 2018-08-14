#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 2e6;
char s[maxn];
int a[maxn],b[maxn];
int len,la,lb,i;
void get(char *s,int *a,int &la){
	scanf("%s",s+1);
	len= strlen(s+1);
	la= 0;
	int i= 1;
	while (i<=len&&s[i]=='0') i++;
	while (i<=len){
		a[++la]= s[i]-'0';
		i++;
	}
	if (!la) la= 1;
	reverse(a+1,a+la+1);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	get(s,a,la);
	get(s,b,lb);
	if (la>lb) printf(">");
	else if (la<lb) printf("<");
	else {
		for (i= la;i>0;i--)
			if (a[i]>b[i]){
				printf(">");
				return 0;
			}else if (a[i]<b[i]){
				printf("<");
				return 0;
			}
		printf("=");
	}return 0;
}
