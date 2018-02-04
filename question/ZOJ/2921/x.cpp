#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int x,s;
	bool operator <(const node &a)const{
		return s>a.s;
	}
};
priority_queue<node> Q;
int now,x,y,z,i,n,T,ans;
void init(){
	now= ans= 0;
	while (!Q.empty()) Q.pop();
}
int main()
{
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		init();
		for (i= 1;i<=n;i++){
			scanf("%d%d%d",&x, &y, &z);
			now+= x;
			if (now>=z){
				Q.push((node){z,y});
				now-= z;
				ans+= z*y;
			}else {
				ans+= now*y;
				z-= now;
				Q.push((node){now,y});
				now= 0;
				while (z){
					if (Q.empty()) break;
					node u= Q.top();
					if (u.s>=y) break;
					Q.pop();
					if (u.x>z){
						ans+= z*(y-u.s);
						u.x-= z;
						Q.push(u);
						Q.push((node){z,y});
						z= 0;
					}else {
						ans+= u.x*(y-u.s);
						z-= u.x;
						Q.push((node){u.x,y});
					}
				}
			}
		}
		printf("%d\n",ans);
	}return 0;
}
