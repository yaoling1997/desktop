#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int maxn= 3001;
stack<int> S;
queue<int> Q;
priority_queue<int> PQ;
int i,x,y,n;
bool b1,b2,b3;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		b1= b2= b3= 1;
		while (!S.empty()) S.pop();
		while (!Q.empty()) Q.pop();
		while (!PQ.empty()) PQ.pop();
		for (i= 1;i<=n;i++){
			scanf("%d%d",&x, &y);
			if (x==1){
				S.push(y);
				Q.push(y);
				PQ.push(y);
			}else {
				if (S.empty()){
					b1= b2= b3= 0;
					continue;
				}
				if (S.top()!=y) b1= 0;
				if (Q.front()!=y) b2= 0;
				if (PQ.top()!=y) b3= 0;
				S.pop();
				Q.pop();
				PQ.pop();
			}
		}
		if (b1&&!b2&&!b3) printf("stack\n");
		else if (!b1&&b2&&!b3) printf("queue\n");
		else if (!b1&&!b2&&b3) printf("priority queue\n");
		else if (!b1&&!b2&&!b3) printf("impossible\n");
		else printf("not sure\n");
	}return 0;
}
