#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 1000;
char s[maxn];
char d[maxn];
char a[100][10000],b[100][10000];
int K[maxn],C[maxn],S[maxn],ans[maxn];
int m,i,j,k,bl,la,L,T,t;
void get(int o){
	if (o>K[t]){
		//if (bl!=1) return;
		m++;
		memcpy(a[m],d,sizeof(d));
		memcpy(b[m],d,sizeof(d));
		return;
	}
	d[o]= 'L';
	get(o+1);
	if (bl) return;
	d[o]= 'G';
	bl= 1;
	get(o+1);
	bl= 0;
}
void deal(){
	int i,j,k,len,K= strlen(a[1]+1);
	for (i= 1;i<=m;i++){
		memset(d,0,sizeof(d));
		len= strlen(b[i]+1);
		k= 0;
		for (j= 1;j<=len;j++){
			int x= 0;
			if (b[i][j]=='L'){
				while (x<K){
					x++;
					d[++k]= a[i][x];
				}
			}else {
				while (x<K){
					x++;
					d[++k]= 'G';
				}				
			}
		}
		memcpy(b[i],d,sizeof(d));
	}
}
void check(){
	queue<int> Q[2];
	int i;
	for (i= 1;i<=m;i++) Q[0].push(i);
	for (i= 1;i<=la;i++){
		int o= (i-1)%2,n= i%2,x= ans[i];
		while (!Q[o].empty()){
			int u= Q[o].front();
			Q[o].pop();
			if (b[u][x]!='G') Q[n].push(u);
		}
	}
	bl= Q[la%2].size()==1;
}
int main()
{
	freopen("1.in","r",stdin);
	scanf("%d",&T);
	for (t= 1;t<=T;t++)
		scanf("%d%d%d",&K[t], &C[t], &S[t]);
	fclose(stdin);
	freopen("1.out","r",stdin);
	freopen("check.out","w",stdout);
	for (t= 1;t<=T;t++){
		scanf("%s%s%s",s+1, s+1, s+1);
		if (s[1]=='I') continue;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		m= 0;
		bl= 0;
		get(1);
		for (j= 2;j<=C[t];j++)
			deal();
		L= strlen(b[1]+1);
		scanf("%d",&la);
		for (i= 1;i<=la;i++)
			scanf("%d",&ans[i]);
		check();
		if (!bl){
			printf("shit");
			return 0;
		}
	}
	printf("ok");
	return 0;
}
