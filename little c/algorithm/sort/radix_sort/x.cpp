#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn= 100001;
int a[maxn];
vector<int> g1[10],g2[10];
int i,j,n,d= 1,l1,l2,k;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		while (a[i]/d>0) d*= 10;
	}
	l1= 10;l2= 1;	
	for (i= 1;i<=n;i++){
		int k= a[i]%l1/l2;
		g1[k].push_back(a[i]);
	}
	l2*= 10;
	for (l1*= 10;l1<=d;l1*= 10,l2*= 10){
		for (i= 0;i<=9;i++){
			int len= g1[i].size();
			for (j= 0;j<len;j++){
				int k= g1[i][j]%l1/l2;
				g2[k].push_back(g1[i][j]);
			}
		}
		swap(g1,g2);
		memset(g2,0,sizeof(g2));
	}
	for (i= 0;i<=9;i++){
		int len= g1[i].size();
		for (j= 0;j<len;j++)
			printf("%d ",g1[i][j]);
	}
}
