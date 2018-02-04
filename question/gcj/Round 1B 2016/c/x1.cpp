#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e3;
map<string,int> fm,sm;
vector<int> g[maxn];
string s,t;
int d[maxn],vis[maxn];
int T,ans,i,j,x,y,n,ft,st,Max_pp,tim;
void init(){
	memset(d,0,sizeof(d));
	fm.clear();
	sm.clear();
	for (i= 1;i<=ft;i++)
		g[i].clear();
	ft= st= 0;
	Max_pp= 0;
}
int find(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (vis[v]==tim) continue;
		vis[v]= tim;
		if (!d[v]||find(d[v])){
			d[v]= o;
			return 1;
		}
	}return 0;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		init();
		for (i= 1;i<=n;i++){
			cin>> s>> t;
			if (!fm.count(s))
				fm[s]= ++ft;
			if (!sm.count(t))
				sm[t]= ++st;
			g[fm[s]].push_back(sm[t]);
		}
		for (i= 1;i<=ft;i++){
			tim++;
			Max_pp+= find(i);
		}
		ans= n-(ft+st-Max_pp);
		printf("%d\n",ans);
	}return 0;
}
