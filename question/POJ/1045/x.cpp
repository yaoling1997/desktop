#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n;
	double Vs,R,C,w;
	scanf("%lf%lf%lf%d",&Vs, &R, &C, &n);
	while (n--){
		scanf("%lf",&w);
		//double Vr= Vs*R*C*w/sqrt(R*R*C*C*w*w+1);
		double Vr= Vs*R*C*w*sqrt(1/(R*R*C*C*w*w+1));
		printf("%.3lf\n",Vr);
	}return 0;
}
