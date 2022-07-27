#include<iostream>
#include<string.h>
using namespace std;

/*
 * 该代码主要用于测试递归枚举 B 矩阵
 * 可以自己输入小规模数据进行验证 
 */ 

static int B[10000][100];
static int columnSum[100];
static int cntvisited[100];
static int line;
static int column;
static int cnt;

void enumeration(int nowline,int nowcolumn) {
	if (nowcolumn == column) {
		//baseCal();
		cnt++;
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
		cnt++;
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
	cin >> line >> column;
	for (int i = 0; i < column; ++i) {
		cin >> columnSum[i];
	}
	cout<<endl;
	//enumeration(0, 0);
	dfs(0,0);
	cout<<cnt<<endl;
	return 0;
}
