#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
char s[maxn],t[maxn];
int n,k,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &k);
	scanf("%s",s+1);
	for (i= 1;i<=n;i++){
		t[i]= s[i];
		if (!k) continue;
		if (s[i]+k<='z'){
			t[i]= s[i]+k;			
			k= 0;
		}else if (s[i]-k>='a'){
			t[i]= s[i]-k;
			k= 0;
		}else if ('z'-s[i]>s[i]-'a')
			k-= 'z'-s[i],t[i]= 'z';
		else k-= s[i]-'a',t[i]= 'a';
	}
	if (k==0) printf("%s",t+1);
	else printf("-1");
}
