#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
struct node{
	int x1,y1,x2,y2,no;
}a[100];
int n,m,i;
bool inWindow(int x,int y,node o){
	if (o.x1<=x&&x<=o.x2)
		if (o.y1<=y&&y<=o.y2)
			return 1;
	return 0;
}
void solve(int x,int y){
	int i,p= 0;
	for (i= n;i>=1;i--)
		if (inWindow(x,y,a[i])){
			p= i;
			break;
		}
	if (!p)
		printf("IGNORED\n");
	else{
		printf("%d\n",a[p].no);
		node t= a[p];
		for (i= p;i<n;i++)
			a[i]= a[i+1];
		a[n]= t;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		int x,y,xx,yy;
		scanf("%d%d%d%d",&x, &y, &xx, &yy);
		a[i]= (node){x,y,xx,yy,i};
	}
	for (i= 1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		solve(x,y);
	}
	return 0;
}

