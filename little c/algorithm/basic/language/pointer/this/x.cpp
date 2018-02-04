#include<cstdio>
#include<cstdlib>
using namespace std;
struct node{
	int x,y,s;
	void xx(int x){
		this->x= x;
	}
};
node a;
int main()
{
	a.x= 10;
	a.xx(15);
	printf("%d",a.x);
}
