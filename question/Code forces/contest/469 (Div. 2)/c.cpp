#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int p[maxn],sta[maxn],L[maxn];
set<int> Z,O;
char s[maxn];
int la,bl;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='0'){
			Z.insert(i);
		}else
			O.insert(i);
	bl=true;
	while (!Z.empty()&&bl){
		int now=*Z.begin();
		Z.erase(Z.begin());
		sta[++la]=now;
		L[la]++;
		while (O.lower_bound(now)!=O.end()){
			int x= *O.lower_bound(now);
			p[now]=x;
			L[la]++;
			now=x;
			O.erase(x);
			if (Z.lower_bound(now)!=Z.end()){
				x=*Z.lower_bound(now);
				Z.erase(x);
				p[now]=x;
				L[la]++;
				now=x;
			}else {
				bl=false;
				break;
			}
		}
	}
	if (!O.empty())
		bl=false;
	if (bl){
		printf("%d\n",la);
		for (int i=1;i<=la;i++){
			int u=sta[i];
			printf("%d",L[i]);
			while (u!=0){
				printf(" %d",u);
				u=p[u];
			}
			printf("\n");
		}
	}else {
		printf("-1");
	}
}
