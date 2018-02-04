#include<cstdio>
#include<cstdlib>
using namespace std;
struct xx{
	int x;
};
xx operator +(xx a,xx b){a.x+=b.x; return a;}
xx operator -(xx a,xx b){a.x-=b.x; return a;}
xx operator *(xx a,xx b){a.x*=b.x; return a;}
xx a={2},b={2};
int main()
{
	freopen("1.out","w",stdout);
	a= a+b*a;
	printf("%d\n",a.x);
	a.x= 2;
	a= a-a+a;
	printf("%d\n",a.x);
}
