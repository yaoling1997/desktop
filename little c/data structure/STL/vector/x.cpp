#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
vector<int> g;
int i,j,k;
int main()
{
	freopen("1.out","w",stdout);
	for (i= 1;i<=10;i++)
		g.push_back(i);
	printf("%d\n",g.front());
	printf("%d\n",g.back());
	g.pop_back();
	for (i= 1;i<=20;i++)
		g.erase(g.begin(),g.begin()+2);
	g.insert(g.begin(),3);
	g.insert(g.begin()+4,4,3);
	g.insert(g.begin(),g.begin()+5,g.begin()+10);
	if (g.empty()) printf("yes");
	else printf("%d\n",g[0]);
	printf("%d",(int)g.size());
	g.clear();
	return 0;
}
