#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 300001;
char ch;
int c[maxn],b[maxn];
int n,v,i,top,tot,x,sum;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d",&n, &v);
	for (int a1= 1;a1<=n;a1++){
		do ch= getchar();
		while (ch<'A'||ch>'Z');
		scanf("%d",&x);
		if (ch=='I'){
			if (x>=v)
				c[++top]= x,sum++;
		}else if (ch=='A'){
			for (i= 1;i<=top;i++)
				c[i]+= x;
		}else if (ch=='S'){
			for (i= 1;i<=top;i++)
				c[i]-= x;
			tot= 0;
			for (i= 1;i<=top;i++)
				if (c[i]>=v) c[++tot]= c[i];
			top= tot;
		}else {
			if (x>top) {printf("-1\n");continue;}
			sort(c+1,c+top+1);
			printf("%d\n",c[top-x+1]);
		}
	}
	printf("%d",sum-top);
	return 0;
}
