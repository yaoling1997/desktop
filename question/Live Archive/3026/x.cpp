#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn= 2000000;
int f[maxn];
char s[maxn];
int len,i,n,cnt;
void kmp(char *s){
	int i,k= 0,len= strlen(s+1);	
	for (i= 2;i<=len;i++){
		while (k && s[i]!=s[k+1]) k= f[k];
		if (s[k+1]==s[i]) k++;
		f[i]= k;
	}		
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		if (!n) break;
		cnt++;
		printf("Test case #%d\n",cnt);
		scanf("%s",s+1);
		len= strlen(s+1);
		kmp(s);
		for (i= 2;i<=len;i++)
			if (f[i]){
				int x= i-f[i];
				if (i%x==0) printf("%d %d\n",i, i/x);
			}
		printf("\n");
	}
	return 0;
}
