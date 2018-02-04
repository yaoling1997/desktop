#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;
set<int> g;
int x;
int main()
{
	freopen("1.out","w",stdout);
	if (g.empty()) printf("yes\n");
	g.insert(1);g.insert(1);g.insert(2);
	x= g.erase(1);
	printf("%d %d\n",g.size(),x);
	g.insert(1);g.insert(1);g.insert(2);	
	g.erase(g.find(1));
	printf("%d\n",g.size());
	x= g.count(2);printf("%d\n",x);
	g.clear();
	return 0;
}
