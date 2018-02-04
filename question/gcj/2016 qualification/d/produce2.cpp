#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 1000;
char s[]= "1.out";
char d[maxn];
char a[100][10000],b[1000][1000];
int m,i,j,k,bl;
void get(int o){
	if (o>i){
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
int main()
{
	for (i= 1;i<=5;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		m= 0;
		s[0]= i+'0';
		freopen(s,"w",stdout);
		bl= 0;
		get(1);
		for (j= 1;j<=4;j++){
			printf("%d\n",j);
			for (k= 1;k<=m;k++)
				printf("%s\n",b[k]+1);
			printf("\n");
			deal();
		}
		fclose(stdout);
	}return 0;
}
