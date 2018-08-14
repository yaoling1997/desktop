#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e6;
char s[maxn],sta[maxn];
int n,i,ans,p,bl,la;
bool left(char c){
	return c=='<'||c=='{'||c=='['||c=='(';
}
bool match(char a,char b){
	if (a=='<'&&b=='>') return 1;
	if (a=='{'&&b=='}') return 1;
	if (a=='['&&b==']') return 1;
	if (a=='('&&b==')') return 1;
	return 0;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n= strlen(s+1);
	bl= 1;
	for (i= 1;i<=n;i++){
		if (left(s[i])) sta[++la]= s[i];
		else {
			if (!la){
				bl= 0;
				goto pn;
			}
			if (match(sta[la],s[i])) la--;
			else {
				ans++;
				la--;
			}
		}
	}
	if (la) bl= 0;
 pn:if (bl) printf("%d\n",ans);
	else printf("Impossible\n");
	return 0;
}
