#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;
map<int,int> g;
map<int,int> ::iterator it;
int main()
{
	freopen("1.out","w",stdout);
	if (g.empty()) printf("yes!\n");
	for (int i= 1;i<=5;i++)	g[i] = i;
	g.erase(2);
	printf("%d\n",g.size());
	it= g.find(4);
	printf("%d\n",it->second);
	int x= g.count(3);
	printf("%d\n",x);
	g.clear();
	return 0;
}
