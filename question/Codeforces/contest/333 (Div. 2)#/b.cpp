#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
struct ni{
	int x,h;
	bool operator <(const ni &a)const{
		return x>a.x;
	}
};
struct na{
	int x,h;
	bool operator <(const na &a)const{
		return x<a.x;
	}
};
priority_queue<ni> Qmin;
priority_queue<na> Qmax;
int a[maxn];
int ans,m,M,x,i,j,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	j= 1;
	for (i= 1;i<=n;i++){
		Qmax.push((na){a[i],i});
		Qmin.push((ni){a[i],i});
		while (Qmax.top().x-Qmin.top().x>1){
			j++;
			while (Qmax.top().h<j) Qmax.pop();
			while (Qmin.top().h<j) Qmin.pop();
		}
		ans= max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
