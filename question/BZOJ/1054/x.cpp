#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 300001,maxm= 600000;
struct node{
	int c[6][6],s,bb;
};
node l[2][maxn];
int b[2][maxm],f[2],r[2];
int i,j,n,m,sum,ans,xx,yy;
bool bl;
int com(int x,int y){
	return (4-x)*4+(4-y);
}
void expand(int o){
	int i,j,ff= ++f[o],rr= r[o];
	for (i= 1;i<=4;i++)
		for (j= 1;j<=4;j++)
			if (l[o][ff].c[i][j]){
				if (!l[o][ff].c[i][j+1]){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].bb;
					sum^= (1<<com(i,j));sum^= (1<<com(i,j+1));
					if (b[o][sum])rr--;
					else if(b[o^1][sum]){
						ans= l[o][rr].s;
						rr= b[o^1][sum];
						ans+= l[o^1][rr].s;
						printf("%d",ans);
						bl= 1;
						return;
					}else {
						b[o][sum]= rr;
						swap(l[o][rr].c[i][j+1],l[o][rr].c[i][j]);
						l[o][rr].bb= sum;
					}
				}
				if (!l[o][ff].c[i][j-1]){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].bb;
					xx= com(i,j);yy= com(i,j-1);
					sum^= (1<<com(i,j));sum^= (1<<com(i,j-1));
					if (b[o][sum])rr--;
					else if(b[o^1][sum]){
						ans= l[o][rr].s;
						rr= b[o^1][sum];
						ans+= l[o^1][rr].s;
						printf("%d",ans);
						bl= 1;
						return;
					}else {
						b[o][sum]= rr;
						swap(l[o][rr].c[i][j-1],l[o][rr].c[i][j]);
						l[o][rr].bb= sum;						
					}
				}
				if (!l[o][ff].c[i+1][j]){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].bb;
					sum^= (1<<com(i,j));sum^= (1<<com(i+1,j));
					if (b[o][sum])rr--;
					else if(b[o^1][sum]){
						ans= l[o][rr].s;
						rr= b[o^1][sum];
						ans+= l[o^1][rr].s;
						printf("%d",ans);
						bl= 1;
						return;
					}else {
						b[o][sum]= rr;
						swap(l[o][rr].c[i+1][j],l[o][rr].c[i][j]);
						l[o][rr].bb= sum;						
					}
				}
				if (!l[o][ff].c[i-1][j]){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].bb;
					sum^= (1<<com(i,j));sum^= (1<<com(i-1,j));
					if (b[o][sum])rr--;
					else if(b[o^1][sum]){
						ans= l[o][rr].s;
						rr= b[o^1][sum];
						ans+= l[o^1][rr].s;
						printf("%d",ans);
						bl= 1;
						return;
					}else {
						b[o][sum]= rr;
						swap(l[o][rr].c[i-1][j],l[o][rr].c[i][j]);
						l[o][rr].bb= sum;													
					}
				}									
			}
	r[o]= rr;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	char ch;memset(l[0][1].c,-1,sizeof(l[0][1].c));
	memset(l[1][1].c,-1,sizeof(l[1][1].c));
	for (i= 1;i<=4;i++){
		for (j= 1;j<=4;j++){
			scanf("%c",&ch);
			l[0][1].c[i][j]= ch-'0';
			sum= sum*2+l[0][1].c[i][j];
		}
		scanf("%c",&ch);
	}
	scanf("%c",&ch);
	l[0][1].bb= sum;
	b[0][sum]= 1;sum= 0;
	for (i= 1;i<=4;i++){
		for (j= 1;j<=4;j++){
			scanf("%c",&ch);
			l[1][1].c[i][j]= ch-'0';
			sum= sum*2+l[1][1].c[i][j];
		}
		scanf("%c",&ch);
	}
	if (sum==l[0][1].bb){
		printf("0");
		return 0;
	}
	l[1][1].bb= sum;
	b[1][sum]= 1;
	r[0]= r[1]= 1;
	while ((f[0]<r[0] || f[1]<r[1]) && !bl){
		if (r[0]<=r[1] && (f[0]<r[0])) expand(0);
		else expand(1);
	}
	return 0;
}
