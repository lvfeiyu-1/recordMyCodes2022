#include<iostream>
#include<string.h>
using namespace std;

static int A[10000][100];
static int B[10000][100];
static int C[10000][100];
static int D[10000][100];
static int resultMatrix[10000][100];
static int columnSum[100];
static int cntvisited[100];
static int base_time[100];
static int line;
static int column;
static int tmpSum, SumD=9999999;

void baseCal() {
	/*
	 * 更新 C 和 D 矩阵
	 * 更新最小值 SumD 同时记录当前最小值矩阵
	 * 备注：当tmpSum==SumD时，此时的 B 矩阵是另一组最优解，在此就不做记录处理了 
	 */
	tmpSum = 0;
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < column; ++j) {
			C[i][j] = A[i][j] + B[i][j];
			D[i][j] = C[i][j] - base_time[j];
			if (D[i][j] < 0)
				D[i][j] = -D[i][j];
			tmpSum += D[i][j];
		}
	}
	if (tmpSum < SumD) {
		SumD = tmpSum;
		for (int i = 0; i <= line; ++i) {
			for (int j = 0; j <= column; ++j) {
				resultMatrix[i][j] = B[i][j];
			}
		}
	}
}

/*
 * 枚举 B 矩阵, 下面的函数是没有处理“单行只有一列为1，其余为0”这个条件
 * 如果填完B矩阵，则调用 baseCal() 函数
 * 如果某一列填完，则填下一列
 * 如果某一列中“下面的位置”多于 columnSum[xx] 中的值，则将当前位置置0，再填该列的下一行
 * 如果 columnSum[xx] 还没减到 0 说明某一列还没有填完1，则将当前位置置1，再填该列的下一行，同时做好回溯处理
 */
void enumeration(int nowline,int nowcolumn) {
	if (nowcolumn == column) {
		//baseCal();
		for (int i = 0; i < line; ++i) {
			for (int j = 0; j < column; ++j) {
				cout << B[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	if (nowline == line) {
		if (columnSum[nowcolumn] != 0)
			return;
		enumeration(0, nowcolumn + 1);
		return;
	}

	if (columnSum[nowcolumn] < line - nowline) {
		B[nowline][nowcolumn] = 0;
		enumeration(nowline + 1, nowcolumn);
	}
	if (columnSum[nowcolumn]) {
		columnSum[nowcolumn]--;
		B[nowline][nowcolumn] = 1;
		enumeration(nowline + 1, nowcolumn);
		columnSum[nowcolumn]++;
	}
}

/*
 * 基于上面 enumeration() 函数的基础多次尝试处理，最终得到如下函数满足“单行只有一列为1，其余为0”这个条件
 */
void dfs(int nowline, int nowcolumn) {
	if (nowcolumn == column) {
		memset(cntvisited, 0, sizeof(cntvisited) / sizeof(int));
		for (int i = 0; i < line; ++i) {
			for (int j = 0; j < column; ++j) {
				if (B[i][j])
					cntvisited[i]++;
				if (cntvisited[i] > 1)
					return;
			}
		}
		baseCal();
		return;
	}
	if (nowline == line) {
		if (columnSum[nowcolumn] != 0)
			return;
		dfs(0, nowcolumn + 1);
		return;
	}

	if (columnSum[nowcolumn] < line - nowline) {
		B[nowline][nowcolumn] = 0;
		dfs(nowline + 1, nowcolumn);
	}
	if (columnSum[nowcolumn]) {
		columnSum[nowcolumn]--;
		B[nowline][nowcolumn] = 1;
		dfs(nowline + 1, nowcolumn);
		columnSum[nowcolumn]++;
	}
}

int main() {
	/*
	 * 输入行数 line 和列数 column
	 * 手动输入 A 矩阵
	 * 输入矩阵 B 每一列相加所得的总和
	 * 输入基础数据 base_time
	 */
	cin >> line >> column;
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < column; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < column; ++i) {
		cin >> columnSum[i];
	}
	for (int i = 0; i < column; ++i) {
		cin >> base_time[i];
	}

	//enumeration(0, 0);
	dfs(0, 0);

	cout << "结果为如下矩阵：" << endl;
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << resultMatrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
