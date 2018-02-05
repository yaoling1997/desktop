#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int a[30],b[30];
int m[3][8]={{1,3,5,7,9,11,24,22},
						{13,14,5,6,17,18,21,22},
						{1,2,18,20,12,11,15,13}};
bool bl= false;
bool jump(int o,int x){
	memcpy(b,a,sizeof(b));
	for (int i= 0;i<8;i++)
		b[m[o][i]]= a[m[o][(i+x+8)%8]];
	bool bb= true;
	for (int i= 1;i<=24;i+= 4)
		for (int j= 1;j<=3;j++)
			if (b[i+j]!=b[i])
				bb= false;
	return bb;
}
void solve(int o){
	if (jump(o,2))
		bl= true;
	if (jump(o,-2))
		bl= true;
}
int main()
{
	for (int i= 1;i<=24;i++)
		scanf("%d",&a[i]);
	for (int i= 0;i<3;i++)
		solve(i);
	printf("%s",bl?"YES":"NO");
	return 0;
}
