#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<string>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
char s[maxn];
string str[maxn];
string t;
double d[maxn];
int per[maxn];
int n;
bool cmp(int a,int b){
	return d[a]>d[b];
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		per[i]=i;
		scanf("%s",s);
		int len= strlen(s),x=0,y=0;
		for (int j=0;j<len;j++)
			if (s[j]=='s')
				x++;
			else
				y++;
		d[i]=(double)x/y;
		str[i]=s;
	}
	sort(per+1,per+n+1,cmp);
	for (int i=1;i<=n;i++)
		t+=str[per[i]];
	ll ans=0,s_num=0;
	for (int i=0;i<(int)t.size();i++)
		if (t[i]=='h')
			ans+= s_num;
		else s_num++;
	printf("%I64d",ans);
	return 0;
}
