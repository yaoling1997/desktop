#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
const int maxn= 3001;
struct student{
	int h;
	char sex;
	string music,PE;
};
vector<int> g[maxn];
int d[maxn],vis[maxn];
student u,a[maxn],b[maxn];
string s;
char ch;
int T,i,j,n,x,top1,top2,ans,tim;
bool ok(student a,student b){
	if (a.sex==b.sex) return 1;
	if (abs(a.h-b.h)>40) return 1;
	if (a.music!=b.music) return 1;
	if (a.PE==b.PE) return 1;
	return 0;
}
void init(int n){
	memset(d,0,sizeof(d));
	ans= top1= top2= 0;	
	for (i= 1;i<=n;i++)
		g[i].clear();
}
bool find(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (vis[v]!=tim){
			vis[v]= tim;
			if (!d[v]||find(d[v])){
				d[v]= o;
				return 1;
			}
		}
	}return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	for (int a1= 1;a1<=T;a1++){
		cin>>n;
		init(n);
		for (i= 1;i<=n;i++){
			cin>>u.h;
			cin>>u.sex;
			cin>>u.music;
			cin>>u.PE;
			if (u.sex=='M') a[++top1]= u;
			else b[++top2]= u;
		}
		for (i= 1;i<=top1;i++)
			for (j= 1;j<=top2;j++)
				if (!ok(a[i],b[j]))
					g[i].push_back(j);
		for (i= 1;i<=top1;i++){
			tim++;
			if (find(i)) ans++;
		}
		cout<<n-ans<<endl;
	}return 0;
}
