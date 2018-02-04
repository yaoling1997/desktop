#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define double long double
using namespace std;
const int oo= 1e6;
char s[5]= {0},s1[5]= {0};
double T,D,H,x,h,e;
int i,j;
void get(char c,double x){
	if (c=='T') T= x;
	else if (c=='D') D= x;
	else H= x;
}
void get_e1(){
	e= 6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
}
void get_h1(){
	h= (0.5555)*(e-10);
}
void get_e2(){
	e= h/0.5555+10;
}
void get_h2(){
	h= H-T;
}
void get_T(){
	T= H-h;
}
void get_D(){
	double x= 1/273.16-log(e/6.11)/5417.753;
	D= 1/x-273.16;
}
void get_H(){
	H= T+h;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for(;;){
		T= D= H= oo;
		scanf("%s",s+1);
		if (s[1]=='E') break;
		else {
			scanf("%Lf",&x);
			get(s[1],x);
			scanf("%s%Lf",s+1, &x);
			get(s[1],x);
			if (T==oo){
				get_e1();
				get_h1();
				get_T();
			}else if (D==oo){
				get_h2();
				get_e2();
				get_D();
			}else{
				get_e1();
				get_h1();
				get_H();
			}
			printf("T %.1Lf D %.1Lf H %.1Lf\n",T, D, H);
		}
	}
	return 0;
}
