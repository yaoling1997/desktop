#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
map<string,string> M;
char s[maxn],t[maxn];
int n,m;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		scanf("%s%s",s,t);
		string tmp=t;
		M[tmp+";"]=s;
	}
	for (int i=1;i<=m;i++){
		scanf("%s%s",s,t);
		printf("%s %s #%s\n",s,t,M[t].c_str());
	}
	return 0;
}
