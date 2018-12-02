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
int T;
void change(char *s){
	int len=strlen(s+1);
	int b[3]={0};
	int c[3]={0};
	for (int i=1;i<=len;i++)
		if ('0'<=s[i]&&s[i]<='9'){
			b[0]=i;
			c[0]++;
		}else if ('a'<=s[i]&&s[i]<='z'){
			b[1]=i;
			c[1]++;
		}else if ('A'<=s[i]&&s[i]<='Z'){
			b[2]=i;
			c[2]++;
		}
	int cnt=0,p=0;
	vector<int> v;
	int k[3]={'0','a','A'};
	for (int i=0;i<3;i++){
		cnt+=b[i]!=0;
		p=c[i]>c[p]?i:p;
		if (b[i]==0)
			v.pb(i);
	}
	if (cnt==3)
		return;
	else if (cnt==2){
		s[b[p]]=k[v[0]];
	}else {
		for (int i=0;i<(int)v.size();i++)
			s[i+1]=k[v[i]];
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		scanf("%s",s+1);
		change(s);
		printf("%s\n",s+1);
	}
}
