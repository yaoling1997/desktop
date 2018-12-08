#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int ans1,ans2;
int a,b,x,y,z;
int get(int x,int y){
	ans1=10;
	ans2=5;
	x^=ans1;
	y^=ans2;
	if (x>y)
		return 1;
	if (x==y)
		return 0;
	return -1;
}
int main()
{
	freopen("1.out","w",stdout);
	printf("? 0 0\n");
	fflush(stdout);
	scanf("%d",&z);
	//z=get(0,0);
	if (z==1||z==-1){//a!=b
		for (int i=29;i>=0;i--){
			printf("? %d %d\n",a,b^(1<<i));
			fflush(stdout);
			scanf("%d",&x);
			//x=get(a,b^(1<<i));
			printf("? %d %d\n",a^(1<<i),b);
			fflush(stdout);
			scanf("%d",&y);
			//y=get(a^(1<<i),b);
			if (z==1){
				if(x==1){
					a^=1<<i;
					if (y==0)
						z=0;
					else if (y==-1)
						b^=1<<i;
				}else if (x==0){
					a^=1<<i;
					z=0;
				}else {
					if (y==0||y==-1){
						a^=1<<i;
						if (y==0)
							z=0;
						else
							z=-1;
					}
				}
			}else if (z==-1){
				if (x==1){
					b^=1<<i;
					if (y==1)
						z=1;
					else if (y==0)
						z=0;
					else if (y==-1)
						a^=1<<i;
				}else if (x==0){
					b^=1<<i;
					z=0;
				}else {
					if (y==0){
						z=0;
						b^=1<<i;
					}else if (y==-1)
						b^=1<<i;
				}
			}else {
				for (;i>=0;i--){
					printf("? %d %d\n",a,b^(1<<i));
					fflush(stdout);
					scanf("%d",&x);
					//x=get(a,b^(1<<i));
					if (x==1){
						a^=1<<i;
						b^=1<<i;
					}					
				}
				break;
			}
		}
	}else if (x==0){//a==b
		for (int i=29;i>=0;i--){
			printf("? %d %d\n",0,1<<i);
			fflush(stdout);
			scanf("%d",&x);
			//x=get(0,1<<i);
			if (x==1){
				a^=1<<i;
				b^=1<<i;
			}
		}
	}
	printf("! %d %d\n",a,b);
	fflush(stdout);
}
