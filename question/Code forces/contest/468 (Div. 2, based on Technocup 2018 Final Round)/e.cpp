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
vector<string> g[50];
int ok[50];
char st[maxn],look[maxn],sta[maxn];
string s,t;
int n,ans,la;
int cti(char c){
	return c-'a';
}
int solve(int o){
	int len= g[o].size();
	/*for (int i=0;i<len;i++)
	printf("%s\n",g[o][i].c_str());*/
	int re=0;
	for (int i=0;i<n;i++){
		la=0;
		for (int j=0;j<len;j++){
			int u=cti(g[o][j][i]);
			sta[++la]=u;
		}
		sort(sta+1,sta+la+1);
		int now=0;
		sta[0]=sta[la+1]=-1;
		for (int i=1;i<=la;i++){
			if (sta[i]!=sta[i-1]&&sta[i]!=sta[i+1])
				now++;
		}
		re=max(re,now);
	}
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",st);
	n=strlen(st);
	s=st;
	for (int i=0;i<n;i++){
		char c=s[0];
		g[cti(s[0])].pb(s);
		s.pb(s[0]);
		s.erase(s.begin());
		int len= s.size();
		len=len+1;
	}
	for (int i='a';i<='z';i++){
		int x=cti(i);
		if (g[x].empty())
			continue;		
		ok[x]=solve(x);
	}
	for (int i='a';i<='z';i++)
		ans+=ok[cti(i)];
	printf("%.10f",(double)ans/n);
	return 0;
}
