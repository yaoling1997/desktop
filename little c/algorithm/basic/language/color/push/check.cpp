#include <stdio.h>
#include <stdlib.h>
#define maxn 100
int dir[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
char map[maxn][maxn];
struct node{
  int x,y;
}box[maxn];
int x,y,boxcount;
int n,m;
void readfile(char *standin){
  freopen(standin,"r",stdin);
  scanf("%d%d\n",&n,&m);
  int i,j;
  for (i=1;i<=n;i++){
    for (j=1;j<=m;j++){
      scanf("%c",&map[i][j]);
    }
    scanf("\n");
  }
  scanf("%d%d",&x,&y);
  scanf("%d",&boxcount);
  for (i=1;i<=boxcount;i++) scanf("%d%d",&box[i].x,&box[i].y);
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
int work(char *player,char *result){
  int step=0;
  freopen(player,"r",stdin);
  freopen(result,"w",stdout);
  scanf("%d",&step);
  if (step>1000 || step<0) return 0;
  int i,nx,ny,k;
  for (i=1;i<=step;i++){
    scanf("%d",&k);
    if (k<1 || k>4) return 0;
    nx=x+dir[k][0];
    ny=y+dir[k][1];
    if (!regal(nx,ny)) return 0;
    if (map[nx][ny]!='1'){
      x=nx;y=ny;
    }
    else return 0;
    if (!push(nx,ny,k)) return 0;
  }
  for (i=1;i<=boxcount;i++){
    if (map[box[i].x][box[i].y]!='X') return 0;
  }
  return 1;
}
int main(int cn,char **p){
  readfile(p[1]);
  if (work(p[2],p[4])) printf("1.0\n");
  else printf("0.0\n");
  printf("%d %d",x,y);
  return 0;
}
