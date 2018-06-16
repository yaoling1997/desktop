#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5,oo=1e9;
struct edge{
	int a,b,w;
}edges[maxn];
map<int,int> M[maxn];
map<int,int>:: iterator it,it2;
int n,m,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x, &y, &z);
		edges[i]=(edge){x,y,z};
	}
	for (int i=1;i<=n;i++)
		M[i][oo]=0;
	for (int i=m;i>=1;i--){
		int x,y,z;
		x=edges[i].a;
		y=edges[i].b;
		z=edges[i].w;
		it= M[y].upper_bound(z);
		int xx=it->first;
		int yy=it->second;
		it= M[x].upper_bound(z);
		if (it->second<yy+1){
			M[x][z]=yy+1;
			ans=max(ans,yy+1);
			it=M[x].find(z);
			while (it!=M[x].begin()){
				it2=it;
				it2--;
				if (it2->second<it->second){
					M[x].erase(it2);
				}else
					break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
