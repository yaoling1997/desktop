#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;


struct TPair
{
    int x1,y1,x2,y2;
};

const int maxm=10;
const int maxn=1000;
const int maxk=1000;

TPair Pair[maxk];
int origin_dir_x[maxm],origin_dir_y[maxn],dir_x[maxm],dir_y[maxn];
int change_x[maxm],change_y[maxn];
int m,n,k,your_ans,std_ans,len,i;
char ss[maxn];
bool std_impossible,your_impossible;

int MIN(int a,int b) { return a<b?a:b; };

int MAX(int a,int b) { return a>b?a:b; };

bool Exist_x(int x1,int x2,int dy)
{
    int x;
    for (x=x1; x<=x2; x++)
        if (dir_x[x]*dy>=0) return true;
    return false;
}

bool Exist_y(int y1,int y2,int dx)
{
    int y;
    for (y=y1; y<=y2; y++)
        if (dir_y[y]*dx>=0) return true;
    return false;
}

int main(int argc,char *argv[])
{
	FILE *fin= fopen(argv[1],"r");
	FILE *fout= fopen(argv[2],"r");
	FILE *ans= fopen(argv[3],"r");
	FILE *source= fopen(argv[5],"w");
	//FILE *msg= fopen(argv[6],"w");
    int i,x,y;
    char ch;
	fscanf(fin,"%d %d",&m, &n);
    for (x=0; x<m; x++)
    {
		do fscanf(fin,"%c",&ch);
		while (ch=='\n'||ch=='\r');
        if (ch=='E') origin_dir_x[x]=1; else origin_dir_x[x]=-1;
    }
    for (y=0; y<n; y++)
    {
		do fscanf(fin,"%c",&ch);
		while (ch=='\n'||ch=='\r');
        if (ch=='S') origin_dir_y[y]=1; else origin_dir_y[y]=-1;
    }
    for (x=0; x<m; x++) fscanf(fin,"%d",&change_x[x]);
    for (y=0; y<n; y++) fscanf(fin,"%d",&change_y[y]);
	fscanf(fin,"%d",&k);
    for (i=0; i<k; i++)
    {
		fscanf(fin,"%d %d %d %d",&Pair[i].x1, &Pair[i].y1, &Pair[i].x2, &Pair[i].y2);
        Pair[i].x1--; Pair[i].y1--; Pair[i].x2--; Pair[i].y2--;
    }
    string st;st.clear();
	fscanf(fout,"%s",ss+1);
	len= strlen(ss+1);
	for (i= 1;i<=len;i++) st.push_back(ss[i]);
    if (st=="impossible")
        your_impossible=true;
	else your_impossible=false;
	fscanf(fout,"%d",&your_ans);
    for (x=0; x<m; x++){
		do fscanf(fout,"%c",&ch);
		while (ch=='\n'||ch=='\r');
        if (ch=='E') dir_x[x]=1; else dir_x[x]=-1;
    }
    for (y=0; y<n; y++){
		do fscanf(fout,"%c",&ch);
		while (ch=='\n'||ch=='\r');
        if (ch=='S') dir_y[y]=1; else dir_y[y]=-1;
    }
	st.clear();
	fscanf(ans,"%s",ss+1);
	len= strlen(ss+1);
	for (i= 1;i<=len;i++) st.push_back(ss[i]);
    if (st=="impossible")
        std_impossible=true;
	else std_impossible=false;
	fscanf(ans,"%d",&std_ans);
    int x1,y1,x2,y2,tot;
    if (your_impossible!=std_impossible)
    {
		fprintf(source,"0");
        return 0;
    }
    if (std_impossible)
    {
		fprintf(source,"10");
        return 0;
    }
    for (i=0; i<k; i++)
    {
        x1=Pair[i].x1; y1=Pair[i].y1; x2=Pair[i].x2; y2=Pair[i].y2;
        if ((y2-y1)*dir_x[x1]>=0 && (x2-x1)*dir_y[y2]>=0) continue;
        if ((x2-x1)*dir_y[y1]>=0 && (y2-y1)*dir_x[x2]>=0) continue;
        if ((y2-y1)*dir_x[x1]>=0 && (y2-y1)*dir_x[x2]>=0 && Exist_y(MIN(y1,y2)+1,MAX(y1,y2)-1,x2-x1)) continue;
        if ((x2-x1)*dir_y[y1]>=0 && (x2-x1)*dir_y[y2]>=0 && Exist_x(MIN(x1,x2)+1,MAX(x1,x2)-1,y2-y1)) continue;
		fprintf(source,"0");
        return 0; 
    }
    tot=0;
    for (x=0; x<m; x++)
    {
        if (origin_dir_x[x]!=dir_x[x]) tot+=change_x[x];
    }
    for (y=0; y<n; y++)
    {
        if (origin_dir_y[y]!=dir_y[y]) tot+=change_y[y];
    }
    if (tot!=your_ans)
		fprintf(source,"0");
	else if (your_ans!=std_ans)
		fprintf(source,"4");
	else fprintf(source,"10");
    return 0;
}
