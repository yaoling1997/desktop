#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
struct point{
	int x,y;
}a[10];
int i;
bool cmpx(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool cmpy(point a,point b){
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	for (i= 1;i<=3;i++)
		scanf("%d%d",&a[i].x, &a[i].y);
	if ((a[1].x==a[2].x&&a[2].x==a[3].x)||(a[1].y==a[2].y&&a[2].y==a[3].y)) printf("1");
	else {
		sort(a+1,a+3+1,cmpx);
		if (a[1].x==a[2].x){
			if (a[1].y<a[3].y&&a[3].y<a[2].y) printf("3");
			else printf("2");
		}else if (a[2].x==a[3].x){
			if (a[2].y<a[1].y&&a[1].y<a[3].y) printf("3");
			else printf("2");			
		}else {
			sort(a+1,a+3+1,cmpy);
			if (a[1].y==a[2].y){
				if (a[1].x<a[3].x&&a[3].x<a[2].x) printf("3");
				else printf("2");				
			}else if (a[2].y==a[3].y){
				if (a[2].x<a[1].x&&a[1].x<a[3].x) printf("3");
				else printf("2");							
			}else printf("3");
		}
	}
}
