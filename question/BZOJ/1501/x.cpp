#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const double eps= 1e-8,PI= acos(-1);
struct point{
	int x,y;
	bool operator <(const point a)const{return x<a.x||(x==a.x&&y<a.y);}
};
struct node{
	int d,x,y;
};
point a[15][15][10]; 
point C[15][10];
int B[20],S[15],t[15],BB[20];
bool map[12][12];
char Map[12][12];
int i,j,k,len,cnt,cnt1,x,y,bl;
point operator -(point a,point b){a.x-= b.x;a.y-= b.y;return a;}
bool operator !=(point a,point b){return a.x!=b.x||a.y!=b.y;}
int idx(char c){return c-'A';}
point rot(point &a,double r){
	return (point){floor(a.x*cos(r)-a.y*sin(r)+0.5),floor(a.x*sin(r)+a.y*cos(r)+0.5)};
}
void build(int o){
	int i,j,&len= S[o],tt= 4;
	memcpy(C[1],a[o][1],sizeof(C[1]));
	for (i= 2;i<=4;i++)
		for (j= 1;j<=len;j++)
			C[i][j]= rot(C[i-1][j],PI/2);
	for (i= 1;i<=4;i++){
		memcpy(C[++tt],C[i],sizeof(C[i]));
		memcpy(C[++tt],C[i],sizeof(C[i]));		
		for (j= 1;j<=len;j++)
			C[tt-1][j].x*= -1,C[tt][j].y*= -1;
	}
	for (i= 1;i<= tt;i++){
		memset(BB,0,sizeof(BB));
		sort(C[i]+1,C[i]+len+1);
		queue<node> Q;
		Q.push((node){1,0,0});BB[1]= 1;
		while (!Q.empty()){
			node u= Q.front();
			point &p1= C[i][u.d];
			int x= u.x,y= u.y;
			Q.pop();
			for (j= 1;j<=len;j++)
				if (!BB[j]){
					point &p2= C[i][j];
					if (p1.x==p2.x){
						if (p1.y+1==p2.y){
							BB[j]= 1;
							Q.push((node){j,x,y+1});
						}else if (p1.y-1==p2.y){
							BB[j]= 1;
							Q.push((node){j,x,y-1});
						}
					}else if (p1.y==p2.y){
						if (p1.x+1==p2.x){
							BB[j]= 1;
							Q.push((node){j,x+1,y});
						}else if (p1.x-1==p2.x){
							BB[j]= 1;
							Q.push((node){j,x-1,y});
						}
					}
				}
			p1.x= x;p1.y= y;
		}
	}
	memset(BB,0,sizeof(BB));
	for (i= tt;i>=2;i--)
		for (j= i-1;j>=1;j--){
			int bl= 1;
			for (k= 1;k<=len;k++)
				if (C[i][k]!=C[j][k]){
					bl= 0;
					break;
				}
			if (bl){
				BB[i]= 1;
				break;
			}
		}
	memcpy(a[o][1],C[1],sizeof(C[1]));
	for (i= 2;i<=tt;i++)
		if (!BB[i])
			memcpy(a[o][++t[o]],C[i],sizeof(C[i]));	
}
void prepare(){
	int i;
	for (i= 0;i<=11;i++) t[i]= 1;
	//A 0
	a[0][1][1].x= 0;a[0][1][1].y= 0;
	a[0][1][2].x= 0;a[0][1][2].y= 1;
	a[0][1][3].x= 1;a[0][1][3].y= 0;	
	build(0);
	//B 1
	a[1][1][1].x= 0;a[1][1][1].y= 0;
	a[1][1][2].x= 0;a[1][1][2].y= 1;
	a[1][1][3].x= 0;a[1][1][3].y= 2;
	a[1][1][4].x= 0;a[1][1][4].y= 3;	
	build(1);
	//C 2
	a[2][1][1].x= 0;a[2][1][1].y= 0;
	a[2][1][2].x= 1;a[2][1][2].y= 0;
	a[2][1][3].x= 0;a[2][1][3].y= 1;
	a[2][1][4].x= 0;a[2][1][4].y= 2;	
	build(2);	
	//D 3
	a[3][1][1].x= 0;a[3][1][1].y= 0;
	a[3][1][2].x= 0;a[3][1][2].y= 1;
	a[3][1][3].x= 1;a[3][1][3].y= 0;
	a[3][1][4].x= 1;a[3][1][4].y= 1;	
	build(3);		
	//E 4
	a[4][1][1].x= 0;a[4][1][1].y= 0;
	a[4][1][2].x= 1;a[4][1][2].y= 0;
	a[4][1][3].x= 2;a[4][1][3].y= 0;
	a[4][1][4].x= 2;a[4][1][4].y= 1;
	a[4][1][5].x= 2;a[4][1][5].y= 2;	
	build(4);	
	//F 5
	a[5][1][1].x= 0;a[5][1][1].y= 0;
	a[5][1][2].x= 0;a[5][1][2].y= 1;
	a[5][1][3].x= 1;a[5][1][3].y= 1;
	a[5][1][4].x= 0;a[5][1][4].y= 2;
	a[5][1][5].x= 0;a[5][1][5].y= 3;	
	build(5);		
	//G 6
	a[6][1][1].x= 0;a[6][1][1].y= 0;
	a[6][1][2].x= 1;a[6][1][2].y= 0;
	a[6][1][3].x= 0;a[6][1][3].y= 1;
	a[6][1][4].x= 0;a[6][1][4].y= 2;
	a[6][1][5].x= 1;a[6][1][5].y= 2;	
	build(6);		
	//H 7
	a[7][1][1].x= 0;a[7][1][1].y= 0;
	a[7][1][2].x= 0;a[7][1][2].y= 1;
	a[7][1][3].x= 0;a[7][1][3].y= 2;
	a[7][1][4].x= 1;a[7][1][4].y= 0;
	a[7][1][5].x= 1;a[7][1][5].y= 1;	
	build(7);	   
	//I 8
	a[8][1][1].x= 0;a[8][1][1].y= 0;
	a[8][1][2].x= 0;a[8][1][2].y= 1;
	a[8][1][3].x= 0;a[8][1][3].y= 2;
	a[8][1][4].x= 1;a[8][1][4].y= 2;
	a[8][1][5].x= 1;a[8][1][5].y= 3;	
	build(8);		
	//J 9
	a[9][1][1].x= 0;a[9][1][1].y= 0;
	a[9][1][2].x= 1;a[9][1][2].y= -1;
	a[9][1][3].x= 1;a[9][1][3].y= 0;
	a[9][1][4].x= 1;a[9][1][4].y= 1;
	a[9][1][5].x= 2;a[9][1][5].y= 0;	
	build(9);		
	//K 10
	a[10][1][1].x= 0;a[10][1][1].y= 0;
	a[10][1][2].x= 1;a[10][1][2].y= 0;
	a[10][1][3].x= 1;a[10][1][3].y= 1;
	a[10][1][4].x= 2;a[10][1][4].y= 1;
	a[10][1][5].x= 2;a[10][1][5].y= 2;	
	build(10);		
	//L 11
	a[11][1][1].x= 0;a[11][1][1].y= 0;
	a[11][1][2].x= 1;a[11][1][2].y= 0;
	a[11][1][3].x= 0;a[11][1][3].y= 1;
	a[11][1][4].x= 0;a[11][1][4].y= 2;
	a[11][1][5].x= 0;a[11][1][5].y= 3;	
	build(11);		
}
bool out(int x,int y,point p){
	x+= p.x-1;y+= p.y-1;
	if (y-x>0||x<0||y<0||x>9) return 1;
	return 0;
}
bool right(int o,int q,int x,int y){
	int i;
	for (i= 1;i<=S[o];i++){
		point p= a[o][q][i];
		if (out(x,y,p)||Map[x+p.x][y+p.y]!='.') return 0;
	}return 1;
}
void put(int o,int q,int x,int y){
	int i;
	for (i= 1;i<=S[o];i++){
		point p= a[o][q][i];
		Map[x+p.x][y+p.y]= o+'A';
	}
}
void clear(int o,int q,int x,int y){
	int i;
	for (i= 1;i<=S[o];i++){
		point p= a[o][q][i];
		Map[x+p.x][y+p.y]= '.';
	}
}
void dfs1(int x,int y){
	for (;;){
		while (y>0&&Map[x][y]!='.') y--;
		if (y==0&&x) y= --x;
		else break;
	}if (x==0){
		bl= 1;
		return;
	}int i,j;
	for (i= 0;i<=11;i++)
		if (!B[i]){
			for (j= 1;j<=t[i];j++)
				if (right(i,j,x,y)){
					put(i,j,x,y);
					B[i]= 1;
					dfs1(x,y-1);
					if (bl) return;
					B[i]= 0;
					clear(i,j,x,y);
				}
		}
}
void dfs(int x,int y){
	for (;;){
		while (y<=x&&Map[x][y]!='.') y++;
		if (y==x+1&&x<10) x++,y= 1;
		else break;
	}if (x==10&&y==x+1){
		bl= 1;
		return;
	}int i,j;
	for (i= 0;i<=11;i++)
		if (!B[i]){
			for (j= 1;j<=t[i];j++)
				if (right(i,j,x,y)){
					put(i,j,x,y);
					B[i]= 1;
					dfs(x,y-1);
					if (bl) return;
					B[i]= 0;
					clear(i,j,x,y);
				}
		}	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	S[0]= 3;
	for (i= 1;i<=3;i++) S[i]= 4;
	for (i= 4;i<=11;i++) S[i]= 5;
	prepare();
	for (i= 1;i<=10;i++){
		scanf("%s",Map[i]+1);
		len= strlen(Map[i]+1);
		for (j= 1;j<=len;j++)
			if (Map[i][j]!='.') B[idx(Map[i][j])]= 1,map[i][j]= 1;
	}x= 1;
	for (i= 6;i<=10;i++){
		for (j= i;j>=i-x+1;j--) cnt+= map[i][j];
		cnt1+= map[i][i-x];
	}
	for (i= 0;i<=11;i++)
		for (j= 1;j<=t[i];j++)
			for (k= 1;k<=S[i];k++)
				a[i][j][k]= a[i][j][k]-a[i][j][S[i]];
	dfs1(10,10);		
	if (!bl) printf("No solution\n");
	else for (i= 1;i<=10;i++){
			 for (j= 1;j<=i;j++)
				 printf("%c",Map[i][j]);
			 printf("\n");
		}
	return 0;
}

