#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 200000,oo= 1e8;
int left[256],right[256],stack[maxn],st[maxn];
char s[maxn];
int n,i,j,top,len,bl;
bool num(char c){
	if (c>='0'&&c<='9') return 1;
	return 0;
}
void count(int x,char c){
	if (c=='+') stack[top]+= x;
	else if (c=='-') stack[top]-= x;
	else if (c=='*') stack[top]*= x;
	else stack[top]/= x;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	left['+']= left['-']= 2;left['*']= left['/']= 4;
	left['(']= 0;left[')']= 6;
	right['+']= right['-']= 1;right['*']= right['/']= 3;
	right['(']= 6;right[')']= 0;
	left['!']= right['!']= -1;
	scanf("%s",s+1);
	stack[top= 1]= '!';
	int len1= strlen(s+1),re= 0;s[++len1]= '!';
	for (i= 1;i<=len1;i++)
		if (num(s[i])) {bl= 1;re= re*10+s[i]-'0';}
		else {
			if (bl){bl= 0;st[++len]= -re;re= 0;}
			while (left[stack[top]]>right[s[i]])
				st[++len]= stack[top--];
			if (left[stack[top]]==right[s[i]]){top--;continue;}
			stack[++top]= s[i];
		}
	top= 0;
	for (i= 1;i<=len;i++)
		if (st[i]<=0) stack[++top]= -st[i];
		else count(stack[top--],st[i]);
	printf("%d\n",stack[top]);
	return 0;
}
