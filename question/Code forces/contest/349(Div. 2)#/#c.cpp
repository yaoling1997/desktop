#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
set<string> S;
set<string> ::iterator it;
bool vis[maxn][10];
char s[maxn];
int n,i;
void dfs(int o,int m){
	if (vis[o][m]||o-m<5) return;
	vis[o][m]= 1;
	string l(s+o-m+1,s+o+1),r(s+o-m*2+1,s+o+1-m);
	S.insert(l);
	if (l!=r) dfs(o-m,m);
	int x= 5-m;
	dfs(o-m,x);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n= strlen(s+1);
	dfs(n,2);
	dfs(n,3);
	printf("%d\n",S.size());
	it= S.begin();
	while (it!=S.end()){
		cout<<*it<<endl;
		it++;
	}return 0;
}
