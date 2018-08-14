#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
struct node{
	string name;	
	int v;
	bool operator <(const node &a)const{
		return v<a.v;
	}
};
priority_queue<node> Q[maxn];
string S;
node a,b;
char s[20];
int n,m,i,j,len,x,y;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%s",s+1);
		len= strlen(s+1);
		S.clear();
		for (j= 1;j<=len;j++)
			S.push_back(s[j]);
		scanf("%d%d",&x, &y);
		Q[x].push((node){S,y});
	}
	for (i= 1;i<=m;i++){
		a= Q[i].top();
		Q[i].pop();
		len= Q[i].size();
		b= Q[i].top();
		Q[i].pop();
		len= Q[i].size();
		if (!Q[i].empty()){
			if (Q[i].top().v==b.v){
				printf("?\n");
				continue;
			}
		}
		cout<<a.name<<' '<<b.name<<endl;
	}return 0;
}