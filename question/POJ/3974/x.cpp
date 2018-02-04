#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e6;
char a[maxn],s[maxn];
int rad[maxn];
int len,i,ans,n,id,mx,T;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%s",a+1)>0){
		if (a[1]=='E') break;
		T++;
		len= strlen(a+1);
		n= 0;
		s[0]= '?';
		for (i= 1;i<=len;i++){
			s[++n]= '#';
			s[++n]= a[i];
		}
		s[++n]= '#';
		id= mx= 0;
		ans= 0;
		for (i= 1;i<=n;i++){
			if (i<=mx) rad[i]= min(rad[2*id-i],mx-i+1);
			else rad[i]= 1;
			while (s[i+rad[i]]==s[i-rad[i]]) rad[i]++;
			if (i+rad[i]-1>mx){
				mx= i+rad[i]-1;
				id= i;
			}
			ans= max(ans,rad[i]-1);
		}
		printf("Case %d: %d\n",T, ans);
	}return 0;
}
