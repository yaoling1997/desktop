#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int x,y,p;
	bool operator <(const node &a)const{
		return x>a.x||(x==a.x&&y>a.y);
	};
};
priority_queue<node> Q;
char s[10];
int n,i,k,x,y;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for (;;){
		scanf("%s",s+1);
		if (strlen(s+1)==1) break;
		n++;
		scanf("%d%d",&x, &y);
		Q.push((node){y,x,y});
	}
	scanf("%d",&k);
	for (i= 1;i<=k;i++){
		node u= Q.top();
		Q.pop();
		printf("%d\n",u.y);
		u.x+= u.p;
		Q.push(u);
	}
	return 0;
}
