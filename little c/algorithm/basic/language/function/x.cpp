#include<cstdio>
#include<cstdlib>
using namespace std;
void g(int );
void f(int x){
	g(++x);
}
void g(int x){
	if (x>1000){printf("shit!\n");return;}
	f(x+= x);
}
int main()
{
	freopen("1.out","w",stdout);
	f(1);
}
