#include<cstdio>
#define gc getchar
using namespace std;
int T,S,bl,n,x;
void gi(int &re){
	char c= gc();re= 0;
	while (c<'0'||c>'9') c= gc();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= gc();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	gi(T);
	while (T--){
		gi(n);
		bl= S= 0;
		while (n--){
			gi(x);
			S^= x;
			if (x>1) bl= 1;
		}
		if ((S==0&&!bl)||(S!=0&&bl)) printf("John\n");
		else printf("Brother\n");
	}return 0;
}
