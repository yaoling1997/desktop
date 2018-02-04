#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4;
char s[maxn],t[maxn];
int a,b,n,i,x,y,cnt,l,r,len,N,k,z;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	t[len= 1]= '+';
	while (scanf("%s",s+1)>0){
		if (s[1]=='=') break;
		if (s[1]=='?'){
			cnt++;
			if (cnt==1) a++;
			else if (y==1) a++;
			else b++;
		}else {
			if (s[1]=='+') y= 1;
			else y= -1;
			t[++len]= s[1];
		}
	}
	scanf("%d",&n);
	l= a-b*n;r= a*n-b;
	if (l<=n&&n<=r){
		printf("Possible\n");
		k= (n+b)/a;
		r= (n+b)%a;
		y= z=0;
		if (!k){
			y= a-r;
			z= y/b+(y%b!=0);
		}
		for (i= 1;i<=len;i++){
			if (t[i]=='+'){
				if (i!=1) printf("+ ");
				x= k;
				if (r){
					r--;
					x++;
				}
				x= max(x,1);
				printf("%d ",x);
			}else {
				x= 1;
				if (y){
					x+= min(z,y);
					y= max(y-z,0);
				}
				printf("- %d ",x);
			}
		}
		printf("= %d\n",n);
	}else printf("Impossible\n");
	return 0;
}
