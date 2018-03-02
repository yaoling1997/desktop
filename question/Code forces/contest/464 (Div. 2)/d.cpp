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
typedef pair<char,char> PA;
PA sta[maxn];
char s[maxn],t[maxn];
int f[maxn];
int la,n;
int cti(char c){
	return c-'a';
}
int find(int o){
	if (o==f[o])
		return o;
	return f[o]=find(f[o]);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s%s",s,t);
	for (int i='a';i<='z';i++)
		f[cti(i)]=cti(i);
	for (int i=0;i<n;i++){
		int x=cti(s[i]),y=cti(t[i]);
		if (find(x)!=find(y)){
			f[find(x)]=find(y);
			sta[++la]=make_pair('a'+x,'a'+y);
		}
	}
	printf("%d\n",la);
	for (int i=1;i<=la;i++)
		printf("%c %c\n",sta[i].first,sta[i].second);
	return 0;
}
