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
struct node{
	int x,y,h;
}a[maxn];
vector<int> sta[maxn];
int n,i,j,la,now;
bool cmp(node a,node b){
	return a.x<b.x||((a.x==b.x)&&(a.y>b.y));
}
void print(int o){
	if (!o) return;
	int x;
	for (;;){
		int len= sta[o].size();
		if (sta[o][len-1]<=now){
			now= sta[o][len-1];
			x= a[now].h;
			break;
		}
		sta[o].pop_back();
	}
	print(o-1);
	printf("%d%c",x, o<la?' ':'\n');
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&a[i].x, &a[i].y);
		a[i].h= i;
	}
	sort(a+1,a+n+1,cmp);
	sta[0].push_back(0);
	for (i= 1;i<=n;i++){
		int len= sta[la].size();
		if (a[i].y>a[sta[la][len-1]].y)
			sta[++la].push_back(i);
		else {
			int l= 0,r= la;
			while (l+1<r){
				int m= (l+r)>>1,len= sta[m].size();
				if (a[sta[m][len-1]].y>=a[i].y) r= m;
				else l= m;
			}
			sta[r].push_back(i);
		}
	}
	printf("%d\n",la);
	now= sta[la][sta[la].size()-1];
	print(la);
	return 0;
}
