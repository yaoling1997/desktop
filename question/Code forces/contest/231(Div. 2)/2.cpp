#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 1e6+2;
int s1[maxn],s2[maxn],ans[maxn];
int p,x,y,z,i,j,s,g,q,bl,bb;
int main()
{
	scanf("%d %d",&p, &x);
	for (i= 1;i<=9;i++){
		memset(s1,0,sizeof(s1));memset(s2,0,sizeof(s2));
		s1[1]= i;bl= 1;
		s= s1[1]*x/10;s2[1]= s1[1]*x%10;
		for (j= 2;j<=p;j++){
			s1[j]= s2[j-1];
			q= s;s= (s1[j]*x+q)/10;
			s2[j]= (s1[j]*x+q)%10;
		}
		if (i!=s2[p] || !s1[p] || s) bl= 0;
		if (bl){
			if (!bb){
				bb= 1;
				memcpy(ans,s1,sizeof(s1));
			}else {
				for (j= p;j>0;j--)
					if (s1[j]>ans[j]){
						bl= 0;break;
					}else if (ans[j]>s1[j]) break;
				if (bl) memcpy(ans,s1,sizeof(s1));
			}
		}
	}
	if (!bb) printf("Impossible");
	else
	for (i= p;i>0;i--) printf("%d",ans[i]);
}
