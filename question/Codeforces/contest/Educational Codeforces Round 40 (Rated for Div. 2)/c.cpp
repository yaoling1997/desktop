#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=5e5;
int a[maxn];
int n,gap;
bool out(int x,int y){
	return x<0||y<0||x>=1e9||y>=gap;
}
bool ok(){
	int x=a[1]/gap;
	int y=a[1]%gap;
	if (y==0){
		x--;
		y=gap;
	}
	y--;
	//printf("%d %d\n",x,y);
	for (int i=2;i<=n;i++){
		int d=a[i]-a[i-1];
		if (d==gap){
			x++;
		}else if (d==-gap){
			x--;
		}else if (d==1){
			y++;
		}else if (d==-1){
			y--;
		}else 
			return false;
		//printf("%d %d\n",x,y);
		if (out(x,y))
			return false;
	}
	return true;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	gap=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (i>1){
			gap=max(gap,abs(a[i]-a[i-1]));
		}
	}
	if (ok()){
		printf("YES\n");
		printf("%d %d\n",(int)1e9,gap);
	}else {
		printf("NO");
	}
	return 0;
}
