#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int n,q,now;
void go(int n,int q){
	if (n==1){
		now++;
		return;
	}
	int x= n/2,y= n-x;
	if (q>x){
		go(y,y-(q-x)+1);
	}else {
		now+= y;		
		go(x,x-q+1);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &q);
	go(n,q);
	printf("%d",now);
	return 0;
}
