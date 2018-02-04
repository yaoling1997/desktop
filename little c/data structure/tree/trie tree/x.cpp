#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 1000,sig= 101;
struct node{
	int next[sig];
	bool bl;
};
node a[maxn];
char s[maxn];
int top,now,i,j,n,m,len;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for (i= 1;i<=n;i++){
		scanf("%s\n",s+1);
		len= strlen(s+1);
		now= 0;
		for (j= 1;j<=len;j++)
			if (a[now].next[s[j]]!=0)
				now= a[now].next[s[j]];
			else {
				a[now].next[s[j]]= ++top;
				now= top;
			}
		a[now].bl= 1;		
	}
	bool bl;
	for (i= 1;i<=m;i++){
		scanf("%s",s+1);
		len= strlen(s+1);
		bl= 1;
		now= 0;
		for (j= 1;j<=len;j++)
			if (a[now].next[s[j]]!=0)
				now= a[now].next[s[j]];
			else {
				bl= 0;
				break;
			}
		if (!a[now].bl) bl= 0;
		if (bl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;	
}
