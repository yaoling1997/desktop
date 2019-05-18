#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#define pb push_back
using namespace std;
const int maxn= 1e5;
string s;
char t[maxn];
char c;
char getSbm(string s){
	int i,re= 0;
	for (i= 0;i<9;i++)
		re= re+(i+1)*(s[i]-'0');
	re%= 11;
	if (re==10)
		return 'X';
	else 
		return '0'+re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",t);
	s= "";
	s.pb(t[0]);
	s.pb(t[2]);
	s.pb(t[3]);
	s.pb(t[4]);
	s.pb(t[6]);
	s.pb(t[7]);
	s.pb(t[8]);
	s.pb(t[9]);
	s.pb(t[10]);
	s.pb(t[12]);
	c= getSbm(s);
	if (c==t[12])
		printf("Right");
	else {
		t[12]= c;
		printf("%s",t);
	}
	return 0;	
}
