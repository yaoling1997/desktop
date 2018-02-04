#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
queue<int> g;
int x;
int main()
{
	if (g.empty()) printf("shit!\n");
	g.push(1);g.push(2);
	x= g.size();
	x= g.front();
	x= g.back();
	g.pop();
	return 0;
}
