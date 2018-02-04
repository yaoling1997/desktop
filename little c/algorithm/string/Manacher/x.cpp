#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn= 3001;
int rad[maxn];
char s[maxn],st[maxn];
int id,mx,len,n,i,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",st+1);
	len= strlen(st+1);
	s[0]='$';
	for (i= 1;i<=len;i++){
		s[++n]= '#';
		s[++n]= st[i];
	}
	s[++n]= '#';
	len= n;
	for (i= 1;i<=len;i++){
		if (mx>i) rad[i]= min(rad[2*id-i],mx-i+1);
		else rad[i]= 1;
		while (s[i-rad[i]]==s[i+rad[i]]) rad[i]++;
		if (i+rad[i]-1>mx){
			mx= i+rad[i]-1;
			id= i;
		}
	}
	for (i= 1;i<=len;i++)
		ans= max(ans,rad[i]-1);
	printf("%d",ans);
	return 0;
}
