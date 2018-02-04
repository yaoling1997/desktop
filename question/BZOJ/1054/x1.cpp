#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 100001,maxm= 100000;
struct node{
	int c;
	short s;
};
node l[2][maxn];
int b[2][maxm],f[2],r[2];
int i,j,n,m,sum,ans,xx,yy,zz;
bool bl;
int com(int x,int y){
	return (4-x)*4+(4-y);
}
void expand(int o){
	int i,j,ff= ++f[o],rr= r[o];
	for (i= 1;i<=4;i++)
		for (j= 1;j<=4;j++){
			xx= com(i,j);
			if (l[o][ff].c & (1<<xx)){
				yy= com(i,j+1);
				if (!(l[o][ff].c & (1<<yy))&& 4-j){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].c;
					sum^= (1<<xx);sum^= (1<<yy);
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
						l[o][rr].c= sum;
					}
				}
				yy= com(i,j-1);
				if (!(l[o][ff].c & (1<<yy))&& j-1){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].c;
					sum^= (1<<xx);sum^= (1<<yy);
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
						l[o][rr].c= sum;
					}
				}
				yy= com(i+1,j);
				if (!(l[o][ff].c & (1<<yy))&& 4-i){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].c;
					sum^= (1<<xx);sum^= (1<<yy);
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
						l[o][rr].c= sum;
					}
				}
				yy= com(i-1,j);
				if (!(l[o][ff].c & (1<<yy))&& i-1){
					l[o][++rr]= l[o][ff];
					l[o][rr].s++;
					sum= l[o][rr].c;
					sum^= (1<<xx);sum^= (1<<yy);
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
						l[o][rr].c= sum;
					}
				}										
			}
		}
	r[o]= rr;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	char ch;
	for (i= 1;i<=4;i++){
		for (j= 1;j<=4;j++){
			scanf("%c",&ch);
			sum= sum*2+ch-'0';
		}
		scanf("%c",&ch);
	}
	scanf("%c",&ch);
	l[0][1].c= sum;
	b[0][sum]= 1;sum= 0;
	for (i= 1;i<=4;i++){
		for (j= 1;j<=4;j++){
			scanf("%c",&ch);
			sum= sum*2+ch-'0';
		}
		scanf("%c",&ch);
	}
	if (sum==l[0][1].c){
		printf("0");
		return 0;
	}
	l[1][1].c= sum;
	b[1][sum]= 1;
	r[0]= r[1]= 1;
	while ((f[0]<r[0] || f[1]<r[1]) && !bl){
		if (r[0]<=r[1] && (f[0]<r[0])){
			expand(0);zz= 0;
		}
		else {
			expand(1);
			zz= 1;
		}
	}
	return 0;
}
