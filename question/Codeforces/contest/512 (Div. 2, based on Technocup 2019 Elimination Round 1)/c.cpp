#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
char s[maxn];
int n;
bool ok(int o){
	int now=0,cnt=0;
	for (int i=1;i<=n;i++){
		now+=s[i]-'0';
		if (now>o)
			return 0;
		else if (now==o){
			now=0;
			cnt++;
		}
	}
	return now==0&&cnt>1;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=0;i<=900;i++)
		if (ok(i)){
			printf("YES");
			return 0;
		}
	printf("NO");
	return 0;
}
