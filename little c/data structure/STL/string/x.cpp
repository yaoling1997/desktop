#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
string g,s= "CCCCCCCCCC";
char ch= 'C';
int i,n,len;
int main()
{
	freopen("1.out","w",stdout);
	//for (i= 1;i<=1000;i++) g.push_back(49);
	for (i= 1;i<=1000000;i++) g.push_back(48);
	//for (i= 0;i<=100;i++) g.erase(g.end()-1000000);
	//for (i= 0;i<=10000;i++) g.erase(g.begin());
	for (i= 0;i<=10000;i++)
		g.insert(1,s);
	//g.insert(g.begin(),ch);
	//g.erase(g.begin());
	g.erase(g.begin(),g.begin()+2);
	//g.erase(1,100000);
	len= g.size();printf("%d",len);
	for (i= 0;i<len;i++){
		putchar(g[i]);putchar(' ');
		if ((i+1)%10==0) putchar('\n');
	}
	if (!g.empty()) printf("yes!\n");
	printf("%d\n",g.size());
	printf("%d\n",g.length());
	printf("%s",g.c_str());
	g.erase(g.begin()+5);
	g.erase(g.begin(),g.begin()+3);
	g[1]='C';len= g.length();
	printf("%d\n",g.size());
	for (i= 0;i<len;i++)
		printf("%c",g[i]);
    g.clear();
	return 0;
}
