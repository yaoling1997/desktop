#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
#include<set>
using namespace std;
const int firstNum = (9 + 9) % 9 + 1;//1
const int matrixLen = 9;//�����͸߳���
bool stringEqual(char *a, char *b)
{
	if (strlen(a) != strlen(b))
		return false;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
		if (a[i] != b[i])
			return false;
	return true;
}
int stringToNum(char *s)
{
	//-1 invalid
	//1~1000000
	const int MaxNum = 1000000;
	int re = 0, len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i]<'0' || s[i]>'9')
			return -1;
		re = re * 10 + s[i] - '0';
		if (re > MaxNum)
			return -1;
	}
	if (re < 1)
		return -1;
	return re;
}
int outputNum = 0;
void output(int matrix[matrixLen][matrixLen]) {
	for (int i = 0; i < matrixLen; i++)
		for (int j = 0; j < matrixLen; j++) {
			putchar(matrix[i][j] + '0');
		}
	printf("\n");
}
typedef pair<int, int> Node;
struct SolveS {
	int matrix[matrixLen][matrixLen];
	set<int> S[matrixLen][matrixLen];
	int rowVis[matrixLen][matrixLen + 1];
	int colVis[matrixLen][matrixLen + 1];
	int littleMatrixVis[3][3][matrixLen + 1];
	void init() {
		for (int i = 0; i < matrixLen; i++)
			for (int j = 0; j < matrixLen; j++)
				S[i][j].clear();
		memset(rowVis, 0, sizeof(rowVis));
		memset(colVis, 0, sizeof(colVis));
		memset(littleMatrixVis, 0, sizeof(littleMatrixVis));
	}
	void initSetOfThisEmptyPos(int x, int y) {
		for (int i = 1; i <= matrixLen; i++) {
			if (rowVis[x][i] || colVis[y][i] || littleMatrixVis[x / 3][y / 3][i])
				continue;
			S[x][y].insert(i);
		}
	}
	int removeItem(int x, int y, int xx, int yy) {
		//use (x,y) to update (xx,yy)'s set
		//1 remove success,other fail
		int v = matrix[x][y];
		if (x == xx || y == yy || (x / 3 == xx / 3 && y / 3 == yy / 3))
			if (S[xx][yy].count(v) != 0) {
				S[xx][yy].erase(v);
				return 1;
			}
		return 0;
	}
	bool dfsSolve(vector<Node> emptyPos) {
		if (emptyPos.size() == 0) {
			output(matrix);
			return true;
		}
		Node c = emptyPos[0];//choice
		int cPos = 0;
		for (int i = 1; i < (int)emptyPos.size(); i++)
			if (S[c.first][c.second].size() > S[emptyPos[i].first][emptyPos[i].second].size()) {
				c = emptyPos[i];
				cPos = i;
			}
		emptyPos.erase(emptyPos.begin() + cPos, emptyPos.begin() + cPos + 1);
		for (set<int>::iterator it = S[c.first][c.second].begin(); it != S[c.first][c.second].end(); it++) {
			int x = *it;
			matrix[c.first][c.second] = x;
			vector<int> isRemoved;
			for (int i = 0; i < (int)emptyPos.size(); i++) {
				int re = removeItem(c.first, c.second, emptyPos[i].first, emptyPos[i].second);
				isRemoved.push_back(re);
			}
			if (dfsSolve(emptyPos))
				return true;
			for (int i = 0; i < (int)emptyPos.size(); i++)
				if (isRemoved[i] == 1)
					S[emptyPos[i].first][emptyPos[i].second].insert(x);
			matrix[c.first][c.second] = 0;
		}
		return false;
	}
	void solve() {
		int x;
		while (scanf("%d", &x) > 0) {//get first num in matrix
			vector<Node> emptyPos;
			init();
			for (int i = 0; i < matrixLen; i++)
				for (int j = 0; j < matrixLen; j++) {
					if (i != 0 || j != 0)
						//not first num in matrix
						scanf("%d", &x);
					matrix[i][j] = x;
					if (x != 0) {
						rowVis[i][x] = 1;
						colVis[j][x] = 1;
						littleMatrixVis[i / 3][j / 3][x] = 1;
					}
				}
			for (int i = 0; i < matrixLen; i++)
				for (int j = 0; j < matrixLen; j++)
					if (matrix[i][j] == 0) {
						emptyPos.push_back(make_pair(i, j));
						initSetOfThisEmptyPos(i, j);
					}
			if (!dfsSolve(emptyPos)) {
				printf("No solution!\n");
			}
		}
	}
}solveS;

//�д������,(r,c,v)��ʾr��c�з�v
//�д�����Ҫ�������������һ����������
//slot(a,b),a��b��Ҫ����
//row(a,b),a��ȱb
//col(a,b),a��ȱb
//sub(a,b),��a��С����ȱb
//һ��9*9*9+1=729+1��(��������ڵ���ռ��)
//һ��9*9*4=324��(������ͷ�ڵ�)
//�ܹ�������9*9*9*4+324+1=3241���ڵ�
const int maxn = 1000;
const int maxnode = 5000;
const int maxr = 1000;
struct DLX {
	int n, sz;//�������ڵ�����
	int S[maxn];//���нڵ���(����������ڵ�)
	int row[maxnode], col[maxnode];//���ڵ����б��
	int L[maxnode], R[maxnode], U[maxnode], D[maxnode];//ʮ������
	int ansd, ans[maxr];//��
	void init(int n) {
		this->n = n;
		//����ڵ�,0��Ϊ����ͷ
		for (int i = 0; i <= n; i++) {
			U[i] = i;
			D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[n] = 0; L[0] = n;
		sz = n + 1;
		memset(S, 0, sizeof(S));
	}
	void addRow(int r, vector<int> columns) {
		//r �к�,columns�����һ�е���Щ��Ϊ1
		int first = sz;//sz ��ǰ�½��ڵ���
		for (int i = 0; i < (int)columns.size(); i++) {
			int c = columns[i];
			L[sz] = sz - 1;
			R[sz] = sz + 1;
			D[sz] = c;
			U[sz] = U[c];
			D[U[c]] = sz;
			U[c] = sz;
			row[sz] = r;
			col[sz] = c;
			S[c]++;
			sz++;
		}
		R[sz - 1] = first;
		L[first] = sz - 1;
	}

	//˳������A,������s�������Ԫ��
#define FOR(i,A,s) for(int i= A[s];i!=s;i=A[i])
	void remove(int c) {
		//�Ƴ����Ϊc���ڵ���
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		FOR(i, D, c)
			FOR(j, R, i) {
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			--S[col[j]];
		}
	}
	void restore(int c) {
		//�ָ����c���ڵ���
		FOR(i, U, c)
			FOR(j, L, i) {
			++S[col[j]];
			U[D[j]] = j;
			D[U[j]] = j;
		}
		L[R[c]] = c;
		R[L[c]] = c;
	}
	//dΪ�ݹ����
	bool dfs(int d) {
		if (R[0] == 0) {
			//��ʾ�е�����ڵ㶼ɾ����
			ansd = d;//�ҵ���
			return true;//��¼��ĳ���
		}
		//��S��С����c
		int c = R[0];//��һ��δɾ����
		FOR(i, R, 0)
			if (S[i] < S[c])
				c = i;
		remove(c);//ɾ����c��
		FOR(i, D, c) {//�ýڵ�i�����и��ǵ�c��
			ans[d] = row[i];
			FOR(j, R, i)
				remove(col[j]);//ɾ���ڵ�i�������ܸ��ǵ�����������
			if (dfs(d + 1))
				return true;
			FOR(j, L, i)
				restore(col[j]);//�ָ��ڵ�i�������ܸ��ǵ�����������
		}
		restore(c);//�ָ���c��
		return false;
	}
	bool solve(vector<int> &v) {
		v.clear();
		if (!dfs(0))
			return false;
		for (int i = 0; i < ansd; i++)
			v.push_back(ans[i]);
		return true;
	}
};
const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;
struct SolveS_DLX {
	int matrix[matrixLen][matrixLen];
	DLX solver;
	int encode(int a, int b, int c) {
		return (a * matrixLen + b) * matrixLen + c + 1;
	}
	void decode(int code, int &a, int &b, int &c) {
		code--;
		c = code%matrixLen;
		code /= matrixLen;
		b = code %matrixLen;
		code /= matrixLen;
		a = code;
	}
	void solve() {
		char s[1000];
		while (scanf("%s", s) > 0) {//get first num in matrix
			if (strlen(s)<10){
				break;
			}
			int tot= 0;
			for (int i = 0; i < matrixLen; i++)
				for (int j = 0; j < matrixLen; j++) {
					if (s[tot]=='.')
						matrix[i][j]= 0;
					else
						matrix[i][j]= s[tot]-'0';
					tot++;
				}
			solver.init(matrixLen*matrixLen * 4);
			for (int r = 0; r < matrixLen; r++)
				for (int c = 0; c < matrixLen; c++)
					for (int v = 0; v < matrixLen; v++) {
						if (matrix[r][c] == 0 || matrix[r][c] == v + 1) {
							vector<int> columns;
							//�кŴ�1��ʼ
							columns.push_back(encode(SLOT, r, c));
							columns.push_back(encode(ROW, r, v));
							columns.push_back(encode(COL, c, v));
							columns.push_back(encode(SUB, r / 3 * 3 + c / 3, v));
							solver.addRow(encode(r, c, v), columns);
						}
					}
			vector<int> ans;
			if (solver.solve(ans)) {
				for (int i = 0; i < (int)ans.size(); i++) {
					int r, c, v;
					decode(ans[i], r, c, v);
					matrix[r][c] = v + 1;
				}
				output(matrix);
			}
			else {
				printf("No solution!\n");
			}
		}
	}
}solveS_DLX;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	double beginTime = clock();
	solveS_DLX.solve();
	double endTime = clock();
	//	printf("time cost:%.3f", (endTime - beginTime) / CLOCKS_PER_SEC);
	return 0;
}
