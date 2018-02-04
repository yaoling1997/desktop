#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
struct node{
	int x,y;
	bool operator <(const node &a)const{
		return x<a.x || (x==a.x && y<a.y);
	}
};
int i;
int main()
{
	priority_queue<node> g;
	g.push((node){1,1});g.push((node){1,1});
	g.push((node){2,1});g.push((node){1,2});
	if (!g.empty()) printf("yes\n");
	printf("%d %d\n",g.top().x,g.top().y);
	g.pop();
	printf("%d\n",g.size());
	return 0;
}
