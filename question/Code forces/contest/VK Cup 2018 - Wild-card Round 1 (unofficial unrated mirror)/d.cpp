#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 100;
struct node{
	int r,c;
	int v;
	bool operator <(const node a)const{
		return v<a.v;
	}
};
priority_queue<node>Q;
char s[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	for (int i=1;i<=6;i++)
		scanf("%s",s[i]+1);

	for (int i=1;i<=2;i++)
		for (int j=1;j<=2;j++)
			Q.push((node){i,j,3});
	for (int i=1;i<=2;i++)
		for (int j=4;j<=5;j++)
			Q.push((node){i,j,4});
	for (int i=1;i<=2;i++)
		for (int j=7;j<=8;j++)
			Q.push((node){i,j,3});

	for (int i=3;i<=4;i++)
		for (int j=1;j<=2;j++)
			Q.push((node){i,j,2});
	for (int i=3;i<=4;i++)
		for (int j=4;j<=5;j++)
			Q.push((node){i,j,3});
	for (int i=3;i<=4;i++)
		for (int j=7;j<=8;j++)
			Q.push((node){i,j,2});
	
	for (int i=5;i<=6;i++)
		for (int j=1;j<=2;j++)
			Q.push((node){i,j,1});
	for (int i=5;i<=6;i++)
		for (int j=4;j<=5;j++)
			Q.push((node){i,j,2});
	for (int i=5;i<=6;i++)
		for (int j=7;j<=8;j++)
			Q.push((node){i,j,1});
	while (!Q.empty()){
		node u=Q.top();
		Q.pop();
		if (s[u.r][u.c]=='*')
			continue;
		s[u.r][u.c]='P';
		break;
	}
	for (int i=1;i<=6;i++)
		printf("%s\n",s[i]+1);
}
