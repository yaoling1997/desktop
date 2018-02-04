#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e5;
struct node{
	int x,h;
	bool operator <(const node &a)const{
		return x>a.x;
	}
};
priority_queue<node> Q;
int a[maxn];
int n,i,j,x,y,z,ans,mx;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		Q.push((node){a[i],i});
	}
	Q.push((node){(int)2e9,n+1});
	for (i= 1;i<=n;i++){
		mx= max(mx,a[i]);
		while (Q.top().h<=i)
			Q.pop();
		if (mx<=Q.top().x){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
