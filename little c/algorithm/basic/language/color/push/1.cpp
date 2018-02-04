#include <stdio.h>
#include <stdlib.h>
#define maxn 100
#define r1 "\033[41m  \033[49m"
#define g1 "\033[42m  \033[49m"
#define y1 "\033[43m  \033[49m"
#define b1 "\033[44m  \033[49m"
#define p1 "\033[45m  \033[49m"
#define b2 "\033[46m  \033[49m"
#define w1 "\033[47m  \033[49m"
#define b3 "\033[48m  \033[49m"
#define c1 "\033[49m  \033[49m"
int dir[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
char map[maxn][maxn];
struct node{
  int x,y;
}box[maxn];
int ss[2000];
int x,y,boxcount;
int n,m;
void readfile(){
	FILE *fin= fopen("mouse10.in","r");
	fscanf(fin,"%d%d\n",&n,&m);
	int i,j;
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			fscanf(fin,"%c",&map[i][j]);
		}
		fscanf(fin,"\n");
	}
	fscanf(fin,"%d%d",&x,&y);
	fscanf(fin,"%d",&boxcount);
	for (i=1;i<=boxcount;i++) fscanf(fin,"%d%d",&box[i].x,&box[i].y);
	fscanf(fin,"\n");
}
int regal(int x,int y){
  if (x>=1 && x<=n && y>=1 && y<=m) return 1;
  return 0;
}
int havebox(int x,int y){
  int i;
  for (i=1;i<=boxcount;i++) if (box[i].x==x && box[i].y==y) return i;
  return 0;
}
int push(int x,int y,int k){
	int i,nx,ny;
	i=havebox(x,y);
	if (i==0) return 1;
	nx=x+dir[k][0];
	ny=y+dir[k][1];
	if (!regal(nx,ny)) return 0;
	if (map[nx][ny]=='1') return 0;
	if (havebox(nx,ny)) return 0;
	box[i].x=nx;
	box[i].y=ny;
	return 1;
}
int work(){
	FILE *fout= fopen("mouse10.out","w");
	int step=1000;
	int i,j,nx,ny,k,zz;
	char ch;
	char ma[maxn][maxn];
	for (i=1;i<=step;i++){
		scanf("%c",&ch);
		if (ch=='\n') k= zz;
		else {
			zz= k= ch-'0';
			scanf("%c",&ch);
		}
		ss[i]= k;if (k==5) return 0;
		if (!k){
			fprintf(fout,"%d\n",i-1);
			for (j= 1;j<=i-1;j++)
				fprintf(fout,"%d\n",ss[j]);
			return 1;
		}
		if (k<1 || k>5) {i--;continue;}
		nx=x+dir[k][0];
		ny=y+dir[k][1];
		if (!regal(nx,ny)) {i--;continue;}
		if (map[nx][ny]!='1'){
			x=nx;y=ny;
		}
		else {i--;continue;}
		if (!push(nx,ny,k)) {i--;continue;}
		for (j= 1;j<=n;j++)
			for (k= 1;k<=m;k++)
				ma[j][k]= map[j][k];
		ma[x][y]= '8';
		for (int i=1;i<=boxcount;i++)
			(ma[box[i].x][box[i].y]='4');
		for (int i= 1;i<=n;i++){
			for (int j= 1;j<=m;j++)
				if (ma[i][j]=='1') printf("%s",w1);
				else if (ma[i][j]=='8') printf("%s",g1);
				else if (ma[i][j]=='0') printf("%s",c1);
				else if (ma[i][j]=='X') printf("%s",r1);
				else printf("%s",y1);
			printf("\n");
		}
	}
  return 1;
}
int main(){
 en:readfile();
	int i,j,k;
	char ma[maxn][maxn];
	for (j= 1;j<=n;j++)
			for (k= 1;k<=m;k++)
				ma[j][k]= map[j][k];	
	ma[x][y]= '8';
	for (i=1;i<=boxcount;i++)
		(ma[box[i].x][box[i].y]='4');
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++)
			if (ma[i][j]=='1') printf("%s",w1);
			else if (ma[i][j]=='8') printf("%s",g1);
			else if (ma[i][j]=='0') printf("%s",c1);
			else if (ma[i][j]=='X') printf("%s",r1);
			else printf("%s",y1);
		printf("\n");
	}
	if (!work()) goto en;
  return 0;
}
