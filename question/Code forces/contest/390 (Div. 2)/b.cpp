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
const int maxn= 10;
char s[maxn][maxn];
int n= 4,ONum,XNum;
bool out(int x,int y){
	return !(1<=x&&x<=4&&1<=y&&y<=4);
}
bool okHorizontal(int x,int y,char c){
	for (int k= 1;k<=3;k++){
		if (out(x,y))
			return false;
		if (s[x][y]!=c)
			return false;
		y++;
	}
	return true;
}
bool okVertical(int x,int y,char c){
	for (int k= 1;k<=3;k++){
		if (out(x,y))
			return false;
		if (s[x][y]!=c)
			return false;
		x++;
	}
	return true;
}
bool okDiagonal1(int x,int y,char c){
	for (int k= 1;k<=3;k++){
		if (out(x,y))
			return false;
		if (s[x][y]!=c)
			return false;
		x++;
		y++;
	}
	return true;
}
bool okDiagonal2(int x,int y,char c){
	for (int k= 1;k<=3;k++){
		if (out(x,y))
			return false;
		if (s[x][y]!=c)
			return false;
		x++;
		y--;
	}
	return true;
}
bool check(char c){
	for (int i= 1;i<=4;i++)
		for (int j= 1;j<=4;j++){			
			if (okHorizontal(i,j,c))
				return true;
			if (okVertical(i,j,c))
				return true;
			if (okDiagonal1(i,j,c))
				return true;
			if (okDiagonal2(i,j,c))
				return true;
		}
	return false;
}
bool ok(char c){
		for (int i= 1;i<=4;i++)
			for (int j= 1;j<=4;j++)
				if (s[i][j]=='.'){
					s[i][j]=c;
					if (check(c))
						return true;
					s[i][j]= '.';
				}
		return false;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	for (int i= 1;i<=4;i++){
		scanf("%s",s[i]+1);
		for (int j= 1;j<=4;j++)
			if (s[i][j]=='o')
				ONum++;
			else if (s[i][j]=='x')
				XNum++;
	}
	bool bl= false;
	if (ONum==XNum){
		//x's turn
		bl= ok('x');
	}else {
		//o's turn
		bl= ok('o');
	}
	if (bl)
		printf("YES");
	else printf("NO");
	return 0;
}
