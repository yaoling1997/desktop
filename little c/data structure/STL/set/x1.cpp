#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;
multiset<int> g;
multiset<int> ::iterator it,it1,it2;
int x,i;
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
	for (i= 1;i<=20;i++)
		g.insert(i);
	printf("\n\n\n");
	for (it= g.begin();it!=g.end();it++)
		printf("%d ",*it);
	printf("\n*******************\n");
	g.clear();
	for (i= 1;i<=5;i++)
		g.insert(2);
	g.insert(1);g.insert(3);
	it= g.find(2);it1= --it;it++;it2= ++it;
	printf("%d %d\n",*(it1),*(it2));
	return 0;
}
